/* 
 * File:   Contenido.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 11:34
 */

#ifndef CONTENIDO_H
#define	CONTENIDO_H

#include <string>
#include <vector>
#include <iostream>

class Contenido{
public:
    Contenido();
    Contenido(std::string tit,std::string sin, std::vector<std::string> gen);
    virtual ~Contenido();
    
    std::string getTitulo() const;
    std::string getSinopsis() const;
    std::vector<std::string> getGenero() const;
    virtual std::string getTipo() ;
    virtual void getInfo();
    
private:
    std::string titulo, sinopsis;
    std::vector<std::string> genero;
    
};

#endif	/* CONTENIDO_H */

