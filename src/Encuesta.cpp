/*
 * Encuesta.cpp
 *
 *  Created on: 03/11/2023
 *      Author: algo2
 */

#include "Encuesta.h"
#include <string>

Encuesta::Encuesta(std::string pregunta, unsigned int cantidadDeOpciones){

	if(cantidadDeOpciones > 1){
		this->cantidadDeOpciones = cantidadDeOpciones;
	} else {
		this->cantidadDeOpciones = 2;
	}
	this->pregunta = pregunta;
	this->opciones = new Opcion*[cantidadDeOpciones];
    for (unsigned int i = 0; i < this->cantidadDeOpciones; i++) {
        this->opciones[i] = NULL;
    }
}

string Encuesta::getPregunta(){
	return this->pregunta;
}

unsigned int Encuesta::getCantidadDeOpciones(){
	return this->cantidadDeOpciones;
}

Opcion* Encuesta::getOpcion(unsigned int numero){

	Opcion* opcion = NULL;

	if((numero > 0) && (numero <= this->cantidadDeOpciones)){
		opcion = this->opciones[numero - 1];

		/* si la opcion aún no fue creada, la crea y la guarda */
		if(opcion == NULL){
			opcion = new Opcion(numero);
			this->opciones[numero - 1] = opcion;
		}
	}

	return opcion;
}

unsigned int Encuesta::contarVotosTotales() {

    unsigned int votos = 0;

    for (int numero = 1; numero <= this->cantidadDeOpciones; numero++) {
        votos += this->getOpcion(numero)->getVotos();
    }

    return votos;
}

Encuesta::~Encuesta(){

    for (unsigned int i = 0; i < this->cantidadDeOpciones; i++){
        Opcion* opcion = this->opciones[i];

        if (opcion != NULL){
            delete opcion;
        }
    }

    delete[] this->opciones;
}
