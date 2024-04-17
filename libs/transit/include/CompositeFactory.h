#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"
/**
 * @brief CompositeFactory class used to produce IEntities and add IEntity
 *Factories.
 **/
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates IEntity entity.
   *
   * @param entity Entity to be made into a IEntity.
   * @return IEntity pointer for IEntity.
   **/
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief Adds IEntityFactory to componentFactories.
   *
   * @param factoryEntity IEntityFactory to be added to componentFactories.
   **/
  void AddFactory(IEntityFactory* factoryEntity);
  /**
   * @brief CompositeFactory destructor.
   **/
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
