#pragma once
#include <iostream>
#include "Libro.h"

using namespace std;

class Nodo {
public:
    Nodo(Libro*, Nodo*);

private:
    Libro* Valor;
    Nodo* Siguiente;

    friend class Lista;
};