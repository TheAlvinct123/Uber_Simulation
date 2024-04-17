#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief JumpDecorator class used to to give jump behavior to IEntities.
 **/
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief JumpDecorator Constructor.
   * @param strategy_ Movement strategy.
   **/
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Returns whether jump is complete.
   * @return Returns whether jump is complete (true=complete, false=incomplete)
   **/
  bool IsCompleted();
  /**
   * @brief Moves IEntity.
   * @param entity IEntity to be moved.
   * @param dt Rate of change.
   **/
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
