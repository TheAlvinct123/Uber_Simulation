#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;
/**
 * @brief This class is the base class from which all other strategy classes
 * inherit from.
 */
class IStrategy {
 public:
  /**
   * @brief Moves Entity by dt.
   *
   * @param entity Entity that needs to be moved.
   * @param dt Rate of change.
   **/
  virtual void Move(IEntity* entity, double dt) = 0;
  /**
   * @brief Determines if trip is complete.
   *
   * @return Whether trip is complete (true) or not (false).
   **/
  virtual bool IsCompleted() = 0;
  /**
   * @brief Get the total length of the strategy's path
   *
   * @return double length of path
   */
  virtual double GetLength() { return routeLength; }

 protected:
  // IGraph object to be used in the simulation.
  const IGraph* graph;
  double routeLength;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
