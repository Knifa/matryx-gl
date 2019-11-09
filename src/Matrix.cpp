#include <array>
#include <cstdint>
#include <memory>
#include <string>

#include <zmq.hpp>

#include "Matrix.hpp"

using matryx::Matrix;

Matrix::Matrix(const std::string zmqEndpoint, const int width,
               const int height) {
  this->zmqEndpoint = zmqEndpoint;
  this->width = width;
  this->height = height;

  this->zmqContext.reset(new zmq::context_t());
  this->zmqSocket.reset(
      new zmq::socket_t(*this->zmqContext, zmq::socket_type::req));
}

void Matrix::connect() { this->zmqSocket->connect(this->zmqEndpoint); }

void Matrix::sendFrame(const uint8_t *frame) {
  this->zmqSocket->send(frame, this->getFrameSize(), 0);
  this->zmqSocket->recv(nullptr, 0, 0);
}

std::size_t Matrix::getFrameSize() {
  return this->width * this->height * Matrix::BITS_PER_PIXEL;
}

int Matrix::getWidth() { return this->width; }

int Matrix::getHeight() { return this->height; }
