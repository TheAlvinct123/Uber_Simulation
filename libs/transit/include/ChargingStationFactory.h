#ifndef LIBS_TRANSIT_INCLUDE_CHARGINGSTATIONFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CHARGINGSTATIONFACTORY_H_

#include <vector>

#include "ChargingStation.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief  ChargingStationFactory class used to produce Charging Stations in
 *simulation.
 **/
class ChargingStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for ChargingStationFactory.
   *
   **/
  virtual ~ChargingStationFactory() {}
  /**
   * @brief Creates ChargingStation entity.
   *
   * @param entity Entity to be made into a ChargingStation.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_CHARGINGSTATIONFACTORY_H_
