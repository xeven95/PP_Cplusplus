/* 
 * File:   Episodio.h
 * Author: All-PC
 *
 * Created on 20 de noviembre de 2016, 13:02
 */

#ifndef EPISODIO_H
#define	EPISODIO_H

#include <string>
#include "tostring.h"

class Episodio {
public:
    Episodio(std::string nom, unsigned int dur);
    virtual ~Episodio();
    
    std::string getNombre() const;
    unsigned int getDuracion() const;
    std::string getInfoString();
private:
    std::string nombre;
    unsigned int duracion;
};

#endif	/* EPISODIO_H */

