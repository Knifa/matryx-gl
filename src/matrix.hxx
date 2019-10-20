#ifndef MATRYX_MATRIX_H
#define MATRYX_MATRIX_H

#include <array>
#include <cstdint>
#include <memory>
#include <string>

#include <zmq.hpp>

namespace matryx {
    class Matrix {
        public:
            Matrix(const std::string zmqEndpoint, const int width, const int height);
            void connect();
            void sendFrame(const uint8_t *frame);

            std::size_t getFrameSize();

            int getWidth();
            int getHeight();

        private:
            std::string zmqEndpoint;
            std::unique_ptr<zmq::context_t> zmqContext;
            std::unique_ptr<zmq::socket_t> zmqSocket;

            int width;
            int height;
    };
}

#endif
