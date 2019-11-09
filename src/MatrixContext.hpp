#ifndef MATRYX_MATRIXCONTEXT_H
#define MATRYX_MATRIXCONTEXT_H

#include "Canvas.hpp"
#include "Matrix.hpp"
#include <memory>

namespace matryx {
class MatrixContext {
public:
  MatrixContext(std::shared_ptr<matryx::Matrix> matrix,
                std::shared_ptr<matryx::Canvas> canvas)
      : matrix(matrix), canvas(canvas) {}

  std::shared_ptr<matryx::Matrix> matrix;
  std::shared_ptr<matryx::Canvas> canvas;
};
} // namespace matryx

#endif
