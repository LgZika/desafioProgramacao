#include <iostream>

using namespace std;

struct {
    int numerador1, numerador2, denominador1, denominador2, numeradorTemp, denominadorTemp, mdc;
    char op;
} fracao;


void adicao(){
    fracao.numeradorTemp = (fracao.numerador1 * fracao.denominador2);    
    fracao.denominadorTemp = (fracao.numerador2 * fracao.denominador1);    

    cout << "O Resultado da operacao eh: " << ((fracao.numeradorTemp / fracao.mdc) + (fracao.denominadorTemp / fracao.mdc)) << "/" << fracao.mdc <<endl;
}

void subtracao(){
    cout << "O Resultado da operacao eh: " << ((fracao.numerador1 * fracao.denominador2) - (fracao.numerador2 * fracao.denominador1)) << "/" << fracao.mdc <<endl;
}

void multiplicacao(){
    cout << "O Resultado da operacao eh: " << (fracao.numerador1 * fracao.numerador2) << "/" << (fracao.denominador2 * fracao.denominador1) << endl;
}

void divisao(){
    cout << "O Resultado da operacao eh: " << (fracao.numerador1 * fracao.denominador2) << "/" << (fracao.numerador2 * fracao.denominador1) << endl;
}

void maximoDivisorComum(){
    int r, num1, num2;
    num1 = fracao.denominador1;
    num2 = fracao.denominador2;

    while((num1 % num2) > 0){
        r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    fracao.mdc = num2;
}

void simplificaFracao(){
    int x = 2;
    while(fracao.denominadorTemp % fracao.numeradorTemp == 0){
        fracao.numeradorTemp / x;
        fracao.denominadorTemp / x;
    }
}

int main(){
    cout << "Digite o numerador da primeira fração: ";
    cin >> fracao.numerador1;
    cout << "Digite o denominador da primeira fração: ";
    cin >> fracao.denominador1;
    if(fracao.denominador1 == 0){
        cout << "Nao existe divisao por 0." << endl;
        return -1;
    }
    cout << "Digite o numerador da segunda fração: ";
    cin >> fracao.numerador2;
    cout << "Digite o denominador da segunda fração: ";
    cin >> fracao.denominador2;
     if(fracao.denominador2 == 0){
        cout << "Nao existe divisao por 0." << endl;
        return -1;
    }
    cout << "Escolha a operação (+, -, *, /): ";
    cin >> fracao.op;

    maximoDivisorComum();

    switch(fracao.op){
        case '+': adicao(); break;
        case '-': subtracao(); break;
        case '*': multiplicacao(); break;
        case '/': divisao(); break;
        default: cout << "Opcao Invalida"; break;
    }
    return 0;
}