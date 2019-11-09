#ifndef MATRYX_SCENES_WATERMELONPLASMASCENEHPP
#define MATRYX_SCENES_WATERMELONPLASMASCENEHPP

#include "../FrameTimer.hpp"
#include "../Scene.hpp"

namespace matryx::scenes {
class WatermelonPlasmaScene : public Scene {
public:
  using Scene::Scene;

  void setup();
  void tick(FrameTime frameTime);
};
} // namespace matryx::scenes

#endif
