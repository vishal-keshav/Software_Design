
#include "data_stream.h"

using namespace std;

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
