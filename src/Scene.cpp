#include "Scene.hpp"
#include "MatrixContext.hpp"

using matryx::Scene;

Scene::Scene(std::shared_ptr<matryx::MatrixContext> matrixCtx) {
  this->ctx = matrixCtx;
}

void Scene::setup() {}
