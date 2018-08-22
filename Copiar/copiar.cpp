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
void menu();

// C++ stuff
using namespace std;

// The very beginning
int main() {
    menu();
}

void menu() {
    int choice;
    printf("1 - Criar os arquivos\n");
    printf("2 - Copiar os arquivos\n");
    cin >> choice;
}