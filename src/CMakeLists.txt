# write simple cmake file creating a library fast_peg_solitaire
#
cmake_minimum_required(VERSION 3.16)
project(fast_peg_solitaire VERSION 1.0 LANGUAGES CXX)

add_library(fast_peg_solitaire fast_peg_solitaire.cpp)
