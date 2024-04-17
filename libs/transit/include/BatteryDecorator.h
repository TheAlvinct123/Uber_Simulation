#ifndef LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

/**
 * @brief BatteryDecorator class used to to give battery behavior to IEntities.
 **/
class BatteryDecorator : public IEntity {
 public:
  /**
   * @brief BatteryDecorator Constructor.
   * @param entity_ IEntity to be given battery behavior.
   **/
  BatteryDecorator(IEntity *entity_) {
    entity = entity_;
    battery = 1.0;
    maxDistance = 10000;
    rechargeNeeded = false;
  }

  /**
   * @brief Gets the IEntity's battery.
   *
   * @return Battery level.
   **/
  double GetBattery() const { return battery; }
  /**
   * @brief Gets the IEntity's max distance it can travel based on battery
   *level.
   *
   * @return Max distance.
   **/
  int GetMaxDistance() const { return maxDistance; }
  /**
   * @brief Decrements IEntity's battery.
   *
   * @param dt Rate of change.
   **/
  void DecrementBattery(double dt);
  /**
   * @brief Gets the distance IEntity can travel before recharging.
   *
   * @return Distance to travel before recharging.
   **/
  double DistanceUntilRecharge();
  /**
   * @brief Recharges the IEntity's battery.
   **/
  void Recharge(double dt);
  /**
   * @brief Updates IEntity's position.
   *
   * @param dt Change in speed.
   * @param scheduler A list of entities waiting to be picked up.
   * @param chargers A list of charging stations
   **/
  void Update(double dt, std::vector<IEntity *> scheduler,
              std::vector<IEntity *> chargers);
  /**
   * @brief Gets IEntity's Id.
   *
   * @return IEntity's Id.
   **/
  int GetId() const { return entity->GetId(); }
  /**
   * @brief Gets IEntity's position.
   *
   * @return IEntity's position.
   **/
  Vector3 GetPosition() const override { return entity->GetPosition(); }
  /**
   * @brief Gets IEntity's direction.
   *
   * @return IEntity's direction.
   **/
  Vector3 GetDirection() const override { return entity->GetDirection(); }
  /**
   * @brief Gets IEntity's destination.
   *
   * @return IEntity's destination.
   **/
  Vector3 GetDestination() const override { return entity->GetDestination(); }
  /**
   * @brief Gets IEntity's details.
   *
   * @return IEntity's details.
   **/
  JsonObject GetDetails() const override { return entity->GetDetails(); }
  /**
   * @brief Gets IEntity's speed.
   *
   * @return IEntity's speed.
   **/
  float GetSpeed() const override { return entity->GetSpeed(); }
  /**
   * @brief Gets IEntity's Availability.
   *
   * @return IEntity's Availability.
   **/
  bool GetAvailability() const override { return entity->GetAvailability(); }
  /**
   * @brief Gets name of IEntity's Strategy.
   *
   * @return name of IEntity's Strategy.
   **/
  std::string GetStrategyName() override { return entity->GetStrategyName(); }
  /**
   * @brief Sets IEntity's Availability.
   * @param boolean value to set Availability to (true= available, false=
   *unavailable).
   **/
  void SetAvailability(bool choice) override {
    entity->SetAvailability(choice);
  }

  /**
   * @brief Sets the IEntity's position.
   *
   * @param pos_ Position to set for IEntity.
   **/
  void SetPosition(Vector3 pos_) override { entity->SetPosition(pos_); }
  /**
   * @brief Sets the IEntity's direction.
   *
   * @param dir_ direction to set for IEntity.
   **/
  void SetDirection(Vector3 dir_) override { entity->SetDirection(dir_); }
  /**
   * @brief Sets the IEntity's destination.
   *
   * @param des_ destination to set for IEntity.
   **/
  void SetDestination(Vector3 des_) override { entity->SetDestination(des_); }
  /**
   * @brief Sets the IEntity's Strategy name.
   *
   * @param strategyName_  Strategy name to set IEntity's Strategy name to.
   **/
  void SetStrategyName(std::string strategyName_) override {
    entity->SetStrategyName(strategyName_);
  }
  /**
   * @brief Rotates IEntity.
   *
   * @param angle angle to rotate IEntity by.
   **/
  void Rotate(double angle) override { entity->Rotate(angle); }
  /**
   * @brief Makes IEntity jump.
   *
   * @param height height for IEntity to jump by.
   **/
  void Jump(double height) override { entity->Jump(height); }

 protected:
  IEntity *entity;
  double battery;
  int maxDistance;
  bool rechargeNeeded;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_
