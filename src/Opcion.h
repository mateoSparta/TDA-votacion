/*
 * opcion.h
 *
 *  Created on: 03/11/2023
 *      Author: algo2
 */

#ifndef OPCION_H_
#define OPCION_H_

#include <string>

using namespace std;

class Opcion {

private:

	unsigned int numero;
	string descripcion;
	unsigned int votos;

public:

	/*
	 * pre : numero es un valor mayor a 0.
	 * post: la Opción queda inicializada con el número indicado,
	 *       con una descripción vacía y sin votos.
	 */
	Opcion(unsigned int numero);

    /*
     * post: devuelve el número de Opción.
     */
	unsigned int getNumero();

    /*
     * post: devuelve la descripción asociada a la Opción.
     */
	string getDescripcion();

    /*
     * post: cambia la descripción de la Opción.
     */
	void setDescripcion(string descripcion);

    /*
     * post: acumula un voto.
     */
	void votar();

    /*
     * post: devuelve la cantidad de votos acumulados.
     */
	unsigned int getVotos();

};


#endif /* OPCION_H_ */
