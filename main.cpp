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
#include "Gestor.h"
#include "Pelicula.h"
#include "Documental.h"
#include "Serie.h"
#include "Episodio.h"
#include "Temporada.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char opc;
    std::vector<std::string> auxgen;
    auxgen.push_back("accion");
    std::vector<std::string> auxgen2;
    auxgen2.push_back("comedia");
    auxgen2.push_back("drama");
    std::vector<std::string> auxgen4;
    auxgen4.push_back("accion");
    auxgen4.push_back("comedia");
    auxgen4.push_back("aventura");
    std::vector<std::string> auxgen5;
    auxgen5.push_back("miedo");
    
   
    Gestor gestor;

    Pelicula p("Pelicula1","sinopsis",auxgen,60);
    Pelicula p2("Pelicula2","sinopsis",auxgen5,55);
    Pelicula p3("Pelicula3","sinopsis",auxgen4,119);
    Serie s("Serie1","sinopsis de serie",auxgen2);
    Serie s2("Serie2","sinopsis de serie",auxgen);
    Documental d("Documental1","sinopsis de documental",auxgen4);
    Documental d2("Documental2","sinopsis de documental",auxgen);
    Documental d3("Documental3","sinopsis de documental",auxgen5);
    

    Contenido * puntero = &p;
    gestor.addContenido(puntero);
    puntero = &s;
    gestor.addContenido(puntero);
    puntero = &d;
    gestor.addContenido(puntero);
    puntero = &p2;
    gestor.addContenido(puntero);
    puntero = &p3;
    gestor.addContenido(puntero);
    puntero = &s2;
    gestor.addContenido(puntero);
    puntero = &d2;
    gestor.addContenido(puntero);
    puntero = &d3;
    gestor.addContenido(puntero);


    gestor.removeContenido("Serie1");
    std::cout << "--CONTENIDO--" << '\n';
    gestor.mostrar_contenido();
    std::cout << "----" << '\n';
    std::cout << "--GENEROS--" << '\n';    
    gestor.mostrarInfoGenero();
    std::cout << "----" << '\n';
    
    return 0;
    /*
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
    */
}
