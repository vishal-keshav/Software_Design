
#include "data_stream.h"
#include "gtest/gtest.h"

using namespace std;

TEST(ReadWriteTest, Test1_INT){
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

TEST(ReadWriteTest, Test_FLOAT){
    float in = 107.77, out;
    DataStreamer ds;
    ds.init_num_bytes(128);
    EXPECT_EQ(128, ds.print_unused());
    ds << in;
    EXPECT_EQ(124, ds.print_unused());
    ds.init_read_mode();
    ds >> out;
    EXPECT_EQ(in, out);
}

TEST(ReadWriteTest, Test_DOUBLE){
    double in = 56.99986, out;
    DataStreamer ds;
    ds.init_num_bytes(128);
    EXPECT_EQ(128, ds.print_unused());
    ds << in;
    EXPECT_EQ(120, ds.print_unused());
    ds.init_read_mode();
    ds >> out;
    EXPECT_EQ(in, out);
}

TEST(ReadWriteTest, Test_CHAR){
    char in = 'V', out;
    DataStreamer ds;
    ds.init_num_bytes(128);
    EXPECT_EQ(128, ds.print_unused());
    ds << in;
    EXPECT_EQ(127, ds.print_unused());
    ds.init_read_mode();
    ds >> out;
    EXPECT_EQ(in, out);
}

TEST(ReadWriteTest, Test_STRING){
    string in = "Keshav", out;
    DataStreamer ds;
    ds.init_num_bytes(128);
    EXPECT_EQ(128, ds.print_unused());
    ds << in;
    EXPECT_EQ(118, ds.print_unused());
    ds.init_read_mode();
    ds >> out;
    EXPECT_EQ(in.size(), out.size());
    EXPECT_STREQ(in.c_str(), out.c_str());
}

TEST(ReadWriteTest, Test_ALL){
    int in_int1 = 47, out_int1;
    int in_int2 = 007, out_int2;
    string in_string1 = "Vishal", out_string1;
    string in_string2 = "Keshav", out_string2;
    float in_float = 1024.50, out_float;
    double in_double = 99.999, out_double;
    char in_char = 'x', out_char;
    DataStreamer ds;
    EXPECT_EQ(-1, ds.print_unused());
    ds.init_num_bytes(2048);
    EXPECT_EQ(2048, ds.print_unused());
    ds << in_string1;
    EXPECT_EQ(2038, ds.print_unused());
    ds << in_int1;
    EXPECT_EQ(2034, ds.print_unused());
    ds << in_double;
    EXPECT_EQ(2026, ds.print_unused());
    ds << in_int2;
    EXPECT_EQ(2022, ds.print_unused());
    ds << in_string2;
    EXPECT_EQ(2012, ds.print_unused());
    ds << in_char;
    EXPECT_EQ(2011, ds.print_unused());
    ds << in_float;
    EXPECT_EQ(2007, ds.print_unused());

    ds.init_read_mode();
    ds >> out_string1;
    ds >> out_int1;
    ds >> out_double;
    ds >> out_int2;
    ds >> out_string2;
    ds >> out_char;
    ds >> out_float;

    EXPECT_EQ(in_string1.size(), out_string1.size());
    EXPECT_STREQ(in_string1.c_str(), out_string1.c_str());
    EXPECT_EQ(in_int1, out_int1);
    EXPECT_EQ(in_double, out_double);
    EXPECT_EQ(in_int2, out_int2);
    EXPECT_EQ(in_string2.size(), out_string2.size());
    EXPECT_STREQ(in_string2.c_str(), out_string2.c_str());
    EXPECT_EQ(in_char, out_char);
    EXPECT_EQ(in_float, out_float);
    ds.clear_memory();
    EXPECT_EQ(-1, ds.print_unused());
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
