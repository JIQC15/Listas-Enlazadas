//Lista.cpp
#include "Lista.h"

//Constructor
Lista::Lista() {
	Primer_Lista = NULL;
}

//Destructor
Lista::~Lista() {
	Nodo* aux;

	while (Primer_Lista) {
		aux = Primer_Lista;
		Primer_Lista = Primer_Lista->Siguiente;
		delete aux;
	}
}

//Parametrizamos el inicio de nuestra lista si esta se encuentra vacia, sino solo se agrega el Aux.
void Lista::insertar_Inicio(Libro* libro) {
	Nodo* aux;
	if (lista_Vacia()) {
		aux = new Nodo(libro, Primer_Lista);
		Primer_Lista = aux;
	}
	else {
		aux = new Nodo(libro, Primer_Lista->Siguiente);
		Primer_Lista = aux;
	}
}

//Funcion para insertar nuevos libros
void Lista::insertar_Nuevo(Libro* libro) {
	Nodo* aux;

	if (lista_Vacia()) {
		aux = new Nodo(libro, Primer_Lista);
		Primer_Lista = aux;
	}
	else {
		aux = Ultimo();
		aux->Siguiente = new Nodo(libro, NULL);
	}

	cout << "\nEl libro fue agregado con exito!" << endl;

}

//Definimos el final de nuestra Lista "NULL".
void Lista::insertar_Final(Libro* libro) {
	Nodo* aux = Ultimo();
	aux->Siguiente = new Nodo(libro, NULL);
}

//Como su nombre lo especifica el nodo se ira acomodando en la posicion dada siguinete, antes del final.
void Lista::insertar_Antes_De(Libro* libro, int x) {
	Nodo* Anterior;
	Anterior = Primer_Lista;

	while (Anterior->Siguiente && Anterior->Siguiente->Valor->get_Clave() != x) {
		Anterior = Anterior->Siguiente;
	}

	Anterior->Siguiente = new Nodo(libro, Anterior->Siguiente);
}

//Como su nombre lo especifica, se buscará un nodo en particular aunque en este caso se busca un libro.
Nodo* Lista::buscar_Nodo(int buscar) {
	Nodo* aux;

	if (!lista_Vacia()) {
		aux = Primer_Lista;
		while (aux != NULL) {
			if (aux->Valor->get_Clave() == buscar) {
				return aux;
			}
			aux = aux->Siguiente;
		}
		return NULL;
	}
	else {
		return NULL;
	}
}

//Borramos un libro con ayuda de la clave dada, ya que a la hora de que se ingresa, el programa la busca y sino se encuentra, advierte.
void Lista::Borrar(int clave_Libro) {
	Nodo* Anterior, *nodo;

	nodo = Primer_Lista;
	Anterior = NULL;

	while (nodo && nodo->Valor->get_Clave() != clave_Libro) {
		Anterior = nodo;
		nodo = nodo->Siguiente;
	}
	if (!nodo || nodo->Valor->get_Clave() != clave_Libro) {
		cout << "\nEl nodo que intenta borrar, no existe." << endl;
		return;
	}
	else {
		if (!Anterior) Primer_Lista = nodo->Siguiente;
		else {
			Anterior->Siguiente = nodo->Siguiente;
			delete nodo;
			cout << "El libro fue borrado con exito!\n";
		}
	}
}

void Lista::modificar_Nodo(Libro* libro, int mod) {
	Nodo* aux = buscar_Nodo(mod);

	if (aux != NULL) {
		aux -> Valor = libro;
		cout << "\nEl libro fue modificado." << endl;
	} else {
		cout << "\nEl nodo que intenta modificar, no existe." << endl;
	}
}

void Lista::visualizar_Nodo(int Viz) {
	Nodo* aux = buscar_Nodo(Viz);

	if (aux != NULL) {
		aux->Valor->mostrar_Datos();
	}
	else {
		cout << "\nEl nodo que intenta visualiza, no existe." << endl;
	}
}

bool Lista::lista_Vacia() {
	return Primer_Lista == NULL;
}

void Lista::mostrar() {
	Nodo* aux;

	if (!lista_Vacia()) {
		aux = Primer_Lista;
		while (aux) {
			cout << "--------------------------------\n";
			aux->Valor->mostrar_Datos();
			aux = aux->Siguiente;
		}
	}
}

Nodo* Lista::Ultimo() {
	Nodo* Temp = Primer_Lista;
	if (!lista_Vacia())
		while (Temp->Siguiente)
			Temp = Temp->Siguiente;
	return Temp;
}