#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "Canvas.hxx"
#include "Matrix.hxx"
#include "MatrixContext.hxx"
#include "FrameTimer.hxx"
#include "scenes/WatermelonPlasmaScene.hxx"



constexpr double pi = 3.14159265358979323846;

int main(int argc, char *argv[]) {
  auto matrix = std::make_shared<matryx::Matrix>("ipc:///tmp/matrix_0", 64, 32);
  matrix->connect();

  auto canvas =
      std::make_shared<matryx::Canvas>(matrix->getWidth(), matrix->getHeight());
  auto matrixCtx = std::make_shared<matryx::MatrixContext>(matrix, canvas);

  matryx::scenes::WatermelonPlasmaScene scene(matrixCtx);

  matryx::FrameTimer frameTimer;

  while (true) {
    auto frameTime = frameTimer.tick();
    // std::cout << "t: " << frameTime.t << std::endl;
    // std::cout << "dt: " << frameTime.dt << std::endl;
    // std::cout << std::endl;

    scene.tick(frameTime);
  }

  return 0;
}
