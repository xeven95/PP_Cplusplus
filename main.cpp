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
    auxgen4.push_back("drama");
    auxgen4.push_back("comedia");
    auxgen4.push_back("accion");
    std::vector<std::string> auxgen5;
    auxgen5.push_back("miedo");

    Gestor gestor;
    
    std::shared_ptr<Contenido> elem (new Pelicula("Pelicula1","sinopsis",auxgen,60));
    gestor.addContenido(elem);
    elem.reset(new Pelicula("Pelicula2","sinopsis",auxgen5,55));
    gestor.addContenido(elem);

    
    elem.reset(new Serie ("Serie1","sinopsis de serie",auxgen2));
    gestor.addContenido(elem);
    elem.reset(new Serie ("Serie2","sinopsis de serie",auxgen4));
    gestor.addContenido(elem);

    elem.reset(new Documental ("Documental1","sinopsis de documental",auxgen4));
    gestor.addContenido(elem);
    elem.reset(new Documental ("Documental2","sinopsis de documental",auxgen));
    gestor.addContenido(elem);
    elem.reset(new Documental ("Documental3","sinopsis de documental",auxgen5   ));
    gestor.addContenido(elem);
    
    
    //elem.reset(new Serie ("Serie1","sinopsis de serie",auxgen2));
    //gestor.addContenido(elem);
    
    //gestor.removeContenido("Serie2");
    gestor.addContenido("Serie1","pepe");
    gestor.addContenido("Serie1","pepe","cap1",10);
    //gestor.removeContenido("Serie1","pepe");
    gestor.addContenido("Documental1","pepe",5);
    //gestor.removeContenido("Documental1","pepe");
    
    
    std::cout << "--CONTENIDO--" << '\n';
    gestor.mostrar_contenido();
    std::cout << "--GENEROS--" << '\n';    
    gestor.mostrarInfoGenero();;
    std::cout << "--CONSULTAS--" << '\n';
    std::cout << "- Consulta de Contenido por nombre:" << '\n';
    gestor.buscarContenidoNombre("Serie1");
    std::cout << "- Consulta de Contenido por genero:" << '\n';
    gestor.buscarGeneros(auxgen4);
    std::cout << "- Consultas de Episodio de una serie y documental:" << '\n';
    gestor.buscarContenidoporNumero("Serie1",1,1);
    gestor.buscarContenidoporNumero("Documental1",1);
    gestor.guardarfichero();
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
