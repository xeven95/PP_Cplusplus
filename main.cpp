/* 
 * File:   main.cpp
 * Author: All-PC
 *
 * Created on 19 de noviembre de 2016, 20:26
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
 * 
 */
int main(int argc, char** argv) {
    char opc;
    
    do{
        std::cout << "Elija una opcion" <<'\n';
        std::cout << "1) Mostrar Peliculas, Series y Documentales." <<'\n';
        std::cout << "2) Consultar una pelicula, serie o documental." <<'\n';
        std::cout << "3) Consultar un episodio de una serie." <<'\n';
        std::cout << "4) Consultar un episodio de un documental." <<'\n';
        std::cout << "5) Consultar un elemento por genero o generos." <<'\n';
        std::cout << "6) Salir." <<'\n';
        std::cin >> opc;
        std::cout << opc <<'\n';
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                return 0;
                break;
            default:
                std::cout << "Elija una opcion valida." << '\n';
        }
    }while (opc!='f');    
    
}
