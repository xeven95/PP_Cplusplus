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
std::string Documental::getInfoString(){
    std::map<std::string, std::shared_ptr<Episodio> >::iterator it;
    std::string aux= this->getTitulo() + " Generos: " + this->getGeneroString() + " Episodios: " + to_string(this->episodios.size()) + '\n';
    aux = aux + "    Episodios: ";
    for(it=episodios.begin();it!=episodios.end();it++){
        aux = aux + it->first + "";
    }
    aux = aux + '\n';
    return aux;
}
void Documental::addEpisodio(std::string ntemp, std::string nepi, int dur){
    if (episodios.count(nepi)==0){
        episodios[nepi].reset(new Episodio(nepi,dur));
        std::cout << "Ha sido añadido el episodio llamado "<< nepi << '\n';
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
std::shared_ptr<Episodio> Documental::buscarEpisodio(unsigned int n1, unsigned int n2){
    std::shared_ptr<Episodio> cont;
    std::map<std::string, std::shared_ptr<Episodio> >::iterator it = episodios.begin();
    if (n1 <= episodios.size()){
        std::advance(it,n1-1);
        cont = episodios[it->first];
    } else {
        std::cout << "No hay tantos capitulos" << '\n';
    }
    return cont;
}