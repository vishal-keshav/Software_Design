
#include "data_stream.h"
#include "gtest/gtest.h"

using namespace std;

TEST(ReadWriteTest, Test1){
    int in = 34, out;
    DataStreamer ds;
    ds.init_num_bytes(128);
    EXPECT_EQ(128, ds.print_unused());
    ds << in;
    EXPECT_EQ(124, ds.print_unused());
    ds.init_read_mode();
    ds >> out;
    EXPECT_EQ(in, out);
}

int main(int argc, char **argv){
    /*int a_in = 34;
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
    ds.print_unused();
    ds << b_in;
    ds.print_unused();
    ds << c_in;
    ds.print_unused();
    ds << d_in;
    ds.print_unused();
    ds << e_in;
    ds.print_unused();
    ds << f_in;
    ds.print_unused();
    ds << g_in;
    ds.print_unused();
    ds << h_in;
    ds.print_unused();
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
    cout << h_out << endl;*/
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
