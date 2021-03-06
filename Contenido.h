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
#include "tostring.h"

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
    virtual std::string getInfoString();
    std::string getGeneroString();
    
protected:
    virtual void addEpisodio(std::string ntemp, std::string nepi, int dur);
    virtual void addTemporada(std::string ntemp);
    
    virtual void removeTemporada(std::string ntemp);
    virtual void removeEpisodio(std::string nombre,std::string nepi);
    
    virtual std::shared_ptr<Episodio> buscarEpisodio (unsigned int n1,unsigned int n2);
    friend std::ostream& operator<< (std::ostream& stream, const std::shared_ptr<Contenido>& cont);
    
    friend class Gestor;
    friend class Pelicula;
    friend class Documental;
    friend class Serie;
    
private:
    std::string titulo, sinopsis;
    std::vector<std::string> genero;
    
};

#endif	/* CONTENIDO_H */

