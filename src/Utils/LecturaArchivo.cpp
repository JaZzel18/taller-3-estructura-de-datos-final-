//
// Created by jazze on 30-11-2025.
//

#include "../Include/Utils/LecturaArchivo.h"
#include "../Include/Models/Avl.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void LecturaArchivo::cargarPersonas(const std::string &ruta, AVL &arbol) {

    std::ifstream file(ruta);

    if (!file.is_open()) {
        std::cout << "error al abrir personas.csv\n";
        return;
    }

    std::string linea;
    getline(file, linea);

    while (getline(file, linea)) {

        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string id, nombre, rol, atributo;

        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, rol, ';');
        getline(ss, atributo, ';');

        Persona* p = new Persona(
            std::stoi(id),
            nombre,
            rol,
            atributo
        );

        arbol.insertar(p);
    }

    file.close();
}

void LecturaArchivo::cargarPartidas(const std::string &ruta, AVL &arbol) {

    std::ifstream file(ruta);

    if (!file.is_open()) {
        std::cout << "error al abrir partidas.csv\n";
        return;
    }

    std::string linea;
    getline(file, linea);
    while (getline(file, linea)) {

        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string idStr, nombreJugador, juego, puntajeStr;

        getline(ss, idStr, ';');
        getline(ss, nombreJugador, ';');
        getline(ss, juego, ';');
        getline(ss, puntajeStr, ';');

        int id = std::stoi(idStr);
        int puntaje = std::stoi(puntajeStr);

        NodoAVL* nodo = arbol.buscarPorNombre(nombreJugador);

        if (nodo == nullptr) {
            std::cout << "advertencia: jugador '"
                      << nombreJugador
                      << "' no encontrado en personas.csv\n";
            continue;
        }

        Partida nueva(id, juego, puntaje);

        nodo->persona->getPartidas().insertar(nueva);
    }

    file.close();
}