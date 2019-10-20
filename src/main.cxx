#include <iostream>

#include "canvas.hxx"
#include "matrix.hxx"

int main (int argc, char *argv[])
{
    matryx::Matrix matrix("tcp://127.0.0.1:8100", 64, 32);
    matrix.connect();

    matryx::Canvas canvas(matrix.getWidth(), matrix.getHeight());

    uint8_t frame[matrix.getFrameSize()];
    float t = 0;

    while (true) {
        for (int y = 0; y < matrix.getHeight(); y++) {
            for (int x = 0; x < matrix.getWidth(); x++) {
                frame[x * 4 + y * matrix.getWidth() * 4 + 0] = static_cast<uint8_t>(x / 64.0f * t * 255.0f);
                frame[x * 4 + y * matrix.getWidth() * 4 + 1] = static_cast<uint8_t>(y / 32.0f * 255.0f);
                frame[x * 4 + y * matrix.getWidth() * 4 + 2] = static_cast<uint8_t>((1 - ((x + y) / (32.0f + 64.0f))) * 255.0f);
            }
        }

        matrix.sendFrame(frame);
        t+= 0.1;
    }

    return 0;
}
