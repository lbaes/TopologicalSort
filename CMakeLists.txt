cmake_minimum_required(VERSION 3.10)

# Projeto
project(GrafoPert VERSION 1.0)

# executavel
add_executable(GrafoPert main.c grafo.c linked_list.c pert.c)

# padrao c11
set(CMAKE_C_STANDARD 11)






