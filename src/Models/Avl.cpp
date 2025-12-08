//
// Created by jazze on 01-12-2025.
//


#include "../Include/Models/Avl.h"
#include <iostream>
#include <algorithm>

AVL::AVL() {
    raiz = nullptr;
}

int AVL::altura(NodoAVL* nodo) {
    if (!nodo) return 0;
    return nodo->altura;
}

int AVL::balance(NodoAVL* nodo) {
    if (!nodo) return 0;
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

NodoAVL* AVL::rotDer(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* T2 = x->derecha;

    x->derecha = y;
    y->izquierda= T2;

    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

NodoAVL* AVL::rotIzq(NodoAVL* x) {
    NodoAVL* y = x->derecha;
    NodoAVL* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

NodoAVL* AVL::insertarRec(NodoAVL* nodo, Persona* p) {
    if (!nodo)
        return new NodoAVL(p);

    if (p->getId() < nodo->persona->getId())
        nodo->izquierda = insertarRec(nodo->izquierda, p);
    else
        nodo->derecha = insertarRec(nodo->derecha, p);

    nodo->altura = 1 + std::max(altura(nodo->izquierda), altura(nodo->derecha));
    int b = balance(nodo);

    if (b > 1 && p->getId() < nodo->izquierda->persona->getId())
        return rotDer(nodo);

    if (b < -1 && p->getId() > nodo->derecha->persona->getId())
        return rotIzq(nodo);

    if (b > 1 && p->getId() > nodo->izquierda->persona->getId()) {
        nodo->izquierda = rotIzq(nodo->izquierda);
        return rotDer(nodo);
    }

    if (b < -1 && p->getId() < nodo->derecha->persona->getId()) {
        nodo->derecha = rotDer(nodo->derecha);
        return rotIzq(nodo);
    }

    return nodo;
}

void AVL::insertar(Persona* p) {
    raiz = insertarRec(raiz, p);
}

void AVL::inOrdenRec(NodoAVL* nodo) {
    if (!nodo) return;

    inOrdenRec(nodo->izquierda);

    std::cout << nodo->persona->getId() << " - "
              << nodo->persona->getNombre() << " - "
              << nodo->persona->getRol() << " - "
              << nodo->persona->getAtributo() << "\n";

    inOrdenRec(nodo->derecha);
}

void AVL::inOrden() {
    inOrdenRec(raiz);
}

NodoAVL* AVL::getRaiz() {
    return raiz;
}


NodoAVL* AVL::buscarPorNombre(const std::string &nombre) {
    return buscarPorNombreRec(raiz, nombre);
}

NodoAVL* AVL::buscarPorNombreRec(NodoAVL* nodo, const std::string &nombre) {

    if (nodo == nullptr) return nullptr;


    NodoAVL* left = buscarPorNombreRec(nodo->izquierda, nombre);
    if (left != nullptr) return left;


    std::string n1 = nodo->persona->getNombre();
    std::string n2 = nombre;

    std::transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
    std::transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

    if (n1 == n2)
        return nodo;


    return buscarPorNombreRec(nodo->derecha, nombre);
}