#include <iostream>
using namespace std;

struct arbolA {
    int dato;
    arbolA* sub_izq;
    arbolA* sub_der;
} *R, *P, *aux1, *aux2;

struct arbolB {
    int dato;
    arbolB* sub_izq;
    arbolB* sub_der;
} *R2, *P2, *aux3, *aux4;

int peso1 = 0;
int peso2 = 0;
int peso3 = 0;
int peso4 = 0;

void recorrerIzquierda1(arbolA* P) {
    if (P->sub_izq != nullptr) {
        recorrerIzquierda1(P->sub_izq);
        peso1++;
    }
}

void recorrerDerecha2(arbolA* P) {
    if (P->sub_der != nullptr) {
        recorrerDerecha2(P->sub_der);
        peso2++;
    }
}

void recorrerIzquierda3(arbolB* P2) {
    if (P2->sub_izq != nullptr) {
        recorrerIzquierda3(P2->sub_izq);
        peso3++;
    }
}

void recorrerDerecha4(arbolB* P2) {
    if (P2->sub_der != nullptr) {
        recorrerDerecha4(P2->sub_der);
        peso4++;
    }
}

void equivalentes(int peso1, int peso2, int peso3, int peso4) {
    if (peso1 == peso3 && peso2 == peso4) {
        cout << "Son equivalentes" << endl;
    } else {
        cout << "No son equivalentes" << endl;
    }
}

void crearArbol1() {
    char OP = 'S';
    while (OP == 'S') {
        P = new arbolA;
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
        cout << "Desea añadir otro nodo? (S/N): ";
        cin >> OP;
    }
}

void crearArbol2() {
    char OP = 'S';
    while (OP == 'S') {
        P2 = new arbolB;
        if (P2 == nullptr) {
            cout << "No hay memoria disponible." << endl;
        } else {
            cout << "Introduzca un valor: ";
            cin >> P2->dato;
            P2->sub_izq = nullptr;
            P2->sub_der = nullptr;
            if (R2 == nullptr) {
                R2 = P2;
            } else {
                aux3 = R2;
                while (aux3 != nullptr) {
                    aux4 = aux3;
                    if (P2->dato <= aux4->dato) {
                        aux3 = aux3->sub_izq;
                    } else {
                        aux3 = aux3->sub_der;
                    }
                }
                if (P2->dato <= aux4->dato) {
                    aux4->sub_izq = P2;
                } else {
                    aux4->sub_der = P2;
                }
            }
        }
        cout << "Desea añadir otro nodo? (S/N): ";
        cin >> OP;
    }
}

int main() {
    crearArbol1();
    crearArbol2();
    recorrerIzquierda1(R);
    recorrerIzquierda3(R2);
    recorrerDerecha2(R);
    recorrerDerecha4(R2);
    equivalentes(peso1, peso2, peso3, peso4);
    return 0;
}
