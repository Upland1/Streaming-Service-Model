//SEBASTIAN ALETT OLIVA ARANDA A01645073
#include "Pelicula.h"

Pelicula::Pelicula(const string& id, const string& nombre, int duracion, const string& genero)
    : Video(id, nombre, duracion, genero) {}

string Pelicula::mostrar() const {
    return id + "," + nombre + "," + to_string(duracion) + "," + genero + "," + 
    (calificaciones.empty() ? "SC" : to_string(obtenerCalificacionPromedio()));
}

//Para calificaciones.empty() ? "SC" utilicé el ejemplo de uso de:
//https://es.stackoverflow.com/questions/384162/qu%C3%A9-hace-el-operador-en-c

//se buscó una función para retornar un valor true si el arreglo de califiaciones estaba vacio
//https://www.educative.io/answers/what-is-stackempty-in-cpp
