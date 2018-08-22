#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// Constantes
const int b = 1;
const int Kb = 1024;
const int Mb = 1024 * 1024;
const int Gb = 1024 * 1024 * 1024;

struct timeval tempo1, tempo2;
struct timezone tzp;

// Protótipos
void createFileFunction();
void createFileSyscall();
void fileFunctionCreator(int, int);
void fileCreator();
void menu();

// C++ stuff
using namespace std;

// The very beginning
int main() {
    menu();
}

void createFileFunction() {
    printf("\nCriando arquivos por função!\n\n");
    for(int i=1; i<=4; i++) {
        if(i == 1) { //b
            printf("Criando %iº arquivo de 1b.\n", i);
            fileFunctionCreator(i, b);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 2) { //Kb
            printf("Criando %iº arquivo de 1Kb.\n", i);
            fileFunctionCreator(i, Kb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 3) { //Mb
            printf("Criando %iº arquivo de 1Mb.\n", i);
            fileFunctionCreator(i, Mb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 4) { //Gb
            printf("Criando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            fileFunctionCreator(i, Gb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
    }
}

void createFileSyscall() {
    printf("\nCriando arquivos por syscall!\n\n");
}

void fileFunctionCreator(int num, int size) {
    FILE* file;
    double tempo;    
    char fileName[64];
    sprintf(fileName, "file%i.txt", num);

    // Openning file
    file = fopen(fileName, "w");


    gettimeofday(&tempo1, &tzp); // Start timing

    for(int i=0; i < size; i++) fputc('o', file);

    gettimeofday(&tempo2, &tzp); // End timing


    //Closing file
    fclose(file);

    tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

    printf("Tempo: %.30f\n", tempo);
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