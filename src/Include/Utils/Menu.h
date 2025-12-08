//
// Created by jazze on 30-11-2025.
//

#ifndef UNTITLED2_MENU_H
#define UNTITLED2_MENU_H

#include "../Models/Avl.h"
#include "../Utils/LecturaArchivo.h"

/**
 * @class Menu
 * @brief Gestiona la interfaz principal del sistema de jugadores y minijuegos.
 *
 * La clase Menu agrupa las funcionalidades centrales:
 * - Carga de personas y partidas desde archivos CSV.
 * - Inserción y validación de nuevos jugadores.
 * - Acceso a reportes y consultas del sistema.
 * - Ejecución de los tres minijuegos principales:
 *   1. Entrega de choripanes (CEAL).
 *   2. Guía a Justin Bieber (Guardias).
 *   3. Adivinar puntajes (Invitados).
 */
class Menu {
public:

    AVL arbolPersonas;        ///< Árbol AVL que almacena todas las personas
    LecturaArchivo lector;    ///< Módulo responsable de la carga de archivos CSV

    /**
     * @brief Constructor por defecto del menú.
     *
     * Inicializa el sistema creando un árbol AVL vacío.
     */
    Menu();

    /**
     * @brief Controla el flujo del programa mediante un menú interactivo.
     *
     * El usuario puede seleccionar opciones tales como:
     * - Agregar personas.
     * - Visualizar reportes.
     * - Entrega de choripanes.
     * - Guia de justin bieber.
     * - adivinar puntajes
     */
    void menuPrincipal();

    /**
     * @brief Permite agregar una nueva persona al sistema.
     *
     * Realiza validaciones según el taller:
     * - El nombre debe ser único (se añade correlativo si se repite).
     * - Validación estricta del campo Rol.
     * - Validación del Atributo según el Rol.
     * - Inserción de la persona en su estructura AVL.
     */
    void agregarPersona();


    /**
     * @brief Muestra un reporte general de todas las personas del sistema.
     *
     * Recorre todas las personas en inOrden (AVL) e imprime:
     * - ID, nombre, rol y atributo.
     * - Lista de partidas con ID y puntaje.
     * Si una persona no tiene partidas, se indica en pantalla.
     */
    void mostrarReporteGeneral();


    /**
     * @brief Minijuego para integrantes CEAL.
     *
     * Consiste en preparar choripanes dentro de un tiempo,
     * aplicando las reglas y bonificaciones según el atributo.
     */

    void entregaChoripanes();

     /**
     * @brief Minijuego para guardias.
     *
     * El jugador debe guiar a Justin Bieber,
     * considerando la distancia, enojos y atributos del guardia.
     */
    void guiaJustinBieber();

    /**
     * @brief Minijuego para invitados con entrada válida.
     *
     * El jugador intenta adivinar qué participantes
     * tienen el puntaje más bajo en rondas alternadas.
     */
    void adivinarPuntajes();


};


#endif //UNTITLED2_MENU_H