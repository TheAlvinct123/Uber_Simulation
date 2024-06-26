#include "DfsStrategy.h"

#include "graph.h"
#include "routing/depth_first_search.h"
#include "routing_api.h"
using namespace routing;

DfsStrategy::DfsStrategy(Vector3 position, Vector3 destination,
                         const IGraph* graph) {
  this->graph = graph;

  std::vector<float> positionV;
  positionV.push_back(position.x);
  positionV.push_back(position.y);
  positionV.push_back(position.z);

  std::vector<float> destinationV;
  destinationV.push_back(destination.x);
  destinationV.push_back(destination.y);
  destinationV.push_back(destination.z);

  std::vector<float> start =
      graph->NearestNode(positionV, EuclideanDistance())->GetPosition();
  std::vector<float> end =
      graph->NearestNode(destinationV, EuclideanDistance())->GetPosition();

  path = graph->GetPath(start, end, DepthFirstSearch::Default());
  currentIndex = 0;
  maxIndex = path.size() - 1;

  routeLength = 0;
  Vector3 pointX = Vector3(path[0].at(0), path[0].at(1), path[0].at(2));
  Vector3 pointY;
  for (int i = 1; i < path.size(); i++) {
    pointY = Vector3(path[i].at(0), path[i].at(1), path[i].at(2));

    routeLength += pointX.Distance(pointY);

    pointX = pointY;
  }
}

bool DfsStrategy::IsCompleted() { return currentIndex == maxIndex; }

void DfsStrategy::Move(IEntity* entity, double dt) {
  Vector3 currentPos = entity->GetPosition();
  Vector3 destination =
      Vector3(path[currentIndex].at(0), path[currentIndex].at(1),
              path[currentIndex].at(2));
  Vector3 direction = (destination - currentPos).Unit();
  float speed = entity->GetSpeed();
  currentPos = currentPos + direction * speed * dt;
  entity->SetPosition(currentPos);
  entity->SetDirection(direction);

  if ((destination - currentPos).Magnitude() < 1.0) {
    currentIndex++;
  }
}
