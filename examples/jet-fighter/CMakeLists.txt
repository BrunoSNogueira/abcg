project(jet-fighter)
add_executable(${PROJECT_NAME} main.cpp openglwindow.cpp ship.cpp bullets.cpp health.cpp)
enable_abcg(${PROJECT_NAME})
