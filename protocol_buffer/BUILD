# Bazel build script for main programm

# proto_library rule requires com_google_protobuf to be defined
proto_library(
    name = "cost_proto",
    srcs = ["cost.proto"],
    deps = ["@com_google_protobuf//:timestamp_proto"],
)

# rule for generating proto.cc and proto.h
# com_google_protobuf_cc has to be defined
cc_proto_library(
    name = "cost_cc_proto",
    deps = [":cost_proto"],
)

# Main executable generation rule
cc_binary(
    name = "main_prog",
    srcs = ["main.cpp"],
    deps = [":cost_cc_proto"],
)
