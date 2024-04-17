#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor of BeelineStrategy.
   *
   * @param position Entity's position.
   * @param destination Entity's destination.
   **/
  BeelineStrategy(Vector3 position, Vector3 destination);
  /**
   * @brief Destructor of BeelineStrategy.
   *
   **/
  ~BeelineStrategy();
  /**
   * @brief Moves Entity using Beeline Strategy.
   *
   * @param entity Entity that needs to be moved.
   * @param dt Rate of change.
   **/
  void Move(IEntity* entity, double dt);
  /**
   * @brief Determines if trip is complete.
   *
   * @return Whether trip is complete (true) or not (false).
   **/
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
