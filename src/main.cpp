#include <chrono>
#include <iostream>
#include <memory>
#include <ratio>
#include <thread>

#include "Canvas.hpp"
#include "FrameTimer.hpp"
#include "Matrix.hpp"
#include "MatrixContext.hpp"
#include "scenes/WatermelonPlasmaScene.hpp"

constexpr double targetFps = 30;
constexpr std::chrono::duration<double> targetDurationPerFrame(1.0 / targetFps);

int main(int argc, char *argv[]) {
  auto matrix = std::make_shared<matryx::Matrix>("ipc:///tmp/matrix_0", 64, 32);
  matrix->connect();

  auto canvas =
      std::make_shared<matryx::Canvas>(matrix->getWidth(), matrix->getHeight());
  auto matrixCtx = std::make_shared<matryx::MatrixContext>(matrix, canvas);

  matryx::scenes::WatermelonPlasmaScene scene(matrixCtx);

  matryx::FrameTimer frameTimer;
  matryx::FrameTimer paceTimer;

  while (true) {
    auto frameTime = frameTimer.tick();
    scene.tick(frameTime);
    std::this_thread::sleep_until(frameTime.now + targetDurationPerFrame);
  }

  return 0;
}
