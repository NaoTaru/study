cmake_minimum_required(VERSION 2.8)

project(led_toggle C)

add_executable(led_toggle
	src/led.c
)

target_include_directories(led_toggle PRIVATE ./inc)

target_compile_options(led_toggle PRIVATE -g3)
target_compile_options(led_toggle PRIVATE -O0)

# ライブラリの参照パスを設定
link_directories(${SYSROOT_PREFIX}/lib)

# インクルードの参照パスを設定
include_directories(${SYSROOT_PREFIX}/usr/include)

