#ifndef LIBS_TRANSIT_INCLUDE_UFO_H_
#define LIBS_TRANSIT_INCLUDE_UFO_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a UFO in a physical system. UFOs move randomly using the
 *beeline strategy.
 **/
class Ufo : public IEntity {
 public:
  // Constructor
  /**
   * @brief Ufo constructor.
   * @param obj Object to be turned into Ufo.
   **/
  Ufo(JsonObject& obj);
  // Destructor
  /**
   * @brief Ufo destructor.
   **/
  ~Ufo();
  /**
   * @brief  Returns Ufo's speed.
   * @return Ufo's speed.
   **/
  float GetSpeed() const { return speed; }

  // Gets the UFO position
  /**
   * @brief  Returns the Ufo's position.
   * @return Ufo's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief  Returns the Ufo's direction.
   * @return Ufo's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief  Returns the Ufo's destination.
   * @return Ufo's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief  Returns the Ufo's details.
   * @return Returns Ufo's details via Json Object.
   **/
  JsonObject GetDetails() const { return details; }

  // Updates the Ufo's position
  /**
   * @brief Updates the Ufo's position.
   *
   * @param dt Change in speed.
   * @param scheduler Scheduler.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> chargers);
  /**
   * @brief Sets the Ufo's position.
   *
   * @param pos_ Position to set Ufo to.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the ufo's direction
  /**
   * @brief Sets the Ufo's direction.
   *
   * @param dir_ Direction to set for Ufo.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the Ufo's destination.
   *
   * @param des_ Destination to set for Ufo.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  /**
   * @brief Removing the copy constructor so Ufos can't be copied.
   *
   * @param Ufo Ufo that was going to be copied.
   **/
  Ufo(const Ufo& ufo) = delete;
  /**
   * @brief Removing the assignment operator so Ufos can't be copied.
   *
   * @param ufo Ufo that was going to be copied.
   * @return Address for Ufo.
   **/
  Ufo& operator=(const Ufo& ufo) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  std::string strategyName;
  IStrategy* moveStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_UFO_H_
