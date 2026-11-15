cmake_minimum_required(VERSION 3.16)
project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
  factory_design_pattern
  Creational_pattern/Factory_Pattern/Factory_Design_Pattern.cpp
)
add_executable(
  payment_factory_design_pattern
  Creational_pattern/Factory_Pattern/Payment_Factory_Design_Pattern.cpp
)
