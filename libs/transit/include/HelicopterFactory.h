#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief HelicopterFactory class used to produce Helicopters.
 **/
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for HelicopterFactory.
   *
   **/
  virtual ~HelicopterFactory() {}
  /**
   * @brief Creates Helicopter entity.
   *
   * @param entity Entity to be made into a Helicopter.
   * @return IEntity pointer for Helicopter.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
