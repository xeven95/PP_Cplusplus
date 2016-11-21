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
    
    void addContenido(Contenido& cont);
    
private:
    std::map<std::string, std::vector<Contenido> >;
    
};

#endif	/* GESTOR_H */

