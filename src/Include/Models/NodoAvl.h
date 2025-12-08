//
// Created by jazze on 05-12-2025.
//

#ifndef UNTITLED2_NODOAVL_H
#define UNTITLED2_NODOAVL_H

#include "Personas.h"

/**
 * @class NodoAVL
 * @brief Representa un nodo del árbol AVL.
 *
 * Cada nodo almacena un puntero a una Persona,
 * sus subárboles izquierdo y derecho, y la altura
 * necesaria para mantener el equilibrio del AVL.
 */
class NodoAVL {

public:
    Persona* persona;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    /**
     * @brief Constructor que inicializa un nodo con una persona.
     *
     * @param p Puntero a la persona que se almacenará.
     */
    NodoAVL(Persona* p);

};
#endif //UNTITLED2_NODOAVL_H