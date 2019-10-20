#include <algorithm>
#include <cstdint>

#include "canvas.hxx"

using namespace matryx;

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

  const std this
      ->frame[x * Canvas::BITS_PER_PIXEL + y * this->width * BITS_PER_PIXEL]
}

uint8_t *Canvas::getFrame() { return this->frame; }
