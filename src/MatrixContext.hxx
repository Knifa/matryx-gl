#ifndef MATRYX_MATRIXCONTEXT_H
#define MATRYX_MATRIXCONTEXT_H

#include "Canvas.hxx"
#include "Matrix.hxx"
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
