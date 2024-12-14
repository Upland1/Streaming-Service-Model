//SEBASTIAN ALETT OLIVA ARANDA A01645073
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Video {
protected:
    string id;
    string nombre;
    int duracion;
    string genero;
    vector<int> calificaciones;

public:
    Video(const string& id, const string& nombre, int duracion, const string& genero);
    void agregarCalificacion(int calificacion);
    double obtenerCalificacionPromedio() const;
    virtual string mostrar() const = 0;
    virtual string getId() const;
    virtual string getNombre() const;
    virtual string getGenero() const;
    virtual int getDuracion() const;
    friend ostream& operator<<(ostream& os, const Video& video);
};


#endif
