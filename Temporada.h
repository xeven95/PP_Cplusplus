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
#include <string>

class Temporada{
public:
    Temporada(std::string nombre);
    virtual ~Temporada();
    
    std::string getNombre() const;
    std::map<std::string, std::vector<Episodio> > getEpisodios();
    
private:
    std::string nombre;
    std::map<std::string, std::vector<Episodio> > episodios;
    
};

#endif	/* TEMPORADA_H */

