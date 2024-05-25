


set(PROJECT_NAME physics)

project(${PROJECT_NAME})



add_executable(${PROJECT_NAME} main.cpp ball.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)