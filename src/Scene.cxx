#include "Scene.hxx"
#include "MatrixContext.hxx"

using matryx::Scene;

Scene::Scene(std::shared_ptr<matryx::MatrixContext> matrixCtx) {
  this->ctx = matrixCtx;
}

void Scene::setup() {}
