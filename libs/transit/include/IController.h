#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------
/**
 * @brief Abstract controller class used in the Transit Service.  Uses the Model
 *View. Done with Controller Pattern.
 **/
class IController {
 public:
  /**
   * @brief IController Destructor.
   **/
  virtual ~IController() {}
  /**
   * @brief Adds an entity to the program.
   *
   * @param entity Entity being added to the program.
   **/
  virtual void AddEntity(const IEntity& entity) = 0;
  /**
   * @brief Update's an entity in the program.
   *
   * @param entity Entity being updated in the program.
   **/
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /**
   * @brief Removes an entity in the program.
   *
   * @param id ID of Entity being removed in the program.
   **/
  virtual void RemoveEntity(int id) = 0;
  /**
   * @brief Adds a path to the program.
   *
   * @param id ID of Entity whose path needs to be added in the program.
   * @param path Path of Entity.
   **/
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /**
   * @brief Removes an entity's path in the program.
   *
   * @param id ID of Entity whose path is being removed in the program.
   **/
  virtual void RemovePath(int id) = 0;
  /**
   * @brief Allows messages to be passed back to the view.
   *
   * @param event event that needs to be viewed in the program.
   * @param details Details of Entity.
   **/
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
