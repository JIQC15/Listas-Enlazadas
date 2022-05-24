//Lista.h
#pragma once
#include "Libro.h"
#include "Nodo.h"

class Lista {
public:
    Lista();//Constructor
    ~Lista();//Destructor para eliminar la lista completa
    void insertar_Inicio(Libro*);//Comando
    void insertar_Nuevo(Libro*);//Comando
    void insertar_Final(Libro*);//Comando
    void insertar_Antes_De(Libro*, int);//Comando
    Nodo* buscar_Nodo(int);//Comando
    void visualizar_Nodo(int);//Comando
    void Borrar(int);//Comando
    void modificar_Nodo(Libro*, int);//Comando
    bool lista_Vacia();//Comando
    Nodo* Ultimo();//Comando
    void mostrar();//Comando para el muestreo de funciones
   
protected:
    Nodo* Primer_Lista;
};