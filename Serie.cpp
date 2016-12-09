#include "Serie.h"

Serie::Serie(std::string tit, std::string sin, std::vector<std::string> gen)
:Contenido(tit,sin,gen),numcapitulos(0){
    
}

Serie::~Serie(){
    temporadas.clear();
}

std::map<std::string,std::shared_ptr<Temporada> > Serie::getTemporadas() const{
    return temporadas;
}

std::string Serie::getTipo(){
    return "serie";
}

void Serie::getInfo(){
    std::cout << "Serie - " << this->getTitulo();
    std::cout << " Temporadas: " << this->getTemporadas().size();
    std::cout << " Genero: " << this->getGeneroString();
    std::cout << '\n';
            
}
std::string Serie::getInfoString(){
    std::map<std::string, std::shared_ptr<Temporada> >::iterator it;
    int cont=1;
    std::string aux= this->getTitulo() + " Genero: "+ this->getGeneroString() + " Temporadas: " + to_string(temporadas.size()) + '\n';
    aux= aux + "    Sinopsis: " + this->getSinopsis() + '\n';
    if(temporadas.size()==0){
        aux = aux + "    Temporadas proximamente...\n";
    }
    for(it=temporadas.begin(); it!=temporadas.end();it++){
        aux= aux + "    Temporada "+it->first + " - " + temporadas[it->first]->getInfoString() + '\n';
        cont++;
    }
    
    return aux;
}
void Serie::addTemporada(std::string ntemp){
    if (temporadas.count(ntemp)==0){ //No existe esta temporada
        temporadas[ntemp].reset(new Temporada(ntemp));
        std::cout << "Ha sido añadida la temporada " << ntemp << '\n';
    } else { //Existe esta temporada
        std::cout << "Ya existe la temporada " << ntemp << '\n';
    }
    
}

void Serie::addEpisodio(std::string ntemp, std::string nepi, int dur){
    if (temporadas.count(ntemp)==1){
        temporadas[ntemp]->addEpisodio(nepi,dur);
    } else {
        std::cout << "No existe la temporada " << ntemp << '\n';
    }
}

void Serie::removeTemporada(std::string ntemp){
    if (temporadas.count(ntemp)==1){
        temporadas.erase(ntemp);
        std::cout << "Se ha eliminado la temporada " << ntemp << " de la serie "<< this->getTitulo() << '\n';
    } else {
        std::cout << "No existe la temporada " << ntemp << '\n';
    }
}
void Serie::removeEpisodio(std::string nombre,std::string nepi){
    if (temporadas.count(nombre)==1){
        temporadas[nombre]->removeEpisodio(nepi);
    } else {
        std::cout << "No existe la temporada " << nombre << '\n';
    }
}

int Serie::getNumCapitulos() {
    return numcapitulos;
}

std::shared_ptr<Episodio> Serie::buscarEpisodio (unsigned int n1,unsigned int n2){
    std::shared_ptr<Episodio> epi;
    std::shared_ptr<Temporada> temp;
    std::map<std::string, std::shared_ptr<Temporada> >::iterator it = temporadas.begin();
    if(temporadas.count(to_string(n1))==1){
        epi = temporadas[to_string(n1)]->buscarEpisodio(n2);
    } else {
        std::cout << "No existe la temporada " << n1 << " en la serie " << this->getTitulo() << '\n';
    }
    /*if (n1<=temporadas.size()){
        std::advance(it,n1-1);
        epi = temporadas[it->first]->buscarEpisodio(n2);
    } else {
       std::cout << "No hay tantas temporadas" << '\n'; 
    }*/
    return epi;
}
