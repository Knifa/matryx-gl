#ifndef MATRYX_FRAMETIMER_HXX
#define MATRYX_FRAMETIMER_HXX

#include <chrono>

namespace matryx {
  struct FrameTime {
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
}

#endif
