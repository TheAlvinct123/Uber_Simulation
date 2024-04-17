#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a car in a physical system. Cars move randomly using the
 *beeline strategy.
 *
 **/
class Car : public IEntity {
 public:
  /**
   * @brief  Constructor for Car entity.
   * @param obj JsonObject to be turned into Car.
   **/
  Car(JsonObject& obj);
  /**
   * @brief  Destructor for Car entity.
   **/
  ~Car();
  /**
   * @brief  Returns Car's speed.
   * @return Car's speed.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief  Returns the Car's position.
   * @return Car's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief  Returns the Car's direction.
   * @return Car's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief  Returns the Car's destination.
   * @return Car's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief  Returns the Car's details.
   * @return Returns Car's details via Json Object.
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Updates the Car's position.
   *
   * @param dt Change in speed.
   * @param scheduler Scheduler.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> chargers);
  /**
   * @brief Sets the Car's position.
   *
   * @param pos_ Position to set Car to.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the Car's direction.
   *
   * @param dir_ Direction to set for Car.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the Car's destination.
   *
   * @param des_ Destination to set for Car.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  /**
   * @brief Removing the copy constructor so cars can't be copied.
   *
   * @param car Car that was going to be copied.
   **/
  Car(const Car& car) = delete;
  /**
   * @brief Removing the assignment operator so cars can't be copied.
   *
   * @param car Car that was going to be copied.
   * @return Address for Car.
   **/
  Car& operator=(const Car& car) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  std::string strategyName;
  IStrategy* moveStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
