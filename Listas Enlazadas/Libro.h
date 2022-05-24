//Libro.h
#pragma once
#include <iostream>

using namespace std;

class Libro {
private:
	int Clave;
	string Titulo;
	string Autor;
public:
	Libro(); //Constructor
	Libro(int, string, string); //Constructor parametrizado
	~Libro(); //Destructor
	void set_Clave(int);
	int get_Clave();//Usuario-Clave
	void set_Titulo(string);
	string get_Titulo();//Usuario-Titulo.
	void set_Autor(string);
	string get_Autor();//Usuario-Autor
	void mostrar_Datos(); //Funcion para ver los datos.
};