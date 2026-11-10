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

# 3. Linked List Programm
add_executable(LinkedLists
        linkedlist/main.c
        linkedlist/linkedlist.c
)

# 4. PID-Regler Programm
add_executable(PIDRegler
        PIDRegler/main.c
        PIDRegler/pidregler.c
)