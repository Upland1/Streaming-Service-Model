//SEBASTIAN ALETT OLIVA ARANDA A01645073
#include "SistemaCalificacion.h"

int main() {
    string id,
           genero;

    int calificacion, 
        opcion,
        tipoVideo;

    double calificacionMinima;

    SistemaCalificacion sistema;
    sistema.cargarVideosDesdeArchivo("videos.txt");


    do{
        cout << "1. Mostrar el catalogo\n"
             << "2. Calificar un video\n"
             << "3. Mostrar peliculas o capitulos con una calificacion minima especifica\n"
             << "4. Mostrar peliculas o capitulos de un genero\n"
             << "9. Salir\n"
             << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.mostrarCatalogo();
                break;
            case 2: {
                
                cout << "Ingrese el ID del video a calificar: ";
                cin >> id;
                do{
                    cout << "Ingrese la calificacion (1-5): ";
                    cin >> calificacion;
                } while (calificacion < 1 || calificacion > 5);
                sistema.calificarVideo(id, calificacion);
                break;
            }
            case 3: {
                
                do{
                    cout << "Pelicula=1, Capitulo=2, Ambos=3: ";
                    cin >> tipoVideo;
                } while(tipoVideo < 1 || tipoVideo > 3);
                cout << "Ingrese la calificacion minima: ";
                cin >> calificacionMinima;
                sistema.mostrarVideosConCalificacionMinima(calificacionMinima, tipoVideo);
                break;
            }
            case 4: {
                do{
                    cout << "Pelicula=1, Capitulo=2, Ambos=3: ";
                    cin >> tipoVideo;
                }while(tipoVideo < 1 || tipoVideo > 3);
                cout << "Ingrese el genero: ";
                cin >> genero;
                sistema.mostrarVideosPorGenero(genero, tipoVideo);
                break;
            }
            case 9:
                cout << "Saliendo" << endl;
                break;
            default:
                cout << "Opcion no valida, intente con una de la lista" << endl;
                break;
        }
    } while(opcion != 9);

    return 0;
}
