//
// Created by jazze on 30-11-2025.
//

#ifndef UNTITLED2_PARTIDAS_H
#define UNTITLED2_PARTIDAS_H

#include <string>


/**
 * @class Partida
 * @brief Representa un registro de puntaje obtenido en un minijuego.
 *
 * Almacena el identificador de la partida, el nombre del juego
 * y el puntaje obtenido por el jugador.
 */
class Partida {
private:
    int id;
    std::string nombreJuego;
    int puntaje;

public:
    /**
     * @brief Constructor por defecto.
     */
    Partida();

    Partida(int id, const std::string &juego, int puntaje);

    /**
     * @brief Obtiene el ID de la partida.
     */
    int getId() const;
    /**
     * @brief Obtiene el nombre del minijuego.
     */
    std::string getJuego() const;
    /**
     * @brief Obtiene el puntaje registrado.
     */
    int getPuntaje() const;

    /**
     * @brief Modifica el puntaje de la partida.
     *
     * @param p Nuevo puntaje.
     */
    void setPuntaje(int p);
};




#endif //UNTITLED2_PARTIDAS_H