cmake_minimum_required(VERSION 3.23)
project(console_roguelike_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(console_roguelike_cpp main.cpp Utility.cpp Utility.h LevelDesign.cpp LevelDesign.h UserInterface.cpp UserInterface.h AnimationAndSprites.cpp AnimationAndSprites.h Character.cpp Character.h PlayerItems.cpp PlayerItems.h TextQuest.cpp TextQuest.h)
