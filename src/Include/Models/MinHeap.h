//
// Created by jazze on 01-12-2025.
//

#ifndef UNTITLED2_MINHEAP_H
#define UNTITLED2_MINHEAP_H


#include "Partidas.h"


/**
 * @class MinHeap
 * @brief Implementa un Min Heap para almacenar partidas.
 *
 * Las partidas se organizan por puntaje, manteniendo siempre
 * el menor puntaje en la raíz. Se usa para gestionar el historial
 * de minijuegos de cada persona.
 */
class MinHeap {
private:
    Partida* arr;
    int capacidad;
    int size;

    /**
     * @brief Ajusta el heap hacia arriba desde una posición dada.
     */
    void heapifyUp(int i);
    /**
     * @brief Ajusta el heap hacia abajo desde una posición dada.
     */
    void heapifyDown(int i);
    /**
     * @brief Duplica la capacidad del arreglo cuando está lleno.
     */
    void expandir();

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa el heap con capacidad base.
     */
    MinHeap();
    /**
     * @brief Destructor del MinHeap.
     *
     * Libera la memoria dinámica reservada.
     */
    ~MinHeap();

    /**
     * @brief Inserta una nueva partida en el heap.
     *
     * @param p Partida a insertar.
     */
    void insertar(const Partida &p);
    /**
     * @brief Indica si el heap está vacío.
     */
    bool vacio() const;
    /**
     * @brief Obtiene la cantidad actual de elementos.
     */
    int getSize() const;

    /**
     * @brief Devuelve el arreglo interno de partidas.
     *
     * @return Puntero al arreglo interno.
     */
    Partida* getElementos() const;
    /**
     * @brief Muestra el contenido del heap (para depuración).
     */
    void mostrar() const;
};



#endif //UNTITLED2_MINHEAP_H