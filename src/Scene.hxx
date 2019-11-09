#ifndef MATRYX_SCENE_H
#define MATRYX_SCENE_H

#include <memory>

#include "FrameTimer.hxx"
#include "MatrixContext.hxx"

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
