//Testing inferencing with tensorflow C++ APIs
#include <iostream>
#include <vector>
#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/tensor.h"

using namespace std;
using namespace tensorflow;
using namespace tensorflow::ops;

int main(){
    // Root is where context lies.
    Scope root = Scope::NewRootScope();
    auto t1 = Const(root, {{1.f, 1.f},{1.f, 1.f}});
    auto t2 = Const(root, {{2.f, 2.f},{2.f, 2.f}});
    auto add_op = Add(root.WithOpName("add"), t1, t2);
    vector<Tensor> outputs;
    // Create a session in the root context
    ClientSession session(root);
    TF_CHECK_OK(session.Run({v}, &outputs));
    LOG(INFO) << outputs[0].matrix<float>();

    return 0;
}
