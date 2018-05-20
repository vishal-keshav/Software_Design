# Bazel build for data streamer test cases

cc_binary(
    name = "program",
    srcs = ["main.cpp"],
    copts = ["-Iinclude", "-Iexternal/gtest/include"],
    deps = [
        ":data_streamer",
        "@gtest//:main",
    ]
)

cc_library(
    name = "data_streamer",
    srcs = ["src/data_stream.cpp"],
    hdrs = ["include/data_stream.h"],
    copts = ["-Iinclude"],
    visibility = ["//visibility:public"],
)
