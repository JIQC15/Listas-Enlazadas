#include "Libro.h"
#include <iostream>

Libro::Libro() {
	Clave = 0;
	Titulo = "";
	Autor = "";
}

Libro::Libro(int clave, string titulo, string autor) {
	Clave = clave;
	Titulo = titulo;
	Autor = autor;
}

Libro::~Libro() {}

void Libro::set_Clave(int clave) {
	Clave = clave;
}

int Libro::get_Clave() {
	return Clave;
}

void Libro::set_Titulo(string titulo) {
	Titulo = titulo;
}

string Libro::get_Titulo() {
	return Titulo;
}

void Libro::set_Autor(string autor) {
	Autor = autor;
}

string Libro::get_Autor() {
	return Autor;
}

void Libro::mostrar_Datos() {
	cout << "Clave: "<< get_Clave() << endl;
	cout << "Titulo: " << get_Titulo()  << endl;
	cout << "Autor: " << get_Autor() << endl;
}