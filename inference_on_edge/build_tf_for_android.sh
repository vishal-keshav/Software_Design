#!/usr/bin/env bash

echo "Building tensorflow library for android"

export ANDROID_NDK_HOME=/home/user/android_tools/android-ndk-r19

export ANDROID_SDK_HOME=/home/user/android_tools/Sdk

export ANDROID_HOME=/home/user/android_tools/Sdk

echo "Please ensure that this is executed from tensorflow directory"

bazel build //tensorflow/c:c_api --crosstool_top=//external:android/crosstool \
   --host_crosstool_top=@bazel_tools//tools/cpp:toolchain --cpu=armeabi-v7a
