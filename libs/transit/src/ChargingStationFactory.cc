#include "ChargingStationFactory.h"

IEntity* ChargingStationFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("chargingstation") == 0) {
    std::cout << "ChargingStation Created" << std::endl;
    return new ChargingStation(entity);
  }
  return nullptr;
}
