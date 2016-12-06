/* 
 * File:   Temporada.h
 * Author: All-PC
 *
 * Created on 25 de noviembre de 2016, 12:06
 */

#ifndef TEMPORADA_H
#define	TEMPORADA_H

#include "Episodio.h"
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <iostream>


class Temporada{
public:
    Temporada(std::string nombre);
    virtual ~Temporada();
    
    std::string getNombre() const;
    std::map<std::string, std::shared_ptr<Episodio> > getEpisodios();
    void addEpisodio (std::string nepi, int dur);
    void removeEpisodio (std::string nepi);
    
    std::string getInfoString();
    
    std::shared_ptr<Episodio> buscarEpisodio (unsigned int n1);
    
private:
    std::string nombre;
    std::map<std::string, std::shared_ptr<Episodio> > episodios;
    
};

#endif	/* TEMPORADA_H */

