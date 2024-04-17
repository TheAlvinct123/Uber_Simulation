#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 * @brief CelebrationDecorator class used to to give celebration behavior to
 *IEntities.
 **/
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief CelebrationDecorator Constructor.
   * @param strategy_ Movement strategy.
   **/
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief Moves IEntity.
   * @param entity IEntity to be moved.
   * @param dt Rate of change.
   **/
  void Move(IEntity *entity, double dt);
  /**
   * @brief Returns whether celebration is complete.
   * @return Returns whether celebration is complete (true=complete,
   *false=incomplete)
   **/
  bool IsCompleted();
  /**
   * @brief Get the total length of the substrategy's path
   *
   * @return double length of path
   */
  double GetLength() { return strategy->GetLength(); }

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
