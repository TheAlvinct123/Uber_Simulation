#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"

/**
 * @brief IEntityFactory class used to produce IEntities.
 **/
class IEntityFactory {
 public:
  /**
   * @brief IEntityFactory destructor.
   **/
  virtual ~IEntityFactory() {}
  /**
   * @brief Creates IEntity entity.
   *
   * @param entity Entity to be made into a IEntity.
   * @return IEntity pointer for IEntity.
   **/
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
