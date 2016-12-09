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
    std::vector<std::string> auxgen3;
    auxgen3.push_back("aventura");
    auxgen3.push_back("accion");
    std::vector<std::string> auxgen4;
    auxgen4.push_back("drama");
    auxgen4.push_back("comedia");
    auxgen4.push_back("accion");
    std::vector<std::string> auxgen5;
    auxgen5.push_back("miedo");

    Gestor gestor;
    
    std::shared_ptr<Contenido> elem (new Pelicula("Pelicula1","Erase una vez...",auxgen,60));
    gestor.addContenido(elem);
    elem.reset(new Pelicula("Pelicula2","Erase una vez...",auxgen5,55));
    gestor.addContenido(elem);
    elem.reset(new Pelicula("Pelicula3","Erase una vez...",auxgen3,85));
    gestor.addContenido(elem);
    elem.reset(new Pelicula("Pelicula4","Erase una vez...",auxgen4,210));
    gestor.addContenido(elem);
    elem.reset(new Pelicula("Pelicula5","Erase una vez...",auxgen2,154));
    gestor.addContenido(elem);

    
    elem.reset(new Serie ("Serie1","Hace mucho tiempo...",auxgen2));
    gestor.addContenido(elem);
    gestor.addContenido("Serie1",1);
    gestor.addContenido("Serie1",3);
    gestor.addContenido("Serie1",2);
    gestor.addContenido("Serie1",1,"cap1",10);
    gestor.addContenido("Serie1",1,"cap2",12);
    gestor.addContenido("Serie1",1,"cap3",11);
    gestor.addContenido("Serie1",2,"cap1",15);
    elem.reset(new Serie ("Serie2","Hace mucho tiempo...",auxgen4));
    gestor.addContenido(elem);
    elem.reset(new Serie ("Serie3","Hace mucho tiempo...",auxgen));
    gestor.addContenido(elem);
    elem.reset(new Serie ("Serie4","Hace mucho tiempo...",auxgen3));
    gestor.addContenido(elem);

    elem.reset(new Documental ("Documental1","En un lugar muy lejano...",auxgen4));
    gestor.addContenido(elem);
    gestor.addContenido("Documental1","Capitulo1",5);
    gestor.addContenido("Documental1","Capitulo2",5);
    gestor.addContenido("Documental1","Capitulo3",5);
    elem.reset(new Documental ("Documental2","En un lugar muy lejano...",auxgen));
    gestor.addContenido(elem);
    elem.reset(new Documental ("Documental3","En un lugar muy lejano...",auxgen5));
    gestor.addContenido(elem);
    
    
    gestor.removeContenido("Serie2");
    gestor.removeContenido("Serie1",3);
    
    gestor.removeContenido("Documental1","pepe");
    gestor.removeContenido("Documental1","Capitulo2");
    
    
    std::cout << "--CONTENIDO--" << '\n';
    gestor.mostrar_contenido();
    std::cout << "--GENEROS--" << '\n';    
    gestor.mostrarInfoGenero();;
    std::cout << "--CONSULTAS--" << '\n';
    std::cout << "- Consulta de Contenido por nombre:" << '\n';
    gestor.buscarContenidoNombre("Serie1");
    std::cout << "- Consulta de Contenido por genero:" << '\n';
    gestor.buscarGeneros(auxgen);
    std::cout << "- Consultas de Episodio de una serie y documental:" << '\n';
    gestor.buscarContenidoporNumero("Serie1",1,2);
    gestor.buscarContenidoporNumero("Documental1",1);
    gestor.guardarfichero();
    return 0;
    
}
