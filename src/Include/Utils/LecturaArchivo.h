//
// Created by jazze on 30-11-2025.
//

#ifndef UNTITLED2_LECTURAARCHIVO_H
#define UNTITLED2_LECTURAARCHIVO_H



#include <string>
#include "../Models/Avl.h"
#include "../Models/Personas.h"
#include "../Models/Partidas.h"


/**
 * @class LecturaArchivo
 * @brief Maneja la lectura de archivos CSV del sistema.
 *
 * Carga la información inicial de personas y partidas,
 * insertándolas en sus respectivas estructuras de datos.
 */
class LecturaArchivo {
public:

    /**
     * @brief Carga los registros desde personas.csv.
     *
     * Lee cada línea, crea objetos Persona y los inserta
     * en el árbol AVL según su ID.
     *
     * @param ruta Ruta del archivo CSV.
     * @param arbol Árbol AVL donde se insertarán las personas.
     */
    static void cargarPersonas(const std::string &ruta, AVL &arbol);
    /**
     * @brief Carga las partidas desde partidas.csv.
     *
     * Asocia cada partida con la persona correspondiente,
     * insertando los registros en el MinHeap interno del jugador.
     *
     * @param ruta Ruta del archivo CSV.
     * @param arbol Árbol AVL donde se buscarán las personas.
     */
    static void cargarPartidas(const std::string &ruta, AVL &arbol);
};


#endif //UNTITLED2_LECTURAARCHIVO_H

