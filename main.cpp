#include <iostream>
#include <cstdlib> 

using namespace std;



int mapa[12][12];


int playerX = 1; 
int playerY = 1;

int itemX;
int itemY;

int main() {
 int inventario [5] = {0, 0, 0, 0, 0};
    int metagravetos = 0;
   int metapedras = 0; 
   int metafrutas = 0; 
   int metaanimais = 0; 
   int metaarvores = 0;

 bool jogorodando = true;
 const char* nomesItens[5] = {"Gravetos", "Pedras", "Frutas", "Animais", "Arvores"};
 
  int  objetivoescolhido = 0;

    char tecla;
    
 cout << "Seja muito bem vindo(a), aventureiro(a)! Escolha um objetivo para sua jornada: " << endl;
 cout << "   1 . Luz e calor: voce deve coletar 4 gravetos e 2 pedras." << endl;
 cout << "   2 . Comida: voce deve coletar 1 fruta e 3 animais." << endl;
 cout << "   3 . Abrigo: voce deve coletar 5 gravetos e 4 pedras." << endl;
 cout << "   4 . Construcao: voce deve coletar 8 pedras e 4 arvores;" << endl;
 cin >> objetivoescolhido;

 if (objetivoescolhido == 1) {
  cout <<"Voce escolheu o objetivo: Luz e calor." << endl;
   metagravetos = 4;
    metapedras = 2;

 } else if (objetivoescolhido == 2) {
   metafrutas = 1;
    metaanimais = 3;
   cout <<"Voce escolheu o objetivo: Comida." << endl;

 } else if (objetivoescolhido == 3) {
   metagravetos = 5; 
   metapedras = 4;
   cout <<"Voce escolheu o objetivo: Abrigo." << endl;

 } else if (objetivoescolhido == 4) {
   metapedras = 8; 
   metaarvores = 4;
   cout <<"Voce escolheu o objetivo: Construcao." << endl;

 } else {
   cout << "Opção inválida. Por favor, escolha um objetivo válido." << endl;
 }
 
    srand(time(0));

    itemX = rand() % 12;
    itemY = rand() % 12;
    
    
    while (true) {
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (i == playerX && j == playerY) {
                    mapa[i][j] = 'P';

                } else {
                    mapa[i][j] =  '.'; 
                }
            }
            cout << endl;
        }
        
        
        cout << "\nUse W, A, S, D + ENTER para andar. Pressione 'Q' + ENTER para sair.\n";
        cout << "Comando: ";
        
        
        cin >> tecla; 
        
        
        if ((tecla == 'w' || tecla == 'W') && playerX > 0) {
            playerX--; 
        }
        if ((tecla == 's' || tecla == 'S') && playerX < LINHAS - 1) {
            playerX++; 
        }
        if ((tecla == 'a' || tecla == 'A') && playerY > 0) {
            playerY--; 
        }
        if ((tecla == 'd' || tecla == 'D') && playerY < COLUNAS - 1) {
            playerY++; 
        }
        if (tecla == 'q' || tecla == 'Q') {
            break; 

            if (playerX == itemX && playerY == itemY) {
            // pega o item la                      
            }
            
        }
    }
    
    cout << "Jogo encerrado!" << endl;
    return 0;
}
