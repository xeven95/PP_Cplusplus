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
#include <memory>
#include "Episodio.h"

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
    
    virtual void addEpisodio(std::string ntemp, std::string nepi, int dur);
    virtual void addTemporada(std::string ntemp);
    
    virtual void removeTemporada(std::string ntemp);
    virtual void removeEpisodio(std::string nombre,std::string nepi);
    
    virtual std::shared_ptr<Episodio> buscarEpisodio (unsigned int n1,unsigned int n2);
    
private:
    std::string titulo, sinopsis;
    std::vector<std::string> genero;
    
};

#endif	/* CONTENIDO_H */

