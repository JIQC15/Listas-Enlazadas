// Listas Enlazadas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Lista.h"
#include "Libro.h"
//#include "Listas Enlazadas.h"

#include <iostream>
#include <conio.h>
#include <string>


using namespace std;

int main()
{
    Libro* libro = new Libro();
    Lista lista;

    int clave, opcion;
    string titulo = " ", autor = " ";

    do {
        system("cls");
        cout << "Bienvenido al programa \"LISTAS ENLAZADAS\"\n" << endl;
        cout << "MENU:" << endl;
        cout << "1) Introducir Libro en la lista.\n";
        cout << "2) Modificar Libro.\n";
        cout << "3) Visualizar Libro.\n";
        cout << "4) Borrar Libro.\n";
        cout << "5) Borrar Lista de libros\n";
        cout << "6) Visualizar todos los libros\n";
        cout << "7) Salir.\n";
        cout << "\n-> Ingrese la opcion que desea aplicar: ";
        cin >> opcion;
        
        switch (opcion) {
        case 1:
            Introducir_Libro(clave, titulo, autor, libro, lista);
            break;

        case 2:
            system("cls");
            cout << "Modificar Libro.\n" << endl;

            cout << "Favor de ingresar la clave del libro por modificar: ";
            cin >> clave;
            cin.ignore();

            cout << "Favor de ingresar el titulo del libro: ";
            getline(cin, titulo);//Util como lector de espacios en una cadena de espacios.

            cout << "Favor de ingresar el autor del libro: ";
            getline(cin, autor);

            libro = new Libro(clave, titulo, autor);
            lista.modificar_Nodo(libro, clave);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Visualizar Libro\n" << endl;

            cout << "Favor de ingresar la clave del libro: ";
            cin >> clave;

            system("cls");
            cout << "Visualizar Libro\n" << endl;
            cout << "El libro encontrado con la clave " << clave << " es:" << endl;
            lista.visualizar_Nodo(clave);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Borrar Libro.\n" << endl;

            cout << "Favor de ingresar la clave del libro: ";
            cin >> clave;

            lista.Borrar(clave);
            system("pause");
            break;
            
        case 5:
            system("cls");
            cout << "Borrar Lista de libros\n" << endl;

            lista.~Lista();
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "Visualizar todos los libros.\n" << endl;

            lista.mostrar();
            system("pause");
            break;

        case 7:
            system("cls");
            cout << "Ha salido con exito, gracias!" << endl;
            break;
        }
    } while (opcion != 7);

    return 0;
}

void Introducir_Libro(int& clave, string& titulo, string& autor, Libro*& libro, Lista& lista)
{
    system("cls");
    cout << "Introducir Libro en la lista.\n" << endl;

    cout << "Favor de ingresar la clave del libro: ";
    cin >> clave;
    cin.ignore();//limpia el bufer saturado.

    cout << "Favor de ingresar el titulo del libro: ";
    getline(cin, titulo);

    cout << "Favor de ingresar el Autor del libro: ";
    getline(cin, autor);

    libro = new Libro(clave, titulo, autor);
    lista.insertar_Nuevo(libro);
    system("pause");
}
