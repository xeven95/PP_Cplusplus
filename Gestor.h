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
#include <memory>

class Gestor{
public:
    Gestor();
    virtual ~Gestor();
    
    void addContenido(std::shared_ptr<Contenido> cont); //Add contenido principal
    void addContenido(std::string nserie, std::string ntemp);
    void addContenido(std::string nserie, std::string ntemp, Episodio& episodio);
    void addContenido(std::string nserie, Episodio& episodio);
    
    void removeContenido(std::string nombre);
    bool exist_contenido(std::string nombre);
    std::shared_ptr<Contenido> encontrar_contenido(std::string nombre);
    std::vector<std::shared_ptr<Contenido>>::iterator encontrar_contenido(std::vector<std::shared_ptr<Contenido>> vector, std::shared_ptr<Contenido> cont); //AÑADIR & A CONTENIDO PARA NO TRATAR COPIAS

    
    
    //Metodos secundarios para opciones extra
    void mostrar_contenido();
    int sizeContenido();
    void mostrarInfoGenero();
    
    
private:
    void addGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont);
    void removeGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont);
    
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> > contenido;
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> > generos;
    
};

#endif	/* GESTOR_H */

