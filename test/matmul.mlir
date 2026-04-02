func.func @matmul_test(%lhs: tensor<4x4xf32>, %rhs: tensor<4x4xf32>) -> tensor<4x4xf32> {
    %result = tlow.matmul %lhs, %rhs : tensor<4x4xf32>, tensor<4x4xf32> -> tensor<4x4xf32>
    return %result : tensor<4x4xf32>
}