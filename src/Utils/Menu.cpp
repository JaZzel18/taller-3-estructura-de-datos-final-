//
// Created by jazze on 30-11-2025.
//


#include "../Include/Utils/Menu.h"
#include <iostream>
#include <string>

Menu::Menu() {
    std::string rutaPersonas = "personas.csv";
    std::string rutaPartidas = "partidas.csv";

    lector.cargarPersonas(rutaPersonas, arbolPersonas);
    lector.cargarPartidas(rutaPartidas, arbolPersonas);

    std::cout << "\ndatos cargados\n";
}


void imprimirReporteRec(NodoAVL* nodo) {
    if (nodo == nullptr) return;


    imprimirReporteRec(nodo->izquierda);


    Persona* p = nodo->persona;

    std::cout << "\n----------------------------------\n";
    std::cout << "ID: " << p->getId() << "\n";
    std::cout << "Nombre: " << p->getNombre() << "\n";
    std::cout << "Rol: " << p->getRol() << "\n";
    std::cout << "Atributo: " << p->getAtributo() << "\n";


    MinHeap& heap = p->getPartidas();

    if (heap.vacio()) {
        std::cout << "partidas: (sin partidas registradas)\n";
    } else {
        std::cout << "partidas:\n";

        Partida* arr = heap.getElementos();
        int n = heap.getSize();

        for (int i = 0; i < n; i++) {
            std::cout << "   - ID Partida: " << arr[i].getId()
                      << " | Puntaje: " << arr[i].getPuntaje() << "\n";
        }
    }


    imprimirReporteRec(nodo->derecha);
}

bool existeID(NodoAVL* nodo, int idBuscado) {
    if (nodo == nullptr) return false;

    if (nodo->persona->getId() == idBuscado)
        return true;


    return existeID(nodo->izquierda, idBuscado) ||
           existeID(nodo->derecha, idBuscado);
}


void Menu::agregarPersona() {
    std::cout << "\nagregar Nueva Persona\n";

    int id;
    std::cout << "ingrese ID: ";
    std::cin >> id;
    std::cin.ignore();


    if (existeID(arbolPersonas.getRaiz(), id)) {
        std::cout << "error El ID ya existe\n";
        return;
    }


    std::string nombre;
    std::cout << "ingrese nombre: ";
    std::getline(std::cin, nombre);


    std::string nombreFinal = nombre;
    int correlativo = 1;

    while (arbolPersonas.buscarPorNombre(nombreFinal) != nullptr) {
        nombreFinal = nombre + "_" + std::to_string(correlativo);
        correlativo++;
    }

    if (nombre != nombreFinal) {
        std::cout << "nombre repetido. Se usará: " << nombreFinal << "\n";
    }


    std::string rol;
    std::cout << "ingrese rol (CEAL / Guardia / Invitado): ";
    std::getline(std::cin, rol);

    if (!(rol == "CEAL" || rol == "Guardia" || rol == "Invitado")) {
        std::cout << "error Rol inválido\n";
        return;
    }


    std::string atributo;

    if (rol == "CEAL") {
        std::cout << "ingrese atributo (Parrillero / Rapido): ";
        std::getline(std::cin, atributo);

        if (!(atributo == "Parrillero" || atributo == "Rapido")) {
            std::cout << "ERROR: Atributo inválido.\n";
            return;
        }
    }
    else if (rol == "Guardia") {
        std::cout << "ingrese atributo (Seguro / Estricto): ";
        std::getline(std::cin, atributo);

        if (!(atributo == "Seguro" || atributo == "Estricto")) {
            std::cout << "ERROR: Atributo inválido.\n";
            return;
        }
    }
    else {
        std::cout << "ingrese atributo (Con entrada / Sin entrada / Entrada falsa): ";
        std::getline(std::cin, atributo);

        if (!(atributo == "Con entrada" ||
              atributo == "Sin entrada" ||
              atributo == "Entrada falsa")) {

            std::cout << "ERROR: Atributo inválido.\n";
            return;
        }
    }


    Persona* nueva = new Persona(id, nombreFinal, rol, atributo);


    arbolPersonas.insertar(nueva);

    std::cout << "Persona agregada correctamente.\n";
}

void Menu::mostrarReporteGeneral() {
    if (arbolPersonas.getRaiz() == nullptr) {
        std::cout << "No hay personas registradas.\n";
        return;
    }

    std::cout << "\nReporte general\n";

    imprimirReporteRec(arbolPersonas.getRaiz());

    std::cout << "\nfin del reporte\n";
}



void Menu::menuPrincipal() {

    char opcion = 'x';

    do {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "              MENU PRINCIPAL             \n";
        std::cout << "-------------------------------------------\n";
        std::cout << "a. Agregar Persona\n";
        std::cout << "b. Mostrar Reporte General\n";
        std::cout << "c. Primer juego - Entrega de Choripanes\n";
        std::cout << "d. Segundo juego - guia a Justin Bieber\n";
        std::cout << "e. Tercer juego - Adivinar Puntajes\n";
        std::cout << "f. Salir y guardar\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {

            case 'a':
            case 'A':
                agregarPersona();
                break;

            case 'b':
            case 'B':
                mostrarReporteGeneral();
                break;

            case 'c':
            case 'C':
                std::cout << "Juego de Choripanes aún no implementado.\n";
                break;

            case 'd':
            case 'D':
                std::cout << "Juego Justin Bieber aún no implementado.\n";
                break;

            case 'e':
            case 'E':
                std::cout << "Juego Adivinar Puntajes aún no implementado.\n";
                break;

            case 'f':
            case 'F':
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opción no válida.\n";
        }

    } while (opcion != 'f' && opcion != 'F');
}