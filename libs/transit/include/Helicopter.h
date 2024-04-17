#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a helicopter in a physical system. Helicpoters move
 *randomly using the beeline strategy.
 **/
class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter constructor.
   * @param obj Object to be turned into Helicopter.
   **/
  Helicopter(JsonObject& obj);
  /**
   * @brief Helicopter destructor.
   **/
  ~Helicopter();
  /**
   * @brief  Returns Helicopter's speed.
   * @return Helicopter's speed.
   **/
  float GetSpeed() const { return speed; }

  // Gets the drone position
  /**
   * @brief  Returns the Helicopter's position.
   * @return Helicopter's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief  Returns the Helicopter's direction.
   * @return Helicopter's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief  Returns the Helicopter's destination.
   * @return Helicopter's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief  Returns the Helicopter's details.
   * @return Returns Helicopter's details via Json Object.
   **/
  JsonObject GetDetails() const { return details; }

  // Updates the helicpoters's position
  /**
   * @brief Updates the Helicopter's position.
   *
   * @param dt Change in speed.
   * @param scheduler Scheduler.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> chargers);
  /**
   * @brief Sets the Helicopter's position.
   *
   * @param pos_ Position to set Helicopter to.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the drone's direction
  /**
   * @brief Sets the Helicopter's direction.
   *
   * @param dir_ Direction to set for Helicopter.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the Helicopter's destination.
   *
   * @param des_ Destination to set for Helicopter.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  /**
   * @brief Removing the copy constructor so Helicopters can't be copied.
   *
   * @param Helicopter Helicopter that was going to be copied.
   **/
  Helicopter(const Helicopter& helicopter) = delete;
  /**
   * @brief Removing the assignment operator so Helicopters can't be copied.
   *
   * @param Helicopter Helicopter that was going to be copied.
   * @return Address for Helicopter.
   **/
  Helicopter& operator=(const Helicopter& helicopter) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  std::string strategyName;
  IStrategy* moveStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
