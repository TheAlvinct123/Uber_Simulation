#define _USE_MATH_DEFINES
#include "Ufo.h"

#include <cmath>
#include <limits>

#include "BeelineStrategy.h"

Ufo::Ufo(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
}

Ufo::~Ufo() {
  // Delete dynamically allocated variables
}

void Ufo::Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> chargers) {
  if (moveStrategy == NULL) {
    // Get random destination < -1400 < x < 1500, 240 < y < Inf, -800 < z < 800
    // >
    Vector3 *dest =
        new Vector3((int)(rand() % 2900 - 1400), (int)(rand() % 1000 + 240),
                    (int)(rand() % 1600 - 800));
    SetDestination(*dest);

    moveStrategy =
        new BeelineStrategy(this->GetPosition(), this->GetDestination());

    // Get random position < -1400 < x < 1500, 240 < y < Inf, -800 < z < 800 >
    Vector3 *pos =
        new Vector3((int)(rand() % 2900 - 1400), (int)(rand() % 1000 + 240),
                    (int)(rand() % 1600 - 800));
    SetPosition(*pos);
  } else {
    // // Randomly multiply dt < 1 < dt < 5 >
    // dt = dt * (rand() % 50 + 1);
    moveStrategy->Move(this, dt);

    if (moveStrategy->IsCompleted()) {
      delete moveStrategy;
      moveStrategy = NULL;
    }
  }
}
