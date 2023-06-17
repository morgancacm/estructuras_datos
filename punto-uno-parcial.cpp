#include <iostream>
#include <string>
using namespace std;

struct cola {
    string dependencia;
    cola* sig;
    cola* ant;
} *frente, *P, *fin;

bool colaLlena() {
    P = new cola;
    if (P == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool colaVacia() {
    if (frente == nullptr) {
        return true;
    } else {
        return false;
    }
}

int prioridad(cola* P) {
    if (P->dependencia == "atencion al cliente") {
        return 1;
    } else if (P->dependencia == "recursos humanos") {
        return 2;
    } else if (P->dependencia == "financiera") {
        return 3;
    } else if (P->dependencia == "tecnico operativa") {
        return 4;
    }
    return 0;
}

void simulacionLlegada() {
    if (colaLlena()) {
        cout << "No se aceptan más trabajos." << endl;
    } else {
        bool trabajosImpresion = true;
        while (trabajosImpresion) {
            P = new cola;
            cout << "Ingrese la dependencia del trabajo (o 'fin' para finalizar): ";
            cin >> P->dependencia;
            if (P->dependencia == "fin") {
                trabajosImpresion = false;
                break;
            }
            P->sig = nullptr;
            P->ant = nullptr;
            if (colaVacia()) {
                frente = P;
                fin = P;
            } else if (prioridad(P->dependencia) >= prioridad(fin->dependencia)) {
                fin->sig = P;
                P->ant = fin;
                frente = P;
            } else if (prioridad(P->dependencia) <= prioridad(fin->dependencia)) {
                fin->ant = P;
                P->sig = fin;
                fin = P;
            }
        }
        if (colaVacia()) {
            cout << "No hay trabajos para imprimir." << endl;
        } else {
            P = frente;
            while (P != nullptr) {
                cout << P->dependencia << endl;
                P = P->sig;
            }
        }
    }
}

int main() {
    simulacionLlegada();
    return 0;
}
