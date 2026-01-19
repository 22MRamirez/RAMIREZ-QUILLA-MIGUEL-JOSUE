#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MatrizBI {
private:
    vector<vector<string>> matriz;

public:
    MatrizBI(vector<vector<string>> m) { matriz = m; }

    void imprimir() {
        for (auto &fila : matriz) {
            for (auto &val : fila) cout << val << "\t";
            cout << "\n";
        }
    }

    void insertarFila(int pos) {
        if (pos < 0 || pos > matriz.size()) return;
        vector<string> fila(matriz[0].size());
        cout << "Ingrese " << fila.size() << " valores:\n";
        for (auto &x : fila) cin >> x;
        matriz.insert(matriz.begin() + pos, fila);
    }

    void insertarColumna(int pos) {
        if (pos < 0 || matriz.empty()) return;
        cout << "Ingrese valores para la columna:\n";
        for (auto &fila : matriz) {
            string val; cin >> val;
            if (pos <= fila.size()) fila.insert(fila.begin() + pos, val);
        }
    }

    void eliminarFila(int pos) {
        if (pos >= 0 && pos < matriz.size()) matriz.erase(matriz.begin() + pos);
    }

    void eliminarColumna(int pos) {
        for (auto &fila : matriz)
            if (pos >= 0 && pos < fila.size()) fila.erase(fila.begin() + pos);
    }

    void buscarValor(string val) {
        bool found=false;
        for(int i=0;i<matriz.size();i++)
            for(int j=0;j<matriz[i].size();j++)
                if(matriz[i][j]==val){
                    cout<<"Encontrado en ("<<i<<","<<j<<")\n";
                    found=true;
                }
        if(!found) cout<<"No encontrado\n";
    }

    void buscarIndice(int i,int j){
        if(i>=0 && i<matriz.size() && j>=0 && j<matriz[i].size())
            cout<<"Valor: "<<matriz[i][j]<<"\n";
        else cout<<"Indice invalido\n";
    }

    void recorrerColumnas(){
        if(matriz.empty()) return;
        for(int j=0;j<matriz[0].size();j++){
            for(int i=0;i<matriz.size();i++)
                cout<<matriz[i][j]<<"\t";
            cout<<"\n";
        }
    }
};

int main() {

    vector<vector<string>> datos = {
        {"\nHugo","Paco","Luis","Jesus","Maria"},
        {"Jose","Martha","Ena","Bertha","Lula"},
        {"Putin","Ana","Luisa","Jesusa","Mario"},
        {"Xi","Fi","Fu","Li","Ju"},
        {"Rena","Paca","Leo","Javier","Bruno"}
    };

    MatrizBI mat(datos);

    int op;
    do {
        cout<<"\n--- MENU MATRIZ ---\n";
        cout<<"1. Insertar fila\n";
        cout<<"2. Insertar columna\n";
        cout<<"3. Eliminar fila\n";
        cout<<"4. Eliminar columna\n";
        cout<<"5. Buscar valor\n";
        cout<<"6. Buscar indice\n";
        cout<<"7. Recorrer por filas\n";
        cout<<"8. Recorrer por columnas\n";
        cout<<"9. Imprimir matriz\n";
        cout<<"0. Salir\n";
        cout<<"Opcion: ";
        cin>>op;

        if(op==1){int pos;cout<<"Pos fila: ";cin>>pos;mat.insertarFila(pos);}
        else if(op==2){int pos;cout<<"Pos columna: ";cin>>pos;mat.insertarColumna(pos);}
        else if(op==3){int pos;cout<<"Fila a eliminar: ";cin>>pos;mat.eliminarFila(pos);}
        else if(op==4){int pos;cout<<"Columna a eliminar: ";cin>>pos;mat.eliminarColumna(pos);}
        else if(op==5){string val;cout<<"Valor: ";cin>>val;mat.buscarValor(val);}
        else if(op==6){int i,j;cout<<"Fila y columna: ";cin>>i>>j;mat.buscarIndice(i,j);}
        else if(op==7) mat.imprimir();
        else if(op==8) mat.recorrerColumnas();
        else if(op==9) mat.imprimir();

    } while(op!=0);

    return 0;
}
