#include "async_helper/tensor.h"
#include "graph.h"
#include "op.h"
#include "session.h"

#include <cmath>
#include <iostream>

namespace ah = async_helper;

bool Check(ah::Tensor &t1, ah::Tensor &t2, ah::Tensor &t3, ah::Tensor &sum) {
  DCHECK(t1.rows == t2.rows);
  DCHECK(t1.rows == t3.rows);
  DCHECK(t1.rows == sum.rows);
  DCHECK(t1.cols == t2.cols);
  DCHECK(t1.cols == t3.cols);
  DCHECK(t1.cols == sum.cols);

  const float err = 1e-6;

  for (int64_t i = 0; i < t1.rows * t1.cols; i++) {
    if (std::fabs(t1.data.get()[i] + t2.data.get()[i] + t3.data.get()[i] -
                  sum.data.get()[i]) > err) {
      return false;
    }
  }
  return true;
}

int main() {
  ah::Tensor t1(2, 3);
  ah::Tensor t2(2, 3);
  ah::Tensor t3(2, 3);

  ah::SetValueOp op1("t1", &t1, 1);
  ah::SetValueOp op2("t2", &t2, 2);
  ah::SetValueOp op3("t3", &t3, 3);

  ah::AddOp add_op1("add1", &op1, &op2);
  ah::AddOp add_op2("add2", &op3, &add_op1);

  ah::Graph *graph = ah::GetDefaultGraph();
  // graph->ShowGraph();

  ah::Session session;
  session.Create(graph);

  std::vector<std::vector<ah::Tensor *>> res;
  session.Run({"add2", "add1"}, &res);
  ah::ShowTensor(*res[0][0]);
  ah::ShowTensor(*res[1][0]);

  if (!Check(t1, t2, t3, *res[0][0])) {
    std::cout << "Check failed" << std::endl;
    return -1;
  }
  std::cout << "Check passed" << std::endl;
  return 0;
}