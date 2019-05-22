// Test program for linux based system
// Testing C++ capability of tensorflow through c_api.h
// https://gist.github.com/asimshankar/7c9f8a9b04323e93bb217109da8c7ad2

#include <iostream>
#include <vector>
#include "libs/c_api.h"

using namespace std;

int main(){
    TF_Graph* graph = TF_NewGraph();
    TF_Status* status = TF_NewStatus();
    TF_SessionOptions* options = TF_NewSessionOptions();
    TF_Session* session = TF_NewSession(graph, options, status);
    //TF_Operation* oper = ScalarConst(3, graph, session);
    TF_Buffer* graph_def = TF_NewBuffer();
    TF_GraphToGraphDef(graph, graph_def, status);
    cout << "Done" << endl;

    return 0;
}
