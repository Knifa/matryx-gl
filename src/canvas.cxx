#include <algorithm>
#include <cstdint>

#include "canvas.hxx"

using namespace matryx;
using std::max;
using std::min;

Canvas::Canvas(const int width, const int height) {
  this->width = width;
  this->height = height;
  this->frame = new uint8_t[width * height * Canvas::BITS_PER_PIXEL];
}

void Canvas::setPixel(const int x, const int y, const float r, const float g,
                      const float b) {
  const uint8_t rByte = static_cast<uint8_t>(max(0.0f, min(1.0f, r)) * 255.0f);
  const uint8_t gByte = static_cast<uint8_t>(max(0.0f, min(1.0f, g)) * 255.0f);
  const uint8_t bByte = static_cast<uint8_t>(max(0.0f, min(1.0f, b)) * 255.0f);

  const std::size_t offset =
      x * Canvas::BITS_PER_PIXEL + y * this->width * BITS_PER_PIXEL;
  this->frame[offset + 0] = rByte;
  this->frame[offset + 1] = gByte;
  this->frame[offset + 2] = bByte;
}

uint8_t *Canvas::getFrame() { return this->frame; }
