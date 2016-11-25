#include "Contenido.h"

Contenido::Contenido(){
    
}

Contenido::Contenido(std::string tit, std::string sin, std::vector<std::string> gen):
titulo(tit),sinopsis(sin),genero(gen) {
}

Contenido::~Contenido(){
}

std::string Contenido::getTitulo() const{
    return titulo;
}

std::string Contenido::getSinopsis() const{
    return sinopsis;
}

std::vector<std::string> Contenido::getGenero() const{
    return genero;
}

std::string Contenido::getTipo(){
    return "mal";
}

void Contenido::getInfo(){
    std::cout << "----" << '\n';
}
