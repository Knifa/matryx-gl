#ifndef MATRYX_FRAMETIMER_HPP
#define MATRYX_FRAMETIMER_HPP

#include <chrono>

namespace matryx {
struct FrameTime {
  std::chrono::high_resolution_clock::time_point now;

  std::chrono::duration<double> deltaStart;
  std::chrono::duration<double> deltaFrame;

  float t = 0;
  float dt = 0;
};

class FrameTimer {
public:
  FrameTimer();

  const FrameTime tick();

private:
  std::chrono::high_resolution_clock::time_point startTick;
  std::chrono::high_resolution_clock::time_point lastTick;
};
} // namespace matryx

#endif
