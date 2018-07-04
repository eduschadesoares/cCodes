#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <clocale>
#include <cstdio>
#include <ctime>

#define p 512               // PÁGINAS
#define f 256               // FRAMES
#define by 8192 			// 8KB
#define maxEnd 4194304      // 4MB

using namespace std;

int n;
int pag[p], frame[f] = {}, pagUsadas[f], enderecos[maxEnd];



void print(const std::string& str) {
    for (size_t i = 0; i != str.size(); ++i) { 
        cout << str[i];
        usleep(20000);
    }
}

void erro(int val){
	cout << "Erro :/" << endl;
	//print("Erro:\n");
}

bool confereSeJaFoiUsado(int valor){
	for (int i=0; i<f; i++){
		if (pagUsadas[i] == valor) return true; // página já foi utilizada
	}
	return false; // página livre
}

void randomizaPaginas(){
	for (int i = 0; i < f; i++){
		frame[i] = i;
	}
	for (int i = 0; i < f; i++) {    // whoop hahah mistureba
	    int temp = frame[i];
	    int random = rand() % f;
	    frame[i] = frame[random];
	    frame[random] = temp;
	}
}

void init(){
	for (int i = 0; i < maxEnd; i++){
		enderecos[i] = -1;
	}
	
	srand(time(NULL));
	for(int i=0; i<p; i++){ //isso nem precisa na vdd
		pag[i] = i;
	}
	randomizaPaginas();
}

void goodbye(){
	//system("clear");
	cout << "Falou!" << endl;
	exit(1);
}

void criarEnderecos(){
	print("Insira a quantidade de endereços: ");
	cin >> n;
	
	if(n > maxEnd) {
		erro(2);
	} else {
		if (n < 0) {
			erro(1);
		} else {
			if (n == 0) {
				goodbye();
			} else {
				for (int i = 0; i < n; i++) {    // whoop hahah mistureba
		    		enderecos[i] = rand() % maxEnd;
				}
			}
		}
	}
	/*for (int i=0; i<n; i++){
		printf(" %d\n", enderecos[i]);
	}*/
}

void paginacao(){
	int m = 0, valor = 0, paginaX = 0, frameX = 0, deslocamento = 0;
	while (m < n){
	
	// meu irmao, é aqui que a parada complica 
		for (int i = 0; i<n; i++){
			valor = enderecos[i];
			paginaX = valor / by;	
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	//init();
	criarEnderecos();
	//paginacao();

	return 0;
}


