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

#include <map>

class Serie: public Contenido{
public:
    Serie(std::string tit,std::string sin, std::vector<std::string> gen);
    virtual ~Serie();
    
    std::map<std::string,std::shared_ptr<Temporada> > getTemporadas() const;
    virtual void addTemporada(std::string ntemp);
    virtual void addEpisodio(std::string ntemp, std::string nepi, int dur);
    int getNumCapitulos() ;
    void addNumCapitulos();
    virtual std::string getTipo();
    virtual void getInfo();
    virtual std::string getInfoString();
    
    virtual void removeTemporada(std::string ntemp);
    virtual void removeEpisodio(std::string nombre,std::string nepi);
    
    virtual std::shared_ptr<Episodio> buscarEpisodio (unsigned int n1,unsigned int n2);

    
    private:
    std::map<std::string,std::shared_ptr<Temporada> > temporadas;
    int numcapitulos;

};

#endif	/* SERIE_H */

