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

int n, endereco;
int pag[p], frame[f] = {}, pagUsadas[f];



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

int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void randomizaPaginas(){
	int randNum;
	bool check;
	srand(time(NULL));

	//Vai inserir um valor no vetor pag sem repetição

	int counter = 0, pos;
	while(counter <= f) {
	    pos = rand() % p;
		if(pag[pos] == -1) {

			do {
				check = true;
				randNum = random(0, f);
				
				for(int j = 0; j < p; j++) {
					if(randNum == pag[j]) {
						check = false;
						break;
					}
				}

			} while(!check);

			pag[pos] = randNum;
			counter += 1;
		}
	}

	for(int i = 0; i < p; i++) {
		cout << pag[i] << endl;
	}
}

void init(){
	for(int i=0; i<f; i++){ //isso nem precisa na vdd
		frame[i] = i;
		//cout << frame[i] << endl;
	}

	for(int i=0; i<p; i++){ //isso nem precisa na vdd
		pag[i] = -1;
		//cout << pag[i] << endl;
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
		    		endereco = rand() % maxEnd;
					//paginacao(endereco);
				}
			}
		}
	}
	/*for (int i=0; i<n; i++){
		printf(" %d\n", enderecos[i]);
	}*/
}

void paginacao(int endereco){
	int m = 0, valor = 0, paginaX = 0, frameX = 0, deslocamento = 0;
	while (m < n){
	
	// meu irmao, é aqui que a parada complica 
		for (int i = 0; i<n; i++){
			//valor = enderecos[i];
			paginaX = valor / by;	
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	init();
	criarEnderecos();

	return 0;
}


