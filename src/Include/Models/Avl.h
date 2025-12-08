//
// Created by jazze on 01-12-2025.
//

#ifndef UNTITLED2_AVL_H
#define UNTITLED2_AVL_H

#include "NodoAvl.h"


/**
 * @class AVL
 * @brief Implementa un árbol AVL para almacenar personas ordenadas por ID.
 *
 * Permite insertar personas, recorrer el árbol en orden
 * y buscar jugadores por nombre.
 */
class AVL {
private:
    NodoAVL* raiz;

    /**
     * @brief Obtiene la altura de un nodo.
     */
    int altura(NodoAVL* nodo);
    /**
     * @brief Calcula el factor de balance de un nodo.
     */
    int balance(NodoAVL* nodo);

    /**
     * @brief Rotación simple hacia la derecha.
     */
    NodoAVL* rotDer(NodoAVL* y);
    /**
     * @brief Rotación simple hacia la izquierda.
     */
    NodoAVL* rotIzq(NodoAVL* x);

    /**
     * @brief Inserta un nodo de forma recursiva manteniendo el balance AVL.
     *
     * @param nodo Subárbol actual.
     * @param p Persona a insertar.
     * @return Nuevo nodo raíz del subárbol.
     */
    NodoAVL* insertarRec(NodoAVL* nodo, Persona* p);
    /**
     * @brief Recorre el árbol en orden (inOrden).
     */
    void inOrdenRec(NodoAVL* nodo);

    /**
     * @brief Búsqueda recursiva de una persona por nombre.
     *
     * La comparación es case-insensitive.
     *
     * @param nodo Nodo actual a revisar.
     * @param nombre Nombre a buscar.
     * @return NodoAVL* donde se encuentra la persona.
     */
    NodoAVL* buscarPorNombreRec(NodoAVL* nodo, const std::string &nombre);

public:
    /**
     * @brief Constructor por defecto.
     */
    AVL();

    /**
    * @brief Inserta una persona en el árbol AVL.
    */
    void insertar(Persona* p);
    /**
     * @brief Imprime el recorrido inOrden del árbol.
     */
    void inOrden();

    /**
    * @brief Obtiene la raíz del árbol.
    */
    NodoAVL* getRaiz();
    /**
     * @brief Busca una persona por nombre.
     *
     * @param nombre Nombre a buscar.
     * @return NodoAVL* encontrado o nullptr.
     */
    NodoAVL* buscarPorNombre(const std::string &nombre);
};

#endif //UNTITLED2_AVL_H