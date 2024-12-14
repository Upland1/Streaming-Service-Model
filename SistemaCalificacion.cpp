//SEBASTIAN ALETT OLIVA ARANDA A01645073
#include "SistemaCalificacion.h"
#include <sstream>

void SistemaCalificacion::cargarVideosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    while (getline(archivo, linea)) {
        istringstream lin(linea);
        string tipo, id, nombre, duracion, genero, serie, episodio;

        getline(lin, tipo, ',');
        getline(lin, id, ',');
        getline(lin, nombre, ',');
        getline(lin, duracion, ',');
        getline(lin, genero, ',');

        if (tipo == "p") {
            catalogo.push_back(new Pelicula(id, nombre, stoi(duracion), genero));
        } else if (tipo == "c") {
            getline(lin, serie, ',');
            getline(lin, episodio, ',');
            
            catalogo.push_back(new Capitulo(id, nombre, stoi(duracion), genero, serie, stoi(episodio)));
        }
    }
}
//Para el método de llamar archivos de texto, se sacó la biblioteca y las funciones de: 
//https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm 



void SistemaCalificacion::mostrarCatalogo() const{
    for (const auto& video: catalogo) {
        cout << *video << endl;
    }

}

void SistemaCalificacion::calificarVideo(const string& id, int calificacion) {
    for (const auto& video: catalogo) {
        if (video->getId() == id) {
            video->agregarCalificacion(calificacion);
            return;
        }
    }
    cout << "Video no encontrado" << endl;
}

void SistemaCalificacion::mostrarVideosConCalificacionMinima(double calificacionMinima, int tipoVideo) const {
    for (const auto& video: catalogo) {
        if (video->obtenerCalificacionPromedio() >= calificacionMinima && 
        ((tipoVideo == 1 && dynamic_cast<Pelicula*>(video)) || 
        (tipoVideo == 2 && dynamic_cast<Capitulo*>(video))|| 
        tipoVideo == 3)) {
            cout << video->getId() << "," << video->getNombre() << "," << video->obtenerCalificacionPromedio() << endl;
        }
    }
}

void SistemaCalificacion::mostrarVideosPorGenero(const string& genero, int tipoVideo) const {
    for (const auto& video: catalogo) {
        if (video->getGenero() == genero && 
        ((tipoVideo == 1 && dynamic_cast<Pelicula*>(video)) || 
        (tipoVideo == 2 && dynamic_cast<Capitulo*>(video)) || 
        tipoVideo == 3)) {
            cout << video->getId() << "," << video->getNombre() << "," << video->getGenero() << "," 
            << video->obtenerCalificacionPromedio() << endl;
        }
    }
}
