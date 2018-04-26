cmake_minimum_required(VERSION 2.8)

project(salvator-x_led)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wconversion)

# 事前に${SYSROOT_PREFIX}には、yocto_sdk/2.4.1/sysroots/aarch64-poky-linux を設定しておく。

# ライブラリの参照パスを設定
link_directories(${SYSROOT_PREFIX}/lib)

# インクルードの参照パスを設定
include_directories(${SYSROOT_PREFIX}/usr/include)

# サブディレクトリ指定
add_subdirectory(led_toggle)

