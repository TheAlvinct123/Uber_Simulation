#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief Robot class used to represent a Robot in the simulation.
 **/

class Robot : public IEntity {
 public:
  /**
   * @brief  Constructor for Robot entity.
   * @param obj JsonObject to be turned into Robot.
   **/
  Robot(JsonObject& obj);
  /**
   * @brief  Destructor for Car entity.
   **/
  ~Robot() override = default;
  /**
   * @brief Gets Robot's position.
   *
   * @return Robot's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets Robot's direction.
   *
   * @return Robot's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets Robot's destination.
   *
   * @return Robot's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets Robot's Availability.
   *
   * @return Robot's Availability.
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets Robot's details.
   *
   * @return Robot's details.
   **/
  JsonObject GetDetails() const override;
  /**
   * @brief Gets Robot's speed.
   *
   * @return Robot's speed.
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets name of Robot's Strategy.
   *
   * @return name of Robot's Strategy.
   **/
  std::string GetStrategyName() { return strategyName; }
  /**
   * @brief Sets Robot's Availability.
   * @param boolean value to set Availability to (true= available, false=
   *unavailable).
   **/
  void SetAvailability(bool choice);
  /**
   * @brief Sets the Robot's position.
   *
   * @param pos_ Position to set for Robot.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the Robot's direction.
   *
   * @param pos_ direction to set for Robot.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the Robot's destination.
   *
   * @param pos_ destination to set for Robot.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets name of Robot's Strategy.
   *
   * @param pos_ Strategy Name to set for Robot.
   **/
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
   * @brief Rotates Robot.
   *
   * @param angle angle to rotate Robot by.
   **/
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_
