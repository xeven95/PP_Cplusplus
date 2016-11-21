/* 
 * File:   Gestor.h
 * Author: All-PC
 *
 * Created on 21 de noviembre de 2016, 0:30
 */

#ifndef GESTOR_H
#define	GESTOR_H

#include "Contenido.h"
#include <vector>
#include <map>
#include <string>

class Gestor{
public:
    Gestor();
    virtual ~Gestor();
    
    void addContenido(std::string tipo,Contenido& cont);
    void removeContenido(std::string nombre);
    bool exist_contenido(std::string nombre);
    
    //Metodos secundarios para opciones extra
    void mostrar_contenido(std::string nombre);
    int size();
    
    
private:
    std::map<std::string, std::vector<Contenido> > contenido;
    
};

#endif	/* GESTOR_H */

