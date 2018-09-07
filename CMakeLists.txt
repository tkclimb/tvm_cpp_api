cmake_minimum_required(VERSION 3.1)
project(tvm_cpp_api)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TVM_PATH $ENV{TVM_PATH})
set(TVM_BUILD_PATH ${TVM_PATH}/build)
include_directories(${TVM_PATH}/include
                    ${TVM_PATH}/nnvm/include
                    ${TVM_PATH}/nnvm/topi/include
                    ${TVM_PATH}/HalideIR/src
                    ${TVM_PATH}/dlpack/include
                    ${TVM_PATH}/dmlc-core/include)
link_directories(${TVM_BUILD_PATH})
link_libraries(tvm)
# link_libraries(tvm nnvm_compiler tvm_runtime vta tvm_topi)
# add_compile_options(-Wl,-rpath,${TVM_BUILD_PATH})


add_executable(test test.cc)



