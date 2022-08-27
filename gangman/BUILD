# load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "gangman_test",
    srcs = ["gangman_test.cc"],
    deps = ["lib"]
    

)

cc_library(
    name = "lib",
    srcs = ["operator.cc",
            "sin_op.cc",
            "Tensor.cc",
            "test.cc",
            "operator.h",
            "Tensor.h",
            "test.h",
            "sin_op.h"]
)
