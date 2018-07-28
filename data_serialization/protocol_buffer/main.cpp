#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "cost.pb.h"

using namespace std;

int main(){
    srand (time(NULL));
    cout << "Main Program" << endl;
    example_proto_class::Computer_Cost cc;
    fstream  in_file("example_bin_file.data", ios::in | ios::binary);
    if(in_file){
        cout << "Read pb file" << endl;
        if(!cc.ParseFromIstream(&in_file)){
            cout << "Could not parse binary file" << endl;
        }
        //Print the data
        cout << "Brand Name: "<<cc.brand() << endl;
        cout << "cpu_cost: " << cc.cpu_cost().cost() << endl;
        cout << "monitor_cost: " << cc.mon_cost().cost() << endl;
        cout << "interface_cost: " << cc.in_cost().cost() << endl;
    }
    cout << "Modifying object and writing pb file" << endl;
    // Modify the data
    cc.set_brand("AMD");
    cc.mutable_cpu_cost()->set_cost(rand()%1000);
    cc.mutable_mon_cost()->set_cost(rand()%500);
    cc.mutable_in_cost()->set_cost(rand()%100);
    fstream out_file("example_bin_file.data", ios::out | ios::trunc | ios::binary);
    if(!cc.SerializeToOstream(&out_file)){
        cout << "Could not write out file" << endl;
    };
    return 0;
}
