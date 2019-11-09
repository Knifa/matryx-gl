#include <cmath>

#include "../FrameTimer.hxx"
#include "WatermelonPlasmaScene.hxx"

using std::cos;
using std::pow;
using std::sin;
using std::sqrt;

using matryx::scenes::WatermelonPlasmaScene;

void WatermelonPlasmaScene::setup(){};
void WatermelonPlasmaScene::tick(FrameTime frameTime) {
  float t = frameTime.t * 0.1;

  for (int y = 0; y < ctx->matrix->getHeight(); y++) {
    for (int x = 0; x < ctx->matrix->getWidth(); x++) {
      float xp =
          ((x / 128.0f) - 0.5f) * (5.0f + sin(t * 0.25)) + sin(t * 0.25) * 5.0f;
      float yp =
          ((y / 128.0f) - 0.5f) * (5.0f + sin(t * 0.25)) + cos(t * 0.25) * 5.0f;

      float pixel = sin(sin(sin(0.25 * t) * xp + cos(0.29 * t) * yp + t) +
                        sin(sqrt(pow(xp + sin(t * 0.25f) * 4.0f, 2) +
                                 pow(yp + cos(t * 0.43f) * 4.0f, 2)) +
                            t) -
                        cos(sqrt(pow(xp + cos(t * 0.36f) * 6.0f, 2) +
                                 pow(yp + sin(t * 0.39f) * 5.3f, 2)) +
                            t));

      float u = pow(cos(9 * pixel + 0.5f * xp + t) * 0.5f + 0.5f, 2);
      float v = pow(sin(9 * pixel + 0.5f * yp + t) * 0.5f + 0.5f, 2);

      ctx->canvas->setPixel(x, y, u, v, (u + v) / 2);
    }
  }

  ctx->matrix->sendFrame(ctx->canvas->getFrame());
};
