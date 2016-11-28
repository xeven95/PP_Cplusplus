#include "Temporada.h"

Temporada::Temporada(std::string nombre): nombre(nombre){
}

Temporada::~Temporada(){
    
}

std::string Temporada::getNombre() const{
    return nombre;
}

std::map<std::string, std::vector<Episodio> > Temporada::getEpisodios(){
    return episodios;
}
