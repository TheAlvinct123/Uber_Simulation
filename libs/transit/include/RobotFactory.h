#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"
/**
 * @brief RobotFactory class used to produce Robots.
 **/
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates Robot entity.
   *
   * @param entity Entity to be made into a Robot.
   * @return IEntity pointer for Robot.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
