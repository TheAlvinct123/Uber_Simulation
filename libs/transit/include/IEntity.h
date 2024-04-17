#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------
/**
 * @brief Abstract controller class used in the Transit Service.  Uses the Model
 *View Controller Pattern.
 **/
class IEntity {
 public:
  /**
   * @brief Constructor of IEntity.
   *
   **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief destructor of IEntity.
   *
   **/
  virtual ~IEntity() {}
  /**
   * @brief Gets IEntity's Id.
   *
   * @return IEntity's Id.
   **/
  virtual int GetId() const { return id; }
  /**
   * @brief Gets IEntity's position.
   *
   * @return IEntity's position.
   **/
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets IEntity's direction.
   *
   * @return IEntity's direction.
   **/
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets IEntity's destination.
   *
   * @return IEntity's destination.
   **/
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets IEntity's details.
   *
   * @return IEntity's details.
   **/
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets IEntity's speed.
   *
   * @return IEntity's speed.
   **/
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets IEntity's Availability.
   *
   * @return IEntity's Availability.
   **/
  virtual bool GetAvailability() const {}
  /**
   * @brief Gets name of IEntity's Strategy.
   *
   * @return Gets name of IEntity's Strategy.
   **/
  virtual std::string GetStrategyName() { return ""; }
  /**
   * @brief Sets IEntity's Availability.
   * @param boolean value to set Availability to (true= available, false=
   *unavailable).
   **/
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates IEntity's position.
   *
   * @param dt Change in speed.
   * @param scheduler Scheduler.
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler,
                      std::vector<IEntity*> chargers) {}
  /**
   * @brief Sets Graph.
   *
   * @param graph Graph value to set IEntity's graph to.
   **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the IEntity's position.
   *
   * @param pos_ Position to set for IEntity.
   **/
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the IEntity's direction.
   *
   * @param pos_ direction to set for IEntity.
   **/
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the IEntity's destination.
   *
   * @param des_ destination to set for IEntity.
   **/
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the IEntity's Strategy name.
   *
   * @param strategyName_  Strategy name to set IEntity's Strategy name to.
   **/
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Rotates IEntity.
   *
   * @param angle angle to rotate IEntity by.
   **/
  virtual void Rotate(double angle) {}
  /**
   * @brief Makes IEntity jump.
   *
   * @param height height for IEntity to jump by.
   **/
  virtual void Jump(double height) {}
  /**
   * @brief Gets the IEntity's battery.
   *
   * @return Battery level.
   **/
  virtual double GetBattery() const { return -1.0; }
  /**
   * @brief Gets nearest entity.
   * @param scheduler scheduler used to get nearest entity.
   **/
  virtual void GetNearestEntity(std::vector<IEntity*> scheduler) {}
  /**
   * @brief Gets route length.
   * @return Route length.
   **/
  virtual float GetRouteLength() const { return -1.0; }
  /**
   * @brief Returns nearest entity.
   * @return Nearest entity.
   **/
  virtual IEntity* ReturnNearestEntity() { return NULL; }

 protected:
  int id;
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
