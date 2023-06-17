#include <iostream>
using namespace std;

struct arbol {
    int dato;
    arbol* sub_izq;
    arbol* sub_der;
} *R, *P, *aux1, *aux2;

int bolasRojas = 0;
int bolasDoradas = 0;

void preOrden(arbol* P) {
    if (P != nullptr) {
        if ((P->sub_izq == nullptr) && (P->sub_der == nullptr)) {
            bolasRojas++;
        } else {
            bolasDoradas++;
        }
        preOrden(P->sub_izq);
        preOrden(P->sub_der);
    }
}

void crearArbol() {
    char OP = 'S';
    while (OP == 'S') {
        P = new arbol;
        if (P == nullptr) {
            cout << "No hay memoria disponible." << endl;
        } else {
            cout << "Introduzca un valor: ";
            cin >> P->dato;
            P->sub_izq = nullptr;
            P->sub_der = nullptr;
            if (R == nullptr) {
                R = P;
            } else {
                aux1 = R;
                while (aux1 != nullptr) {
                    aux2 = aux1;
                    if (P->dato <= aux2->dato) {
                        aux1 = aux1->sub_izq;
                    } else {
                        aux1 = aux1->sub_der;
                    }
                }
                if (P->dato <= aux2->dato) {
                    aux2->sub_izq = P;
                } else {
                    aux2->sub_der = P;
                }
            }
        }
        cout << "Desea agregar otro nodo? (S/N): ";
        cin >> OP;
    }
}

int main() {
    crearArbol();
    preOrden(R);
    cout << "Cantidad de BOLAS ROJAS del arbol: " << bolasRojas << endl;
    cout << "Cantidad de BOLAS DORADAS del arbol: " << bolasDoradas << endl;
    return 0;
}
