#ifndef MATRYX_SCENES_WAVESCENE_HPP
#define MATRYX_SCENES_WAVESCENE_HPP

#include "../FrameTimer.hpp"
#include "../Scene.hpp"

namespace matryx::scenes {
class WaveScene : public matryx::Scene {
public:
  using Scene::Scene;

  void setup();
  void tick(FrameTime frameTime);
};
} // namespace matryx::scenes

#endif