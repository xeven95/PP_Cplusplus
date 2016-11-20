/* 
 * File:   Serie.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 12:57
 */

#ifndef SERIE_H
#define	SERIE_H

#include "Contenido.h"
#include "Episodio.h"
#include <string>
#include <vector>
#include <map>

class Serie: public Contenido{
public:
    Serie(std::string tit,std::string sin, std::vector<std::string> gen, std::string nom_temp, std::vector<Episodio> episodios);
    virtual ~Serie();
    
    std::map<std::string,std::vector<Episodio> > getTemporadas() const;
    
private:
    std::map<std::string,std::vector<Episodio> > temporadas;

};

#endif	/* SERIE_H */

