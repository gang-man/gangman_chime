# load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "gangman_test",
    srcs = ["gangman_test.cc"],
    deps = ["Tensor",
            "Operator"]

)


cc_library(
    name = "Tensor",
    srcs = ["Tensor.cc"],
    hdrs = ["Tensor.h"]
    
)

cc_library(
    name = "Operator",
    srcs = ["Operator.cc"],
    hdrs = ["Operator.h"]
)