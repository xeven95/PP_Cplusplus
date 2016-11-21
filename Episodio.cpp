#include "./Episodio.h"

Episodio::Episodio(std::string nom, unsigned int dur):
nombre(nom),duracion(dur) {
}

Episodio::~Episodio(){
}

std::string Episodio::getNombre() const{
    return nombre;
}

unsigned int Episodio::getDuracion() const{
    return duracion;
}