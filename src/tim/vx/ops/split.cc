/****************************************************************************
*
*    Copyright (c) 2020 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/
#include "tim/vx/ops/split.h"

#include "builtin_op_impl.h"
#include "vsi_nn_pub.h"

namespace tim {
namespace vx {
namespace ops {

Split::Split(Graph* graph, uint32_t axis, std::vector<uint32_t> slices)
    : BuiltinOp(graph, VSI_NN_OP_SPLIT, 1, slices.size()),
      axis_(axis),
      slices_(std::move(slices)) {
  this->impl()->node()->nn_param.split.axis = axis_;
  this->impl()->node()->nn_param.split.slices = slices_.data();
  this->impl()->node()->nn_param.split.slices_num = slices_.size();
}

std::shared_ptr<Operation> Split::Clone(std::shared_ptr<Graph>& graph) const {
  return graph->CreateOperation<Split>(this->axis_, this->slices_);
}

}  // namespace ops
}  // namespace vx
}  // namespace tim
