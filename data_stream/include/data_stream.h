/*
 * Header for data streamer
 */

#include<iostream>
#include<string>

using namespace std;

 #ifndef data_stream_H
 #define data_stream_H

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
     void init_num_bytes(int nr_bytes);
     // At this time, streamer is required to
     // output byte data sequentially
     void init_read_mode(void);
     //Delete the memory chunk
     void clear_memory(){
         // dont invoke double free
         if(unused_bytes!=-1){
             unused_bytes = -1;
             delete [] data_ref;
         }
     }
     //Operator overloading, args passed by ref-value
     //[TO-DO] Reduce the source code with templates
     DataStreamer& operator<<(int &input);
     DataStreamer& operator>>(int& output);

     DataStreamer& operator<<(float &input);
     DataStreamer& operator>>(float& output);

     DataStreamer& operator<<(double &input);
     DataStreamer& operator>>(double& output);

     DataStreamer& operator<<(char &input);
     DataStreamer& operator>>(char& output);

     DataStreamer& operator<<(string &input);
     DataStreamer& operator>>(string& output);
     int print_unused(){
         return unused_bytes;
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

 #endif
