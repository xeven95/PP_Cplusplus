#include "Serie.h"

Serie::Serie(std::string tit, std::string sin, std::vector<std::string> gen)
:Contenido(tit,sin,gen),numcapitulos(0){
    
}

Serie::~Serie(){
    
}

std::map<std::string,std::vector<Temporada> > Serie::getTemporadas() const{
    return temporadas;
}

std::string Serie::getTipo(){
    return "serie";
}

void Serie::getInfo(){
    std::cout << "Serie - " << this->getTitulo();
    std::cout << " Temporadas: " << this->getTemporadas().size();
    std::cout << " Episodios: " << this->getNumCapitulos() << '\n';
            
}

int Serie::getNumCapitulos() {
    return numcapitulos;
}

void Serie::addNumCapitulos(){
    numcapitulos = numcapitulos + 1;
}