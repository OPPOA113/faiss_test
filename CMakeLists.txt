cmake_minimum_required(VERSION 2.8)

# test hz compare library time whit faiss
find_package(OpenCV REQUIRED)
project(myproject)
set(CMAKE_CXX_STANDARD 11)

set(INCLUDE_DIRS
        ./include
        /usr/local/include
        /usr/local/cuda/include
        )
set(LINKER_DIRS
        /usr/local/lib
        /usr/local/cuda/lib64
        )

include_directories(${INCLUDE_DIRS})
link_libraries(${LINKER_DIRS})

set(cpp_list ./src/5-Multiple-GPUs.cpp)
#aux_source_directory(./src cpp_list)

set(TEMP_LINKER "")
list(APPEND TEMP_LINKER /home/data/zem_pyw/lab_project/hz_faiss/myproject/lib/libhz_objectRetrival.so)
list(APPEND TEMP_LINKER /home/data/zem_pyw/lab_project/hz_faiss/myproject/lib/libopencv_core.so.2.4)


add_executable(myproject ${cpp_list})
target_link_libraries(myproject ${TEMP_LINKER} cudart faiss)#${OpenCV_LIBS}

