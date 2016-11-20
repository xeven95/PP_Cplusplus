#include "Documental.h"

Documental::Documental(std::string tit, std::string sin, std::vector<std::string> gen, std::vector<Episodio> episodios)
:Contenido(tit,sin,gen), episodios(episodios){
    
}

Documental::~Documental(){
    
}

Documental::getEpisodios() const{
    return episodios;
}
