#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <clocale>
#include <cstdio>
#include <ctime>

#define p 512               // PÁGINAS
#define f 256               // FRAMES
#define by 8192				// 8KB
#define maxEnd 4194304      // 4MB

void init();
void paginacao(int);
void criarEnderecos();
void randomizaPaginas();
void random(int);

using namespace std;

int n, endereco;
int pag[p], frame[f] = {}, pagUsadas[f];

int hitRatio = 0;
int missRatio = 0;

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
	//Valor referente ao vetor frame

	int counter = 0, pos;
	while(counter <= f - 1) {
	    pos = rand() % p;
		if(pag[pos] == -1) {

			do {
				check = true;
				randNum = random(0, f - 1);
				
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

	/*for(int i = 0; i < p; i++) {
		cout << pag[i] << " ";
	}*/
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

	srand(time(NULL));
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
					cout << "Endereço: " << endereco << " ";
					paginacao(endereco);
				}
			}
		}
	}
	/*for (int i=0; i<n; i++){
		printf(" %d\n", enderecos[i]);
	}*/
}

void paginacao(int endereco){
	// meu irmao, é aqui que a parada complica RSRSRS
	//Vc pode fazer aquele cálculo deslocamento para cara endereço? eu n lembro =/
	int primeiroBitPag = 0, paginaX = 0, frameX = 0, deslocamento = 0, primeiroBitFrame = 0;
	int posFinalFrame = 0;

	paginaX = endereco / by;
	primeiroBitPag = paginaX * by;

	deslocamento = endereco - primeiroBitPag; //Acho q é isso

	frameX = pag[paginaX];

	if(frameX == -1 ) {
		cout << "PF" << endl;
		missRatio += 1;
		return;
	}

	primeiroBitFrame = frameX * by;
	posFinalFrame = primeiroBitFrame + deslocamento; 

	cout << "Página: " << paginaX << " ";
	cout << "Deslocamento: " << deslocamento << " ";
	cout << "Frame: " << frameX << " ";
	cout << "Endereço real: " << posFinalFrame << endl;
	hitRatio += 1;
}

void ratio() {
	cout << "Quantidade de acertos: " << hitRatio << endl;
	cout << "Quantidade de erros: " << missRatio << endl;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	init();

	criarEnderecos();

	ratio();

	return 0;
}


