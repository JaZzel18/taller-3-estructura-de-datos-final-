//
// Created by jazze on 30-11-2025.
//


#include "../Include/Models/Personas.h"


Persona::Persona() : id(0), nombre(""), rol(""), atributo("") {}

Persona::Persona(int id, const std::string &nombre,
                 const std::string &rol, const std::string &atributo)
        : id(id), nombre(nombre), rol(rol), atributo(atributo) {}

int Persona::getId() const { return id; }
std::string Persona::getNombre() const { return nombre; }
std::string Persona::getRol() const { return rol; }
std::string Persona::getAtributo() const { return atributo; }

MinHeap& Persona::getPartidas() { return partidas; }