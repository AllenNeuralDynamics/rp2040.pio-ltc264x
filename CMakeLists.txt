cmake_minimum_required(VERSION 3.13)

#add_definitions(-DDEBUG)

if(NOT DEFINED PICO_SDK_PATH)
    message(FATAL_ERROR
            "PICO_SDK_PATH was not specified.
             pico_sdk_init() must first be invoked.")
endif()

project(rp2040.pio-ltc264x)

# Use modern conventions like std::invoke
set(CMAKE_CXX_STANDARD 17)

add_library(pio_ltc264x
    src/pio_ltc264x.cpp
)

pico_generate_pio_header(pio_ltc264x
    ${CMAKE_CURRENT_LIST_DIR}/src/pio_ltc264x.pio
)

# Header file location exposed with target scope for external projects.
target_include_directories(pio_ltc264x PUBLIC inc)

target_link_libraries(pio_ltc264x hardware_pio hardware_dma pico_stdlib)

if(DEBUG)
    # UART stdio for printf.
    pico_enable_stdio_uart(pio_ltc264x 1)
endif()
