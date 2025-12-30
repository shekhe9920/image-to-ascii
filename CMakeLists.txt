cmake_minimum_required(VERSION 3.10)
project(image_to_ascii C)

set(CMAKE_C_STANDARD 11)

add_executable(image_to_ascii
        src/main.c
        src/grayscale.c
        src/convolution.c
        include/ascii.h
        include/image.h
)

target_include_directories(image_to_ascii PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(image_to_ascii m)

