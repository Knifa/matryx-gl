#ifndef MATRYX_SCENES_WATERMELONPLASMASCENE_HXX
#define MATRYX_SCENES_WATERMELONPLASMASCENE_HXX

#include "../FrameTimer.hxx"
#include "../Scene.hxx"

namespace matryx::scenes {
class WatermelonPlasmaScene : public Scene {
public:
  using Scene::Scene;

  void setup();
  void tick(FrameTime frameTime);
};
} // namespace matryx::scenes

#endif
