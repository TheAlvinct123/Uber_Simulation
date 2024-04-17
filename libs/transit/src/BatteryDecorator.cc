#include "BatteryDecorator.h"

void BatteryDecorator::DecrementBattery(double dt) {
  battery -= (dt * entity->GetSpeed()) / maxDistance;
}

double BatteryDecorator::DistanceUntilRecharge() {
  return (battery * maxDistance);
}

void BatteryDecorator::Recharge(double dt) {
  // charge 3 times faster then discharge
  battery += (3 * dt * entity->GetSpeed()) / maxDistance;

  if (battery >= 1.0) {
    rechargeNeeded = false;
    battery = 1.0;
  }
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler,
                              std::vector<IEntity*> chargers) {
  double minDisToCharger = std::numeric_limits<double>::max();
  for (auto station : chargers) {
    double disToEntity = entity->GetPosition().Distance(station->GetPosition());
    if (disToEntity <= minDisToCharger) {
      minDisToCharger = disToEntity;
    }
  }

  if (rechargeNeeded && (minDisToCharger <= 1.0)) {
    // Drone has indicated battery is low and is near enough
    // to a charging station

    Recharge(dt);
    entity->SetAvailability(true);
    return;  // recharging is all drone can do until it reaches 100%
  } else if (minDisToCharger < 1.0) {
    // drone has not indicated it has to charge, but is still close
    // to a charging station. so it can do other things as well as charge
    Recharge(dt);
  } else if (battery <= 0) {
    // dead battery do nothing
    return;
  } else {
    DecrementBattery(dt);
  }

  bool availablePreUpdate = entity->GetAvailability();

  entity->Update(dt, scheduler, chargers);

  // If entity isn't available now, but was before the update it has taken on a
  // trip.
  if (!(entity->GetAvailability()) && availablePreUpdate) {
    double minDisRobotToCharger = std::numeric_limits<double>::max();
    for (auto station : chargers) {
      double disToEntity =
          entity->GetDestination().Distance(station->GetPosition());
      if (disToEntity <= minDisRobotToCharger) {
        minDisRobotToCharger = disToEntity;
      }
    }

    // If the distance of the trip and returning to a charger is greater than
    // the battery refuse the trip
    if ((entity->GetRouteLength() + minDisRobotToCharger) >=
        this->DistanceUntilRecharge()) {
      entity->ReturnNearestEntity()->SetAvailability(true);

      entity->GetNearestEntity(chargers);
      rechargeNeeded = true;  // Since it rejected a trip it should just
                              // recharge
    }
  }

  if (entity->GetAvailability() && minDisToCharger > 1.0) {
    // if no robots go charge while waiting
    entity->GetNearestEntity(chargers);
    entity->SetAvailability(true);
  }
}
