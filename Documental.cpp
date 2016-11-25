#include "Documental.h"

Documental::Documental(std::string tit, std::string sin, std::vector<std::string> gen)
:Contenido(tit,sin,gen){
    
}

Documental::~Documental(){
    
}

std::map<std::string,std::vector<Episodio> > Documental::getEpisodios() const{
    return episodios;
}

std::string Documental::getTipo(){
    return "documental";
}

void Documental::getInfo(){
    std::cout << "Documental - " << this->getTitulo();
    std::cout << " Episodios: " << this->episodios.size() << '\n';
}