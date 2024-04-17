#ifndef LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Ufo.h"
/**
 * @brief UfoFactory class used to produce Ufos.
 **/
class UfoFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for UfoFactory.
   *
   **/
  virtual ~UfoFactory() {}
  /**
   * @brief Creates Ufo entity.
   *
   * @param entity Entity to be made into a Ufo.
   * @return IEntity pointer for Ufo.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
