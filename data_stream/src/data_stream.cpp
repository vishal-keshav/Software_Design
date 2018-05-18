/*
 * Source for data-streamer
 */
#include "data_stream.h"

void DataStreamer::init_num_bytes(int nr_bytes){
    if(nr_bytes!=0){
        clear_memory();
    }
    total_bytes = nr_bytes;
    unused_bytes = nr_bytes;
    // An integer is of 4 bytes
    data_ref = new int[nr_bytes/4];
    read_write_ref = data_ref;
}

void DataStreamer::init_read_mode(void){
    read_write_ref = data_ref;
}

//Operator overloading(INT), args passed by ref-value
DataStreamer& DataStreamer::operator<<(int &input){
    int *local_ref = (int*)read_write_ref;
    *local_ref = input;
    local_ref++;
    read_write_ref = local_ref;
    unused_bytes-=sizeof(int);
    return *this;
}
DataStreamer& DataStreamer::operator>>(int& output){
    int *local_ref = (int*)read_write_ref;
    output = *local_ref;
    local_ref++;
    read_write_ref = local_ref;
    return *this;
}
//Operator overloading(FLOAT), args passed by ref-value
DataStreamer& DataStreamer::operator<<(float &input){
    float *local_ref = reinterpret_cast<float*>(read_write_ref);
    *local_ref = input;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    unused_bytes-=sizeof(float);
    return *this;
}
DataStreamer& DataStreamer::operator>>(float& output){
    float *local_ref = reinterpret_cast<float*>(read_write_ref);
    output = *local_ref;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    return *this;
}
//Operator overloading(DOUBLE), args passed by ref-value
DataStreamer& DataStreamer::operator<<(double &input){
    double *local_ref = reinterpret_cast<double*>(read_write_ref);
    *local_ref = input;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    unused_bytes-=sizeof(double);
    return *this;
}
DataStreamer& DataStreamer::operator>>(double& output){
    double *local_ref = reinterpret_cast<double*>(read_write_ref);
    output = *local_ref;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    return *this;
}
//Operator overloading(CHAR), args passed by ref-value
DataStreamer& DataStreamer::operator<<(char &input){
    char *local_ref = reinterpret_cast<char*>(read_write_ref);
    *local_ref = input;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    unused_bytes-=sizeof(char);
    return *this;
}
DataStreamer& DataStreamer::operator>>(char& output){
    char *local_ref = reinterpret_cast<char*>(read_write_ref);
    output = *local_ref;
    local_ref++;
    read_write_ref = reinterpret_cast<int*>(local_ref);
    return *this;
}
//Operator overloading(CHAR), args passed by ref-value
DataStreamer& DataStreamer::operator<<(string &input){
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
DataStreamer& DataStreamer::operator>>(string& output){
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
