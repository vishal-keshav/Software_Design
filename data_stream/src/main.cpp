#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

enum DataType{
    INT = 0,
    FLOAT = 1,
    DOUBLE = 2,
    CHAR = 3,
    STRING = 4
}

class DataStreamer{
public:
    // Constructor with base member initialization
    DataStreamer() :
        total_bytes(0),
        unused_bytes(-1),
        data_ref(NULL),
        read_write_ref(NULL) {}
    // At the creation of streamer,
    // we decide on bytes this streamer can hold
    void init_num_bytes(int nr_bytes){
        if(nr_bytes!=0){
            clear_memory();
        }
        total_bytes = nr_bytes;
        unused_bytes = nr_bytes;
        // An integer is of 4 bytes
        data_ref = new int[nr_bytes/4];
        read_write_ref = data_ref;
    }
    // At this time, streamer is required to
    // output byte data sequentially
    void init_read_mode(void){
        read_write_ref = data_ref;
    }
    void clear_memory(){
        delete [] data_ref;
    }
    //Operator overloading, args passed by ref-value
    DataStreamer& operator<<(int &input){
        int *local_ref = (int*)read_write_ref;
        *local_ref = input;
        local_ref++;
        read_write_ref = local_ref;
        unused_bytes-=sizeof(int);
        return *this;
    }
    DataStreamer& operator>>(int& output){
        int *local_ref = (int*)read_write_ref;
        output = *local_ref;
        local_ref++;
        read_write_ref = local_ref;
        return *this;
    }
    // Desctructor, with memory free
    ~DataStreamer(){
        clear_memory();
        data_ref = NULL;
        read_write_ref = NULL;
    }
private:
    int total_bytes;
    int unused_bytes;
    int* data_ref;
    int *read_write_ref;
};

int main(){
    int a = 34;
    int d = 12;
    DataStreamer ds;
    ds.init_num_bytes(1024);
    ds << a;
    ds << d;
    ds.init_read_mode();
    int b,c;
    ds >> b;
    ds >> c;
    cout << b << " " << c << endl;
    return 0;
}
