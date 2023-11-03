/*
 * Encuesta.h
 *
 *  Created on: 03/11/2023
 *      Author: algo2
 */

#ifndef ENCUESTA_H_
#define ENCUESTA_H_

#include <string>
#include "Opcion.h"

using namespace std;

class Encuesta{

private:

	string pregunta;
	unsigned int cantidadDeOpciones;
	Opcion** opciones;

public:

    /*
     * pre : cantidadDeOpciones es mayor a 1.
     * post: la Encuesta queda inicializada con la pregunta indicada y con
     *       cantidadDeOpciones opciones disponibles.
     */
	Encuesta(string pregunta, unsigned int cantidadDeOpciones);

    /*
     * post: devuelve el enunciado de la pregunta que tiene la Encuesta.
     */
	string getPregunta();

    /*
     * post: devuelve la cantidad de Opciones que tiene la Encuesta.
     */
	unsigned int getCantidadDeOpciones();

    /*
     * pre : numero está en el rango [1, contarOpciones()]
     * post: devuelve la Opción que corresponde con el número indicado.
     */
    Opcion* getOpcion(unsigned int numero);

    /*
     * post: devuelve la cantidad total de votos de la encuesta,
     *       es decir la sumatoria de votos que cada una de sus Opciones recibió.
     */
	unsigned int contarVotosTotales();

    /*
     * post: libera todos los recursos asociados con la instancia.
     */
	~Encuesta();

};

#endif /* ENCUESTA_H_ */
