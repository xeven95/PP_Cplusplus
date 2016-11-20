#include "Episodio.h"

Episodio::Episodio(std::string nom, unsigned int dur):
nombre(nom),duracion(dur) {
}

Episodio::~Episodio(){
}

Episodio::getNombre() const{
    return nombre;
}

Episodio::geteDuracion() const{
    return duracion;
}
