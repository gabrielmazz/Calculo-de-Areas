#include "extras.hpp"
#include <iostream>

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

void clear_screen(void){
    //Comando para os dois sistemas "apagarem a tela"
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif
}

void stop_time(int tempo){
    #ifdef __linux__
        sleep(tempo);
    #elif WIN32
        Sleep(tempo);
    #else
    #endif
}

void stop(void){
    fflush(stdin);
    printf("\nPressione qualquer tecla para continuar. . ."); 
    fflush(stdin);
    getchar();
}