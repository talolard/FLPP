cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME mblights)
project(${PROJECT_NAME})
set(${CMAKE_PROJECT_NAME}_BOARD mega2560)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyACM0)

set(${CMAKE_PROJECT_NAME}_SKETCH mblights.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
