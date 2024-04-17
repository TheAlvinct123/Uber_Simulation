#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation. The model can
 *communicate with the controller.
 *
 **/
class SimulationModel {
 public:
  /**
   * @brief SimulationModel Constructor.
   * @param controller Controller used in transit service.
   **/
  SimulationModel(IController& controller);
  /**
   * @brief Sets graph.
   * @param graph Graph that needs to be set.
   **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Creates an simulation entity.
   * @param entity Entity to be created.
   **/
  void CreateEntity(JsonObject& entity);
  /**
   * @brief Schedules a trip for an object in the scene.
   * @param details Details of Entity.
   **/
  void ScheduleTrip(JsonObject& details);
  /**
   * @brief Updates the simulation.
   * @param dt rate of change.
   **/
  void Update(double dt);
  /**
   * @brief Adds a new entity type.
   * @param factory IEntityFactory that needs to be added.
   **/
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  std::vector<IEntity*> chargers;

  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
