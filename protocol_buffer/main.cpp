#include <iostream>
#include <fstream>
#include <string>
#include "cost.pb.h"

using namespace std;

int main(){
    example_proto_class::Computer_Cost cc;
    fstream  in_file("example_bin_file", ios::in | ios::binary);
    if(in_file){
        cc.ParseFromIstream(&in_file);
        //Print the data
        cout << cc.brand() << endl;
        cout << "cpu_cost: " << cc.CPU_Cost().cost() << endl;
        cout << "monitor_cost: " << cc.Monitor_Cost().cost() << endl;
        cout << "interface_cost: " << cc.Interface_Cost().cost() << endl;
    }
    // Modify the data
    cc.set_brand("AMD");
    cc.set_CPU_Cost().set_cost(1000);
    cc.set_Monitor_Cost().set_cost(500);
    cc.set_Interface_Cost().set_cost(300);
    fstream out_file("example_bin_file", ios::trunc | ios::binary);
    cc.SerializeToOstream(&out_file)
    return 0;

}
