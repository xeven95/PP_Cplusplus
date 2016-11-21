#include "Serie.h"

Serie::Serie(std::string tit, std::string sin, std::vector<std::string> gen, std::string nom_temp, std::vector<Episodio> episodios)
:Contenido(tit,sin,gen){
    std::pair<std::string, std::vector<Episodio> > entry(nom_temp, episodios);
    temporadas.insert(entry);
}

Serie::~Serie(){
    
}

std::map<std::string,std::vector<Episodio> > Serie::getTemporadas() const{
    return temporadas;
}
