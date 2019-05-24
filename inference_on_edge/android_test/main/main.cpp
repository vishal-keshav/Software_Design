// Test program for android based system
// Testing C++ capability of tensorflow through c_api.h

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
