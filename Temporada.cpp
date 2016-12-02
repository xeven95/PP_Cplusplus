#include "Temporada.h"

Temporada::Temporada(std::string nombre): nombre(nombre){
}

Temporada::~Temporada(){
    
}

std::string Temporada::getNombre() const{
    return nombre;
}

std::map<std::string, std::shared_ptr<Episodio> > Temporada::getEpisodios(){
    return episodios;
}

void Temporada::addEpisodio (std::string nepi, int dur){
    if (episodios.count(nepi)==0){
        episodios[nepi].reset(new Episodio (nepi,dur));
    } else {
        std::cout << "Ya existe el episodio " << nepi << '\n';
    }
}
void Temporada::removeEpisodio(std::string nepi){
    if (episodios.count(nepi)==1){
        episodios.erase(nepi);
    } else {
        std::cout << "No existe el episodio " << nepi << '\n';
    }
}
std::shared_ptr<Episodio> Temporada::buscarEpisodio (unsigned int n1){
    std::shared_ptr<Episodio> epi;
    std::map<std::string, std::shared_ptr<Episodio> >::iterator it = episodios.begin();
    if (n1<=episodios.size()){
        std::advance(it,n1-1);
        epi = episodios[it->first];
    } else {
        std::cout << "No hay tantos episodios." << '\n';
    }
    return epi;
}