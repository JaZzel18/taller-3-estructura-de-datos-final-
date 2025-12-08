//
// Created by jazze on 30-11-2025.
//

#ifndef UNTITLED2_PERSONAS_H
#define UNTITLED2_PERSONAS_H

#include <string>
#include "MinHeap.h"


/**
 * @class Persona
 * @brief Representa a una persona registrada en el sistema.
 *
 * Contiene información básica del jugador y su historial
 * de partidas almacenado en un MinHeap.
 */
class Persona {
private:
    int id;
    std::string nombre;
    std::string rol;
    std::string atributo;
    MinHeap partidas;

public:

    /**
     * @brief Constructor por defecto.
     */
    Persona();
    /**
     * @brief Constructor con parámetros.
     *
     * @param id Identificador único.
     * @param nombre Nombre de la persona.
     * @param rol Rol asignado.
     * @param atributo Atributo asociado al rol.
     */
    Persona(int id, const std::string &nombre,
            const std::string &rol, const std::string &atributo);

    /**
     * @brief Obtiene el ID de la persona.
     */
    int getId() const;
    /**
     * @brief Obtiene el nombre de la persona.
     */
    std::string getNombre() const;

    /**
     * @brief Obtiene el rol asignado.
     */
    std::string getRol() const;
    /**
    * @brief Obtiene el atributo asociado al rol.
    */
    std::string getAtributo() const;

    /**
     * @brief Devuelve la estructura de partidas del jugador.
     *
     * @return Referencia al MinHeap que almacena las partidas.
     */
    MinHeap& getPartidas();
};

#endif //UNTITLED2_PERSONAS_H