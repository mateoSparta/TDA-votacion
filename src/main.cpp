/*
 * main.cpp
 *
 *  Created on: 03/11/2023
 *      Author: algo2
 */

/*
 * Implementar el TDA Encuesta.
 *
 * Una Encuesta es una pregunta que ofrece múltiples opciones
 * para responderla y que contabiliza los votos recibidos.
 *
 * Desarrollar una aplicación para llevar adelante una votación:
 * creando una Encuesta y permitiendo votar en la misma.
 *
 */

#include <iostream>
#include "Opcion.h"
#include "Encuesta.h"

using namespace std;

int main() {

    string pregunta;
    string descripcion;
    unsigned int cantidadDeOpciones;
    int opcion;

    cout << "Ingrese la pregunta de la encuesta: ";
    getline(cin, pregunta);

    cout << "Ingrese la cantidad de opciones de la encuesta: ";
    cin >> cantidadDeOpciones;

    Encuesta encuesta(pregunta, cantidadDeOpciones);

    for(unsigned int i = 0; i < cantidadDeOpciones; i++){
    	cout << "Opcion " << i + 1 << ": ";
    	cin  >> descripcion;
		encuesta.getOpcion(i)->setDescripcion(descripcion);
    }

    do {
        cout << "\n--- Menú ---" << endl;
        cout << "1. Ver pregunta de la encuesta" << endl;
        cout << "2. Ver cantidad de opciones de la encuesta" << endl;
        cout << "3. Ver opciones de la encuesta" << endl;
        cout << "4. Votar por una opción" << endl;
        cout << "5. Ver total de votos de la encuesta" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Pregunta de la encuesta: " << encuesta.getPregunta() << endl;
                break;
            case 2:
                cout << "Cantidad de opciones de la encuesta: " << encuesta.getCantidadDeOpciones() << endl;
                break;
            case 3:
                cout << "Opciones de la encuesta:" << endl;
                for (unsigned int i = 1; i <= encuesta.getCantidadDeOpciones(); ++i) {
                    Opcion* opcion = encuesta.getOpcion(i);
                    cout << i << ". " << opcion->getDescripcion() << " - Votos: " << opcion->getVotos() << endl;
                }
                break;
            case 4:
                unsigned int numOpcion;
                cout << "Ingrese el número de la opción para votar: ";
                cin >> numOpcion;
                if (numOpcion >= 1 && numOpcion <= encuesta.getCantidadDeOpciones()) {
                    encuesta.getOpcion(numOpcion)->votar();
                    cout << "Voto registrado correctamente." << endl;
                } else {
                    cout << "Número de opción no válido." << endl;
                }
                break;
            case 5:
                cout << "Total de votos de la encuesta: " << encuesta.contarVotosTotales() << endl;
                break;
            case 6:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
