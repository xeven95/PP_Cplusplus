/* 
 * File:   Serie.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 12:57
 */

#ifndef SERIE_H
#define	SERIE_H

#include "Contenido.h"
#include "Temporada.h"
#include <string>
#include <vector>
#include <map>

class Serie: public Contenido{
public:
    Serie(std::string tit,std::string sin, std::vector<std::string> gen);
    virtual ~Serie();
    
    std::map<std::string,std::vector<Temporada> > getTemporadas() const;
    int getNumCapitulos() ;
    void addNumCapitulos();
    virtual std::string getTipo();
    virtual void getInfo();
    
private:
    std::map<std::string,std::vector<Temporada> > temporadas;
    int numcapitulos;

};

#endif	/* SERIE_H */

