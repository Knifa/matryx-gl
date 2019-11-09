#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include "Canvas.hxx"
#include "Matrix.hxx"

using std::cos;
using std::pow;
using std::sin;
using std::sqrt;

constexpr double pi = 3.14159265358979323846;

int main(int argc, char *argv[]) {
  matryx::Matrix matrix("ipc:///tmp/matrix_0", 64, 32);
  matryx::Canvas canvas(matrix.getWidth(), matrix.getHeight());
  matrix.connect();

  float t = 0;
  while (true) {
    for (int y = 0; y < matrix.getHeight(); y++) {
      for (int x = 0; x < matrix.getWidth(); x++) {
        float xp = ((x / 128.0f) - 0.5f) * (5.0f + sin(t * 0.25)) +
                   sin(t * 0.25) * 5.0f;
        float yp = ((y / 128.0f) - 0.5f) * (5.0f + sin(t * 0.25)) +
                   cos(t * 0.25) * 5.0f;

        float pixel = sin(sin(sin(0.25 * t) * xp + cos(0.29 * t) * yp + t) +
                          sin(sqrt(pow(xp + sin(t * 0.25f) * 4.0f, 2) +
                                   pow(yp + cos(t * 0.43f) * 4.0f, 2)) +
                              t) -
                          cos(sqrt(pow(xp + cos(t * 0.36f) * 6.0f, 2) +
                                   pow(yp + sin(t * 0.39f) * 5.3f, 2)) +
                              t));

        float u = pow(cos(9 * pixel + 0.5f * xp + t) * 0.5f + 0.5f, 2);
        float v = pow(sin(9 * pixel + 0.5f * yp + t) * 0.5f + 0.5f, 2);

        canvas.setPixel(x, y, u, v, (u + v) / 2);
      }
    }

    matrix.sendFrame(canvas.getFrame());

    t += 0.002f;
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
  }

  return 0;
}
