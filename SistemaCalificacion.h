//SEBASTIAN ALETT OLIVA ARANDA A01645073
#ifndef SISTEMACALIFICACION_H
#define SISTEMACALIFICACION_H

#include <fstream>
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

class SistemaCalificacion {
private:
    vector<Video*> catalogo;

public:
    void cargarVideosDesdeArchivo(const string& nombreArchivo);
    void mostrarCatalogo() const;
    void calificarVideo(const string& id, int calificacion);
    void mostrarVideosConCalificacionMinima(double calificacionMinima, int tipoVideo) const;
    void mostrarVideosPorGenero(const string& genero, int tipoVideo) const;
};

#endif


