//SEBASTIAN ALETT OLIVA ARANDA A01645073
#include "Video.h"

Video::Video(const string& id, const string& nombre, int duracion, const string& genero)
    : id(id), nombre(nombre), duracion(duracion), genero(genero) {}

void Video::agregarCalificacion(int calificacion) {
    calificaciones.push_back(calificacion);
}

double Video::obtenerCalificacionPromedio() const{
    if (calificaciones.empty()){
        return 0;
    } 

    double suma = 0.0;
    for (const int& calificacion : calificaciones) {
        suma += calificacion;
    }
    return suma / calificaciones.size();
}

//se buscó una función para retornar un valor true si el arreglo de califiaciones estaba vacio
//https://www.educative.io/answers/what-is-stackempty-in-cpp


string Video::getId()const { 
    return id; 
}
string Video::getNombre() const { 
    return nombre; 
}
string Video::getGenero() const { 
    return genero;
}
int Video::getDuracion() const { 
    return duracion; 
}

ostream& operator<<(ostream& os, const Video& video) {
    os << video.mostrar();
    return os;
}
