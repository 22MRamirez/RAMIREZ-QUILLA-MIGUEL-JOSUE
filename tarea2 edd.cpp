#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ArregloUnidimensional{
private:
    string elementos[10];
    int tamano;
    static const int CAP_MAX = 10;

public:
    ArregloUnidimensional(){
        tamano = 0;
    }

    void insertar(int indice, const string& nombre){
        if (tamano == CAP_MAX) throw runtime_error("Arreglo lleno.");
        if (indice < 0 || indice > tamano) throw out_of_range("Indice fuera de rango.");
        if (nombre.empty()) return;

        for (int i = tamano; i > indice; i--){
            elementos[i] = elementos[i - 1];
        }
        elementos[indice] = nombre;
        tamano++;
    }

    void insertarOrdenado(const string& nombre){
        if (tamano == CAP_MAX) throw runtime_error("Arreglo lleno.");
        int i = tamano - 1;
        while (i >= 0 && elementos[i] > nombre){
            elementos[i + 1] = elementos[i];
            i--;
        }
        elementos[i + 1] = nombre;
        tamano++;
    }

    string eliminar(int indice){
        if (indice < 0 || indice >= tamano) throw out_of_range("Indice fuera de rango.");
        string eliminado = elementos[indice];
        for (int i = indice; i < tamano - 1; i++){
            elementos[i] = elementos[i + 1];
        }
        elementos[tamano - 1] = "";
        tamano--;
        return eliminado;
    }

    int buscarValor(const string& valor){
        for (int i = 0; i < tamano; i++){
            if (elementos[i] == valor) return i;
        }
        return -1;
    }

    void ordenar() {
    for (int i = 0; i < tamano - 1; i++){
        for (int j = 0; j < tamano - i - 1; j++){
            if (elementos[j] > elementos[j + 1]){
                swap(elementos[j], elementos[j + 1]);
            }
        }
    }
}

    void invertir() {
        for (int i = 0; i < tamano / 2; i++){
            swap(elementos[i], elementos[tamano - 1 - i]);
        }
    }

    int busquedaBinaria(const string& valor){
        int izq = 0, der = tamano - 1;
        while (izq <= der){
            int mid = (izq + der) / 2;
            if (elementos[mid] == valor) return mid;
            if (elementos[mid] < valor) izq = mid + 1;
            else der = mid - 1;
        }
        return -1;
    }

    void imprimir(){
        if (tamano == 0){
            cout << "[] (arreglo vacio)\n";
            return;
        }
        cout << "[ ";
        for (int i = 0; i < tamano; i++){
            cout << elementos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << " ]\n";
    }
};

int main() {
    ArregloUnidimensional arr;
    int opcion;
    string valor;
    int indice;

    do {
        cout << "\n1. Insertar en posicion\n";
        cout << "2. Insertar en arreglo ordenado\n";
        cout << "3. Eliminar por indice\n";
        cout << "4. Buscar por valor\n";
        cout << "5. Ordenar (alfabeticamente)\n";
        cout << "6. Invertir arreglo\n";
        cout << "7. Busqueda binaria\n";
        cout << "8. Mostrar arreglo\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        try {
            switch (opcion) {
                case 1:
                    cout << "Indice: ";
                    cin >> indice;
                    cin.ignore();
                    cout << "Nombre: ";
                    getline(cin, valor);
                    arr.insertar(indice, valor);
                    break;

                case 2:
                    cout << "Nombre: ";
                    getline(cin, valor);
                    arr.insertarOrdenado(valor);
                    break;

                case 3:
                    cout << "Indice a eliminar: ";
                    cin >> indice;
                    cin.ignore();
                    cout << "Eliminado: " << arr.eliminar(indice) << "\n";
                    break;

                case 4:
                    cout << "Valor a buscar: ";
                    getline(cin, valor);
                    indice = arr.buscarValor(valor);
                    if (indice == -1) cout << "No encontrado\n";
                    else cout << "Encontrado en posicion " << indice << "\n";
                    break;

                case 5:
                    arr.ordenar();
                    cout << "Arreglo ordenado\n";
                    break;

                case 6:
                    arr.invertir();
                    cout << "Arreglo invertido\n";
                    break;

                case 7:
                    cout << "Valor a buscar (binaria): ";
                    getline(cin, valor);
                    indice = arr.busquedaBinaria(valor);
                    if (indice == -1) cout << "No encontrado\n";
                    else cout << "Encontrado en posicion " << indice << "\n";
                    break;

                case 8:
                    arr.imprimir();
                    break;

                case 0:
                    cout << "Saliendo...\n";
                    break;

                default:
                    cout << "Opcion invalida\n";
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (opcion != 0);

    return 0;
}
