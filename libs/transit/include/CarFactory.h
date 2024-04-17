#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief CarFactory class used to produce Cars.
 **/
class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for CarFactory.
   *
   **/
  virtual ~CarFactory() {}
  /**
   * @brief Creates Car entity.
   *
   * @param entity Entity to be made into a Car.
   * @return IEntity pointer for Car.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
