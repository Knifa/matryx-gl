#ifndef MATRYX_CANVAS_H
#define MATRYX_CANVAS_H

#include <cstdint>

namespace matryx {
    class Canvas {
        public:
            static constexpr int BITS_PER_PIXEL = 4;

            Canvas(const int width, const int height);
            void setPixel(int x, int y, float r, float g, float b);
            uint8_t *getFrame();

        private:
            int width;
            int height;
            uint8_t *frame;
    };


};

#endif
