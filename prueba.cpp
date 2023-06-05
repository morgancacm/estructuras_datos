#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void convertirInfijaPostfija();
void evaluarExpresionPostfija();
bool validacion(const std::string& infija);
bool expresionCorrecta(const std::string& infija);
bool pilaLlena();
bool pilaLlenaPO();
bool pilaVacia();
bool pilaVaciaPO();
void empilar(char dato);
void empilarPO(int dato);
double desempilar();
double desempilarPO();
int prioridad(char operador);
int designarPO(int operando1, char operador, int operando2);

// variables para almacenar las expresiones
char infija[20];
char postfija[20];

// pilas
char pila[20];
int pilaOperandos[20];

int tope = -1;
int topePO = -1;

int main() {
    convertirInfijaPostfija();
    evaluarExpresionPostfija();
    return 0;
}

// función para convertir la expresión a postfija
void convertirInfijaPostfija() {
    cout << "Ingrese la expresion a evaluar: ";
    cin.getline(infija, 20);
    int k = 0;

    if (expresionCorrecta(infija)) {
        if (validacion(infija)) {
            for (int i = 0; i < strlen(infija); i++) {
                if (isalpha(infija[i])) {
                    postfija[k] = infija[i];
                    k++;
                }
                else if (infija[i] == '(') {
                    empilar(infija[i]);
                }
                else if (infija[i] == ')') {
                    while (!pilaVacia() && pila[tope] != '(') {
                        postfija[k] = desempilar();
                        k++;
                    }
                    if (!pilaVacia() && pila[tope] == '(') {
                        desempilar();
                    }
                }
                else {
                    while (!pilaVacia() && prioridad(infija[i]) <= prioridad(pila[tope])) {
                        postfija[k] = desempilar();
                        k++;
                    }
                    empilar(infija[i]);
                }
            }
            while (!pilaVacia()) {
                postfija[k] = desempilar();
                k++;
            }
        }
        else {
            cout << "Error: ingrese la expresion correctamente, por favor intente nuevamente." << endl;
        }
    }
    else {
        cout << "Error: para convertir la expresion debe contener operandos y operadores" << endl;
    }

    cout << "La expresion en postfija es: " << postfija << endl;
}

// función para evaluar la expresión en postfija
void evaluarExpresionPostfija() {
    int resultado, sobra;
    double valor;
    char operador;
    double operando1, operando2;
    for (int i = 0; i < strlen(postfija); i++) {
        if (isalpha(postfija[i])) {
            cout << "Ingrese el valor para el operando " << postfija[i] << ": ";
            cin >> valor;
            empilarPO(valor);
        }
        else {
            operando1 = desempilarPO();
            operando2 = desempilarPO();
            operador = postfija[i];
            resultado = designarPO(operando1, operador, operando2);
            empilarPO(resultado);
        }
    }
    cout << "El resultado de la expresion " << postfija << " es: " << pilaOperandos[topePO];
}

// función para validar que la expresión infija contenga lo que se necesita
bool expresionCorrecta(const std::string& infija) {
    bool contieneOperando = false;
    bool contieneOperador = false;

    for (char select: infija) {
        if (isalpha(select)) {
            contieneOperando = true;
        }
        else if (select == '+' || select == '-' || select == '*' || select == '/' || select == '(' || select == ')') {
            contieneOperador = true;
        }
    }
    if (!contieneOperando || !contieneOperador) {
        return false;
    }
    return true;
}

// función para validar que los datos que se ingresan en la expresión infija sean correctos
bool validacion(const std::string& infija) {
    for (char select: infija) {
        if (!isalpha(select) && select != '+' && select != '-' && select != '*' && select != '/' && select != '^' && select != '(' && select != ')') {
            return false;
        }
    }
    return true;
}

// función para saber si la pila de operandos está vacía
bool pilaVaciaPO() {
    if (topePO == -1) {
        return true;
    }
    else {
        return false;
    }
}

// función para saber si la pila de operandos está llena 
bool pilaLlenaPO() {
    if (topePO == 20 - 1) {
        return true;
    }
    else {
        return false;
    }
}

// función para empilar un dato a la pila de operandos
void empilarPO(int dato) {
    if (pilaLlenaPO()) {
        cout << "Stack Overflow" << endl;
    }
    else {
        topePO++;
        pilaOperandos[topePO] = dato;
    }
}

// función para desempilar un dato a la pila de operandos
double desempilarPO() {
    if (pilaVaciaPO()) {
        cout << "Stack Underflow" << endl;
        return ' ';
    }
    else {
        char letra = pilaOperandos[topePO];
        topePO--;
        return letra;
    }
}

// función para hacer las operaciones en la evaluación de la expresión postfija
int designarPO(int operando1, char operador, int operando2) {
    int resultado;
    if (operador == '+') {
        resultado = operando1 + operando2;
    }
    if (operador == '-') {
        resultado = operando1 - operando2;
    }
    if (operador == '*') {
        resultado = operando1 * operando2;
    }
    if (operador == '/') {
        if (operando2 == 0) {
            cout << "Error: no se puede dividir entre 0" << endl;
        }
        resultado = operando1 / operando2;
    }
    if (operador == '^') {
        resultado = pow(operando1, operando2);
    }
    // cout << resultado << endl;
    return resultado;
}

// función para saber si la pila está llena
bool pilaLlena() {
    return tope == 20 - 1;
}

// función para saber si la pila está vacía
bool pilaVacia() {
    return tope == -1;
}

// función para empilar un dato en la pila
void empilar(char dato) {
    if (pilaLlena()) {
        cout << "Stack Overflow" << endl;
    }
    else {
        tope++;
        pila[tope] = dato;
    }
}

// función para desempilar un dato de la pila
double desempilar() {
    if (pilaVacia()) {
        cout << "Stack Underflow" << endl;
        return ' ';
    }
    else {
        char letra = pila[tope];
        tope--;
        return letra;
    }
}

// función que le otorga la prioridad a los operadores dentro de la pila
int prioridad(char operador) {
    if (operador == '^') {
        return 3;
    }
    else if (operador == '*' || operador == '/') {
        return 2;
    }
    else if (operador == '+' || operador == '-') {
        return 1;
    }
    else {
        return 0;
    }
}