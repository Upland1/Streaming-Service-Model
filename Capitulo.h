//SEBASTIAN ALETT OLIVA ARANDA A01645073
#ifndef CAPITULO_H
#define CAPITULO_H

#include "Video.h"

class Capitulo : public Video {
private:
    string serie;
    int episodio;

public:
    Capitulo(const string& id, const string& nombre, int duracion, const string& genero, const string& serie, int episodio);
    string mostrar() const;
};

#endif
