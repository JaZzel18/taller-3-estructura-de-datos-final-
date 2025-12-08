//
// Created by jazze on 30-11-2025.
//


#include "../Include/Models/Partidas.h"


Partida::Partida() : id(0), nombreJuego(""), puntaje(0) {}

Partida::Partida(int id, const std::string &juego, int puntaje)
        : id(id), nombreJuego(juego), puntaje(puntaje) {}

int Partida::getId() const {return id;}
std::string Partida::getJuego() const {return nombreJuego;}
int Partida::getPuntaje() const {return puntaje;}

void Partida::setPuntaje(int p) {puntaje = p;}