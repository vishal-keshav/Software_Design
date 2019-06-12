load("//tensorflow:tensorflow.bzl", "tf_cc_binary")

tf_cc_binary(
    name = "inference_no_model",
    srcs = ["inference.cc"],
    deps = [
        "//tensorflow/cc:cc_ops",
        "//tensorflow/cc:client_session",
        "//tensorflow/core:tensorflow",
    ],
)
