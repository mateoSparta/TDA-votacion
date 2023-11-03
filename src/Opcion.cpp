/*
 * Opcion.cpp
 *
 *  Created on: 03/11/2023
 *      Author: algo2
 */

#include "Opcion.h"
#include <string>

Opcion::Opcion(unsigned int numero){

	if(numero < 1){
		throw string("Numero invalido");
	}

	this->numero = numero;
	this->votos = 0;
}

unsigned int Opcion::getNumero(){
	return this->numero;
}

std::string Opcion::getDescripcion(){
	return this->descripcion;
}

void Opcion::setDescripcion(std::string descripcion){
	this->descripcion = descripcion;
}

void Opcion::votar(){
	this->votos++;
}

unsigned int Opcion::getVotos(){
	return this->votos;
}
