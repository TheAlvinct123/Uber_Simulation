#ifndef LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the Astar Strategy that the drone will take.
 */
class AstarStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor of AstarStrategy.
   *
   * @param position Entity's position.
   * @param destination Entity's destination.
   * @param graph Graph used to navigate in simulation.
   **/
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor of AstarStrategy.
   *
   **/
  ~AstarStrategy();
  /**
   * @brief Moves Entity using Astar Strategy.
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
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
