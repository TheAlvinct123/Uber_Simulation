#define _USE_MATH_DEFINES
#include "ChargingStation.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"

ChargingStation::ChargingStation(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  destination = position;

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
}

ChargingStation::~ChargingStation() {
  // Delete dynamically allocated variables
}

