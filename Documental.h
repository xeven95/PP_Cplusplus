/* 
 * File:   Documental.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 23:57
 */

#ifndef DOCUMENTAL_H
#define	DOCUMENTAL_H

#include "Contenido.h"
#include "Episodio.h"
#include <vector>

class Documental: public Contenido{
public:    
    Documental(std::string tit,std::string sin, std::vector<std::string> gen, std::vector<Episodio> episodios);
    virtual ~Documental();

    std::vector<Episodio> getEpisodios() const;
    
private:
    std::vector<Episodio> episodios;
    
};

#endif	/* DOCUMENTAL_H */

