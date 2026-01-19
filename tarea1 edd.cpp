#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ArregloUnidimensional {
private:
    string elementos[10];
    int tamano;
    static const int CAP_MAX = 10;

public:
    ArregloUnidimensional() {
        tamano = 0;
    }

    void insertar(int indice, const string& nombre) {
        if (tamano == CAP_MAX) {
            throw runtime_error("Arreglo lleno.");
        }
        if (indice < 0 || indice > tamano) {
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }
        if (nombre.empty()) return;

        for (int i = tamano; i > indice; i--) {
            elementos[i] = elementos[i - 1];
        }
        elementos[indice] = nombre;
        tamano++;
    }

    string eliminar(int indice) {
        if (indice < 0 || indice >= tamano) {
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }
        string eliminado = elementos[indice];

        for (int i = indice; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }

        elementos[tamano - 1] = "";
        tamano--;
        return eliminado;
    }

    string obtener(int indice) {
        if (indice < 0 || indice >= tamano) {
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }
        return elementos[indice];
    }

    int getTamano() {
        return tamano;
    }

    bool estaLleno() {
        return tamano == CAP_MAX;
    }

    void imprimir() {
        if (tamano == 0) {
            cout << "[] (arreglo vacio)\n";
            return;
        }
        cout << "[\n";
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i];
            if (i < tamano - 1) cout << ".\n";
        }
        cout << "\n]\n";
    }
};

int main() {
    ArregloUnidimensional arr;

    arr.insertar(0, "Hugo");
    arr.insertar(1, "Paco");
    arr.insertar(1, "Luis");
    arr.insertar(2, "Ana");
    arr.insertar(3, "Javier");
    arr.insertar(4, "Maria");
    arr.insertar(5, "Ena");
    arr.insertar(6, "Martha");
    arr.insertar(7, "Bertha");
    arr.insertar(8, "Gaby");

    cout << "Arreglo lleno\n";
    arr.imprimir();

    try {
        arr.insertar(9, "Donald Trompas");
    } catch (runtime_error &e) {
        cout << "\n" << e.what() << "\n";
    }

    string eliminado = arr.eliminar(0);
    cout << "\nEliminado: " << eliminado << "\n";
    arr.imprimir();

    arr.eliminar(4);
    cout << "Despues de eliminar indice 4\n";
    arr.imprimir();

    return 0;
}

