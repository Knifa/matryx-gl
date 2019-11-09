#ifndef MATRYX_SCENE_HPP
#define MATRYX_SCENE_HPP

#include <memory>

#include "FrameTimer.hpp"
#include "MatrixContext.hpp"

namespace matryx {
class Scene {
public:
  Scene(std::shared_ptr<matryx::MatrixContext> matrixContext);

  virtual void setup();
  virtual void tick(FrameTime frameTime) = 0;

protected:
  std::shared_ptr<MatrixContext> ctx;
};
} // namespace matryx

#endif
