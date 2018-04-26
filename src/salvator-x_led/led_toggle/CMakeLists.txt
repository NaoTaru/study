cmake_minimum_required(VERSION 2.8)

project(led_toggle C)

add_executable(led_toggle
	src/led.c
)

target_include_directories(led_toggle PRIVATE ./inc)

target_compile_options(led_toggle PRIVATE -g3)
target_compile_options(led_toggle PRIVATE -O0)

#link_directories(${CMAKE_INSTALL_PREFIX}/lib)
#target_link_libraries(led_toggle sifutil)
#target_link_libraries(led_toggle sifutil)

