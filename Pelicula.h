/* 
 * File:   Pelicula.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 11:50
 */

#ifndef PELICULA_H
#define	PELICULA_H

#include "Contenido.h"
#include <string>

class Pelicula: public Contenido {
public:
    Pelicula();
    Pelicula(std::string tit,std::string sin, std::vector<std::string> gen, unsigned int dur);
    virtual ~Pelicula();
    
    unsigned int getDuracion() const;
    virtual std::string getTipo();
    virtual void getInfo();
    
private:
    unsigned int duracion;
};

#endif	/* PELICULA_H */

