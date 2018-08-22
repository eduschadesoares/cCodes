#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <sys/wait.h>

// Constantes
const int b = 1;
const int Kb = 1024;
const int Mb = 1024 * 1024;
const int Gb = 1024 * 1024 * 1024;

// Protótipos
void createFileFunction();
void createFileSyscall();
void menu();

// C++ stuff
using namespace std;

// The very beginning
int main() {
    menu();
}

void createFileFunction() {
    printf("Criando arquivos por função\n");
    for(int i=1; i<=4; i++) {
        if(i == 1) {
            printf("Criando %iº arquivo de 1b.\n", i);
            printf("Arquivo file%i.in criado!\n", i);
        }
        if (i == 2) {
            printf("Criando %iº arquivo de 1Kb.\n", i);
            printf("Arquivo file%i.in criado!\n", i);
        }
        if (i == 3) {
            printf("Criando %iº arquivo de 1Mb.\n", i);
            printf("Arquivo file%i.in criado!\n", i);
        }
        if (i == 4) {  
            printf("Criando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            printf("Arquivo file%i.in criado!\n", i);
        }
    }
}

void createFileSyscall() {
    printf("Sys\n");
}
void menu() {
    int choice;
    printf("1 - Criar os arquivos\n");
    printf("2 - Copiar os arquivos\n");
    cin >> choice;
    
    switch(choice) {
        case 1:
            createFileFunction();
            break;
        case 2:
            createFileSyscall();
            break;
        default:
            printf("Mano, ajuda ai\n");
            menu();
            break;
    }
}   