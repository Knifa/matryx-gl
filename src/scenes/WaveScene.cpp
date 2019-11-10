#include "WaveScene.hpp"
#include "../FrameTimer.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory>

using matryx::scenes::WaveScene;

static float *map = nullptr;

const unsigned int xyToIndex(int h, int x, int y) { return y * h + x; }

void drawMap(std::shared_ptr<matryx::MatrixContext> ctx, float *map) {
  for (int y = 0; y < ctx->matrix->getHeight(); y++) {
    for (int x = 0; x < ctx->matrix->getWidth(); x++) {
      const int i = xyToIndex(ctx->matrix->getWidth(), x, y);
      ctx->canvas->setPixel(x, y,
                            std::pow(map[i], 4 + (map[i] * 0.5)) * std::cos(map[i]),
                            std::pow(map[i], 3 + (map[i] * 0.5)) * std::sin(map[i]),
                            std::pow(map[i], 2 + (map[i] * 0.5)));
    }
  }
}

void WaveScene::setup() {
  std::srand(std::time(0));

  map = new float[ctx->matrix->getWidth() * ctx->matrix->getHeight()];

  for (int y = 0; y < ctx->matrix->getHeight(); y++) {
    for (int x = 0; x < ctx->matrix->getWidth(); x++) {
      const int i = xyToIndex(ctx->matrix->getWidth(), x, y);
      map[i] = static_cast<float>(std::rand()) / RAND_MAX;
    }
  }
}

void WaveScene::tick(FrameTime frameTime) {
  float *lastMap = map;
  map = new float[ctx->matrix->getWidth() * ctx->matrix->getHeight()];

  for (int y = 0; y < ctx->matrix->getHeight(); y++) {
    for (int x = 0; x < ctx->matrix->getWidth(); x++) {
      const int i = xyToIndex(ctx->matrix->getWidth(), x, y);
      const float lastValue = lastMap[i];

      map[i] = lastValue * (0.96 + 0.02 * (static_cast<float>(std::rand()) / RAND_MAX));

      if (lastValue <= (0.18 + 0.04 * (static_cast<float>(std::rand()) / RAND_MAX))) {
        float n = 0;

        for (int u = -1; u <= 1; u++) {
          for (int v = -1; v <= 1; v++) {
            if (u == 0 && u == 0) {
              continue;
            }

            int nX = std::abs((x + u) % ctx->matrix->getWidth());
            int nY = std::abs((y + v) % ctx->matrix->getHeight());

            const int nI = xyToIndex(ctx->matrix->getWidth(), nX, nY);
            const float nLastValue = lastMap[nI];

            if (nLastValue >= (0.5 + 0.04 * (static_cast<float>(std::rand()) / RAND_MAX))) {
              n += 1;
              map[i] += nLastValue * (0.8 + 0.4 * (static_cast<float>(std::rand()) / RAND_MAX));
            }
          }
        }

        if (n > 0) {
          map[i] *= 1 / n;
        }

        if (map[i] > 1)
          map[i] = 1;
      }
    }
  }

  drawMap(ctx, map);

  ctx->matrix->sendFrame(ctx->canvas->getFrame());
}