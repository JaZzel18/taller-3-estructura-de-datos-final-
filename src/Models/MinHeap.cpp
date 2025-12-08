//
// Created by jazze on 01-12-2025.
//


#include "../Include/Models/MinHeap.h"
#include <iostream>



MinHeap::MinHeap() {
    capacidad = 10;
    size = 0;
    arr = new Partida[capacidad];
}

MinHeap::~MinHeap() {
    delete[] arr;
}

bool MinHeap::vacio() const {
    return size == 0;
}

int MinHeap::getSize() const {
    return size;
}

Partida* MinHeap::getElementos() const {
    return arr;
}

void MinHeap::expandir() {
    capacidad *= 2;
    Partida* nuevo = new Partida[capacidad];
    for (int i = 0; i < size; i++) nuevo[i] = arr[i];
    delete[] arr;
    arr = nuevo;
}

void MinHeap::insertar(const Partida &p) {
    if (size == capacidad)
        expandir();

    arr[size] = p;
    heapifyUp(size);
    size++;
}

void MinHeap::heapifyUp(int i) {
    while (i > 0) {
        int padre = (i - 1) / 2;
        if (arr[padre].getPuntaje() <= arr[i].getPuntaje()) break;

        std::swap(arr[padre], arr[i]);
        i = padre;
    }
}

void MinHeap::heapifyDown(int i) {
    int izquierda, derecha, menor;

    while (true) {
        izquierda = 2*i+1;
        derecha = 2*i+2;
        menor = i;

        if (izquierda < size && arr[izquierda].getPuntaje() < arr[menor].getPuntaje())
            menor = izquierda;

        if (derecha < size && arr[derecha].getPuntaje() < arr[menor].getPuntaje())
            menor = derecha;

        if (menor == i) break;

        std::swap(arr[i], arr[menor]);
        i = menor;
    }
}
void MinHeap::mostrar() const {
    if (size == 0) {
        std::cout << "no hay partidas registradas.\n";
        return;
    }

    std::cout << "ID | JUEGO | PUNTAJE\n";
    std::cout << "---------------------------\n";

    for (int i = 0; i < size; i++) {
        std::cout << arr[i].getId() << " | "
                  << arr[i].getJuego() << " | "
                  << arr[i].getPuntaje() << "\n";
    }
}