/* 
 * File:   Gestor.h
 * Author: All-PC
 *
 * Created on 21 de noviembre de 2016, 0:30
 */

#ifndef GESTOR_H
#define	GESTOR_H

#include "Contenido.h"
#include "Episodio.h"
#include <vector>
#include <map>
#include <string>

class Gestor{
public:
    Gestor();
    virtual ~Gestor();
    
    void addContenido(Contenido* cont); //Add contenido principal
    void addContenido(std::string nserie, std::string ntemp);
    void addContenido(std::string nserie, std::string ntemp, Episodio& episodio);
    void addContenido(std::string nserie, Episodio& episodio);
    
    void removeContenido(std::string nombre);
    bool exist_contenido(std::string nombre);
    Contenido* encontrar_contenido(std::string nombre);
    std::vector<Contenido*>::iterator encontrar_contenido(std::vector<Contenido*> vector, Contenido* cont); //AÑADIR & A CONTENIDO PARA NO TRATAR COPIAS

    
    
    //Metodos secundarios para opciones extra
    void mostrar_contenido();
    int sizeContenido();
    void mostrarInfoGenero();
    
    
private:
    void addGenero(std::vector<std::string> genero, Contenido* cont);
    void removeGenero(std::vector<std::string> genero, Contenido* cont);
    
    std::map<std::string, std::vector<Contenido*> > contenido;
    std::map<std::string, std::vector<Contenido*> > generos;
    
};

#endif	/* GESTOR_H */

