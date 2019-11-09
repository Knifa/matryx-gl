#include <chrono>
#include <ratio>
#include "FrameTimer.hxx"

using matryx::FrameTime;
using matryx::FrameTimer;

FrameTimer::FrameTimer() {
  startTick = std::chrono::high_resolution_clock::now();
  lastTick = startTick;
}

const FrameTime FrameTimer::tick() {
  auto now = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> t(now - startTick);
  std::chrono::duration<double> dt(now - lastTick);

  struct FrameTime frameTime;
  frameTime.t = t.count();
  frameTime.dt = dt.count();

  lastTick = now;

  return frameTime;
}
