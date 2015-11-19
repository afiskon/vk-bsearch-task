cmake_minimum_required(VERSION 2.8)

project(vk_bsearch_task)

add_executable(bsearch bsearch.c)

set_property(TARGET bsearch PROPERTY C_STANDARD 99)