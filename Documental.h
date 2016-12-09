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
#include <map>

class Documental: public Contenido{
public:    
    Documental(std::string tit,std::string sin, std::vector<std::string> gen);
    virtual ~Documental();

    std::map<std::string,std::shared_ptr<Episodio> > getEpisodios() const;
    virtual std::string getTipo();
    virtual void getInfo();
    virtual std::string getInfoString();
    virtual void addEpisodio(std::string ntemp, std::string nepi, int dur);
    virtual void removeTemporada(std::string ntemp);

    virtual std::shared_ptr<Episodio> buscarEpisodio (unsigned int n1,unsigned int n2);
    friend std::ostream& operator<< (std::ostream& stream, const std::shared_ptr<Contenido> cont);
    
private:
    std::map<std::string,std::shared_ptr<Episodio> > episodios;
    
};

#endif	/* DOCUMENTAL_H */

