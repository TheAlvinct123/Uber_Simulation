#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief DroneFactory class used to produce Drones.
 **/
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief DroneFactory destructor.
   **/
  virtual ~DroneFactory() {}
  /**
   * @brief Creates Drone entity.
   *
   * @param entity Entity to be made into a Drone.
   * @return IEntity pointer for Drone.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
