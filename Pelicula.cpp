#include "Pelicula.h"

Pelicula::Pelicula(std::string tit, std::string sin, std::vector<std::string> gen, unsigned int dur):
Contenido(tit,sin,gen), duracion(dur){
}

Pelicula::~Pelicula(){
}

unsigned int Pelicula::getDuracion() const{
    return duracion;
}