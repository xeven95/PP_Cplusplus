#include "Documental.h"

Documental::Documental(std::string tit, std::string sin, std::vector<std::string> gen)
:Contenido(tit,sin,gen){
    
}

Documental::~Documental(){
    
}

std::map<std::string,std::shared_ptr<Episodio> > Documental::getEpisodios() const{
    return episodios;
}

std::string Documental::getTipo(){
    return "documental";
}

void Documental::getInfo(){
    std::cout << "Documental - " << this->getTitulo();
    std::cout << " Episodios: " << this->episodios.size() << '\n';
}

void Documental::addEpisodio(std::string ntemp, std::string nepi, int dur){
    if (episodios.count(nepi)==0){
        episodios[nepi].reset(new Episodio(nepi,dur));
        std::cout << "Ha sido añadido "<< nepi << '\n';
    } else {
        std::cout << "Ya existe un episodio llamado "<< nepi << '\n';
    }
}
void Documental::removeTemporada(std::string ntemp){
    if (episodios.count(ntemp)==1){
        episodios.erase(ntemp);
        std::cout << "Ha sido eliminado "<< ntemp << '\n';
    } else {
        std::cout << "No ha sido encontra el documental "<< ntemp << '\n';
    }
}