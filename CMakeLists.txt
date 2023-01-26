cmake_minimum_required(VERSION 3.21)
project(3D_Curves)

set(CMAKE_CXX_STANDARD 14)

add_executable(3D_Curves main.cpp Curve.cpp Curve.h Circle.cpp Circle.h Elips.cpp Elips.h Helixe.cpp Helixe.h)
