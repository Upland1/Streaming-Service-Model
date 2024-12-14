//SEBASTIAN ALETT OLIVA ARANDA A01645073
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(const string& id, const string& nombre, int duracion, const string& genero);
    string mostrar() const;
};

#endif
