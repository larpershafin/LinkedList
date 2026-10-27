cmake_minimum_required(VERSION 3.28)
project(untitled C)

set(CMAKE_C_STANDARD 11)

# 1. Bitwise Operators Programm
add_executable(BitwiseOperators
        BitwiseOperators/main.c
)

# 2. 2-Punkt-Regler Programm
add_executable(ZweiPunktRegler
        2PunktRegler/main.c
        2PunktRegler/2punktregler.c
)

# 3. Linked List Programm (Standardmäßig einfach verkettete Liste)
add_executable(LinkedLists
        linkedlist/main.c
        linkedlist/linkedlist.c
)

# Falls du stattdessen die doppelt verkettete Liste testen willst,
# tausche 'linkedlist.c' oben gegen 'doublelinkedlist.c' aus.