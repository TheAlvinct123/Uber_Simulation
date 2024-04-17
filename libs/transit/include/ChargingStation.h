#ifndef LIBS_TRANSIT_INCLUDE_CHARGINGSTATION_H_
#define LIBS_TRANSIT_INCLUDE_CHARGINGSTATION_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief  ChargingStation class used to represent Charging Station in
 *simulation.
 **/
class ChargingStation : public IEntity {
 public:
  /**
   * @brief  Constructor for ChargingStation entity.
   * @param obj JsonObject to be turned into ChargingStation.
   **/
  ChargingStation(JsonObject& obj);

  /**
   * @brief  Destructor for ChargingStation entity.
   **/
  ~ChargingStation();
  /**
   * @brief  Returns Car's speed.
   * @return Car's speed.
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief  Returns the ChargingStation's position.
   * @return ChargingStation's position.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief  Returns the ChargingStation's direction.
   * @return ChargingStation's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief  Returns the ChargingStation's destination.
   * @return ChargingStation's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief  Returns the ChargingStation's details.
   * @return Returns ChargingStation's details via Json Object.
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Returns the charging stations status, of true as its always
   * available
   * @return true
   */
  bool GetAvailability() const { return true; }
  /**
   * @brief Sets the ChargingStation's position.
   *
   * @param pos_ Position to set ChargingStation to.
   **/
  void SetPosition(Vector3 pos_) { /*position = pos_;*/
  }
  /**
   * @brief Sets the ChargingStation's direction.
   *
   * @param dir_ Direction to set for ChargingStation.
   **/
  void SetDirection(Vector3 dir_) { /*direction = dir_; */
  }
  /**
   * @brief Sets the ChargingStation's destination.
   *
   * @param des_ Destination to set for ChargingStation.
   **/
  void SetDestination(Vector3 des_) { /*destination = des_; */
  }

  // Removing the copy constructor and assignment operator
  // so that ChargingStation cannot be copied.
  /**
   * @brief Removing the copy constructor so ChargingStation can't be copied.
   *
   * @param station ChargingStation that was going to be copied.
   **/
  ChargingStation(const ChargingStation& station) = delete;
  /**
   * @brief Removing the assignment operator so ChargingStation can't be copied.
   *
   * @param station ChargingStation that was going to be copied.
   * @return Address for ChargingStation.
   **/
  ChargingStation& operator=(const ChargingStation& station) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  std::string strategyName;
  IStrategy* moveStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_CHARGINGSTATION_H_
