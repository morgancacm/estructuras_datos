#include <iostream>

using namespace std;

struct arbol {
    int dato;
    arbol *sub_izq;
    arbol *sub_der;
};

arbol *R = nullptr;
arbol *P = nullptr;
arbol *aux1 = nullptr;
arbol *aux2 = nullptr;
int peso = 0;

void preOrden(arbol *P) {
    if (P != nullptr) {
        peso = peso + 1;
        preOrden(P->sub_izq);
        preOrden(P->sub_der);
    }
}

void crearArbol() {
    char OP;
    do {
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
        do {
            cout << "Desea agregar otro nodo? (S/N): ";
            cin >> OP;
        } while ((OP != 'S') && (OP != 'N'));
    } while (OP == 'S');
}

int main() {
    crearArbol();
    preOrden(R);
    cout << "El peso total es de: " << peso << endl;
    return 0;
}
