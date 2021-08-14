#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int escolherNumero() {
    int numero = 0;

    while(numero < 48 || numero > 57){
        if (numero < 48 || numero > 57) {
            numero = rand() % 100 + 48;
        } else {
            break;
        }
    }

    return numero;
}

int escolherLetraMaiuscula() {
    int letra = 0;

    while(letra < 65 || letra > 90){
        if (letra < 65 || letra > 90) {
            letra = rand() % 100 + 65;
        } else {
            break;
        }
    }

    return letra;
}

int escolherLetraMinuscula() {
    int letra = 0;

    while(letra < 97 || letra > 122){
        if (letra < 97 || letra > 122) {
            letra = rand() % 200 + 65;
        } else {
            break;
        }
    }

    return letra;
}

int escolherSimbolo1() {
    int simbolo = 0;

    while(simbolo < 33 || simbolo > 47){
        if (simbolo < 33 || simbolo > 47) {
            simbolo = rand() % 200 + 33;
        } else {
            break;
        }
    }

    return simbolo;
}


int escolherSimbolo2() {
    int simbolo = 0;

    while(simbolo < 58 || simbolo > 64){
        if (simbolo < 58 || simbolo > 64) {
            simbolo = rand() % 100 + 58;
        } else {
            break;
        }
    }

    return simbolo;
}

int escolherSimbolo3() {
    int simbolo = 0;

    while(simbolo < 91 || simbolo > 96){
        if (simbolo < 91 || simbolo > 96) {
            simbolo = rand() % 100 + 91;
        } else {
            break;
        }
    }

    return simbolo;
}

int escolherSimbolo4() {
    int simbolo = 0;

    while(simbolo < 123 || simbolo > 125){
        if (simbolo < 123 || simbolo > 125) {
            simbolo = rand() % 200 + 123;
        } else {
            break;
        }
    }

    return simbolo;
}

int escolherSimbolo5() {
    int simbolo = 0;

    while(simbolo < 128 || simbolo > 255){
        if (simbolo < 128 || simbolo > 255) {
            simbolo = rand() % 200 + 128;
        } else {
            break;
        }
    }

    return simbolo;
}

int sorteioTipo() {
    int tipo = 9;
    srand(time(NULL));

    while(tipo >= 8 || tipo < 0){
        if (tipo >= 8 || tipo < 0) {
            tipo = rand() % 10;
        } else {
            break;
        }
    }

    return tipo;
}

int main()
{


    srand(time(NULL));



    int qtdCaracteres = 12;

    char resposta1;



    do {
        printf("Deseja escolher a quantidade de caracteres da senha? (y/n)\n");
        scanf("%c", &resposta1);
        getchar();
    } while (resposta1 != 'y'&& resposta1 != 'n') ;

    if(resposta1 == 'y') {
        int resposta2 = 25;
        do {
            printf("Digite a quantidade desejada (máximo 24 caracteres)\n");
            scanf("%d", &resposta2);
            getchar();
        } while (resposta2 > 24);

        qtdCaracteres = resposta2;
    }

    printf("\nGerando senha...\n\n");

    int senha[qtdCaracteres];
    int tipoSenha[qtdCaracteres];


    int i=0;
    int tipo = -1;

    for(i=0; i < qtdCaracteres; i++) {
        senha[i] = -1;
        tipoSenha[i] = -1;
    }

    for(i = 0; i < qtdCaracteres; i++) {
        if(i > 0){
            while(tipo == tipoSenha[i-1]){
                tipo = sorteioTipo();

            }

        } else {
            tipo = sorteioTipo();

        }

        tipoSenha[i] = tipo;

        int caracter;

        switch(tipo) {
            case 0:
                caracter = escolherSimbolo1();
                break;
            case 1:
                caracter = escolherSimbolo2();
                break;
            case 2:
                caracter = escolherSimbolo3();
                break;
            case 3:
                caracter = escolherSimbolo4();
                break;
            case 4:
                caracter = escolherSimbolo5();
                break;
            case 5:
                caracter = escolherNumero();
                break;
            case 6:
                caracter = escolherLetraMaiuscula();
                break;
            case 7:
                caracter = escolherLetraMinuscula();
                break;

        }


        senha[i] = caracter;

    }

    printf("Sua senha: ");

    for(i = 0; i < qtdCaracteres; i++)
        printf("%c", senha[i]);

    printf("\n\n");






}
