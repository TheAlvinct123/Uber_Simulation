#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a drone in a physical system. Drones move using euler
 *integration based on a specified velocity and direction.
 *
 **/
class Drone : public IEntity {
 public:
  /**
   * @brief Drone constructor.
   **/
  Drone() {}
  /**
   * @brief Drone constructor given a JsonObject.
   * @param obj JsonObject to be turned into Drone.
   **/
  // Drones are created with a name
  Drone(JsonObject& obj);
  /**
   * @brief Drone destructor.
   **/
  ~Drone();
  /**
   * @brief Gets Drone's speed.
   * @return Returns Drone's speed.
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets Drone's position.
   * @return Returns Drone's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets Drone's direction.
   * @return Returns Drone's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets Drone's destination.
   * @return Returns Drone's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets Drone's details.
   * @return Returns Drone's details.
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets Drone's availability.
   * @return Returns Drone's availability.
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets Drone's nearest entity.
   * @param scheduler Scheduler used for getting nearest entity.
   * @return Returns Drone's nearest entity.
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
   * @brief Gets Drone's route length.
   * @return Returns Drone's route length.
   **/
  float GetRouteLength() const { return routeLength; }

  // Updates the drone's position
  /**
   * @brief Updates the drone's battery.
   * @param dt rate of change.
   * @param scheduler Scheduler used for updating.
   * @param chargers Charging.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> chargers);
  /**
   * @brief Sets the drone's position.
   * @param pos_ Position to set Drone's position to.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the drone's direction.
   * @param dir_ Direction to set Drone's direction to.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the drone's destination.
   * @param des_ Destination to set Drone's destination to.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the drone's availability.
   * @param available_ availability status to give drone.
   **/
  void SetAvailability(bool available_) { available = available_; }
  /**
   * @brief Returns nearest entity.
   * @return nearest entity to drone.
   **/
  IEntity* ReturnNearestEntity() { return nearestEntity; }

  // Rotates a drone
  /**
   * @brief Rotates a drone.
   * @param angle angle to rotate drone by.
   **/
  void Rotate(double angle);
  /**
   * @brief Makes drone jump.
   * @param height height to jump Drone by.
   **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  /**
   * @brief Drone copy constructor.
   **/
  Drone(const Drone& drone) = delete;
  /**
   * @brief Drone assignment operator.
   **/
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  float routeLength;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
