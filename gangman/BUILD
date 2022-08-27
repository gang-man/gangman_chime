# load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "gangman_test",
    srcs = ["gangman_test.cc"],
    deps = ["Tensor",
            "test"]
            # "sin_op"]

)

cc_library(
    name = "test",
    srcs = ["test.cc", "test.h"]
    # hrds = ["Tensor.h"]
    
)


cc_library(
    name = "Tensor",
    srcs = ["Tensor.cc","Tensor.h"]
    # hrds = ["Tensor.h"]
    
)


cc_library(
    name = "operator",
    srcs = ["operator.cc","operator.h"]
# #     hrds = ["operator.h"]
    
)

cc_library(
    name = "sin_op",
    srcs = ["sin_op.cc","sin_op.h"]
    # hrds = ["sin_op.h"]
)