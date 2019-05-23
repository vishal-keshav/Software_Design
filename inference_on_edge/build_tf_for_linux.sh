#!/usr/bin/env bash

echo "Building tensorflow library for linux"
echo "Please ensure that this is executed from tensorflow directory"

bazel build //tensorflow/c:c_api
