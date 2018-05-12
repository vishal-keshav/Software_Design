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
};

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
    //Operator overloading(INT), args passed by ref-value
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
    //Operator overloading(FLOAT), args passed by ref-value
    DataStreamer& operator<<(float &input){
        float *local_ref = reinterpret_cast<float*>(read_write_ref);
        *local_ref = input;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        unused_bytes-=sizeof(float);
        return *this;
    }
    DataStreamer& operator>>(float& output){
        float *local_ref = reinterpret_cast<float*>(read_write_ref);
        output = *local_ref;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        return *this;
    }
    //Operator overloading(DOUBLE), args passed by ref-value
    DataStreamer& operator<<(double &input){
        double *local_ref = reinterpret_cast<double*>(read_write_ref);
        *local_ref = input;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        unused_bytes-=sizeof(double);
        return *this;
    }
    DataStreamer& operator>>(double& output){
        double *local_ref = reinterpret_cast<double*>(read_write_ref);
        output = *local_ref;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        return *this;
    }
    //Operator overloading(CHAR), args passed by ref-value
    DataStreamer& operator<<(char &input){
        char *local_ref = reinterpret_cast<char*>(read_write_ref);
        *local_ref = input;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        unused_bytes-=sizeof(char);
        return *this;
    }
    DataStreamer& operator>>(char& output){
        char *local_ref = reinterpret_cast<char*>(read_write_ref);
        output = *local_ref;
        local_ref++;
        read_write_ref = reinterpret_cast<int*>(local_ref);
        return *this;
    }
    //Operator overloading(CHAR), args passed by ref-value
    DataStreamer& operator<<(string &input){
        int *local_ref = reinterpret_cast<int*>(read_write_ref);
        int nr_char = input.size();
        *local_ref = nr_char;
        local_ref++;
        unused_bytes-=sizeof(int);
        char *local_char_ref = reinterpret_cast<char*>(local_ref);
        const char *temp_char = input.c_str();
        while(*temp_char != 0){
            *local_char_ref = *temp_char;
            local_char_ref++;
            temp_char++;
        }
        read_write_ref = reinterpret_cast<int*>(local_char_ref);
        unused_bytes-=sizeof(char)*nr_char;
        return *this;
    }
    DataStreamer& operator>>(string& output){
        int *local_ref = reinterpret_cast<int*>(read_write_ref);
        int nr_char = *local_ref;
        local_ref++;
        char *out = new char[nr_char];
        char *local_char_ref = reinterpret_cast<char*>(local_ref);
        for(int i=0;i<nr_char;i++){
            out[i] = *local_char_ref;
            local_char_ref++;
        }
        output = out;
        read_write_ref = reinterpret_cast<int*>(local_char_ref);
        delete[] out;
        return *this;
    }
    int print_unsued(){
        cout << "Total unused bytes: " << unused_bytes << endl;
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
    int a_in = 34;
    int b_in = 12;
    float c_in = 8.90;
    double d_in = 100.004;
    int e_in = 890;
    string f_in = "sample_input";
    char g_in = 'Q';
    double h_in = 26.01;
    DataStreamer ds;
    ds.init_num_bytes(1024);
    ds << a_in;
    ds.print_unsued();
    ds << b_in;
    ds.print_unsued();
    ds << c_in;
    ds.print_unsued();
    ds << d_in;
    ds.print_unsued();
    ds << e_in;
    ds.print_unsued();
    ds << f_in;
    ds.print_unsued();
    ds << g_in;
    ds.print_unsued();
    ds << h_in;
    ds.print_unsued();
    ds.init_read_mode();
    int a_out, b_out, e_out;
    float c_out;
    double d_out, h_out;
    char g_out;
    string f_out;
    ds >> a_out;
    cout << a_out << endl;
    ds >> b_out;
    cout << b_out << endl;
    ds >> c_out;
    cout << c_out << endl;
    ds >> d_out;
    cout << d_out << endl;
    ds >> e_out;
    cout << e_out << endl;
    ds >> f_out;
    cout << f_out << endl;
    ds >> g_out;
    cout << g_out << endl;
    ds >> h_out;
    cout << h_out << endl;
    return 0;
}
