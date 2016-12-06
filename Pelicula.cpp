#include "Pelicula.h"

Pelicula::Pelicula(){
}

Pelicula::Pelicula(std::string tit, std::string sin, std::vector<std::string> gen, unsigned int dur):
Contenido(tit,sin,gen), duracion(dur){
}

Pelicula::~Pelicula(){
}

unsigned int Pelicula::getDuracion() const{
    return duracion;
}

std::string Pelicula::getTipo(){
    return "pelicula";
}

void Pelicula::getInfo(){
    std::cout << "Pelicula - " << this->getTitulo();
    std::cout << " Duración: " << this->getDuracion() << '\n';
}
std::string Pelicula::getInfoString(){
    std::string aux= this->getTitulo() + " Duración: " + to_string(this->getDuracion()) + " Genero: " + this->getGeneroString() + '\n';
    return aux;
}