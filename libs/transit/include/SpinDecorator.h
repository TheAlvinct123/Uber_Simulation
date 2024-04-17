#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief SpinDecorator class used to to give spin behavior to IEntities.
 **/
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief SpinDecorator Constructor.
   * @param strategy_ Movement strategy.
   **/
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Returns whether spin is complete.
   * @return Returns whether spin is complete (true=complete, false=incomplete)
   **/
  bool IsCompleted();
  /**
   * @brief Moves IEntity.
   * @param entity IEntity to be moved.
   * @param dt Rate of change.
   **/
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
