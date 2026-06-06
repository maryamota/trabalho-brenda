#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;



char mapa[12][12];


int playerX = 1; 
int playerY = 1;



int main() {
 int inventario [5] = {0, 0, 0, 0, 0};
    int metagravetos = 0;
   int metapedras = 0; 
   int metafrutas = 0; 
   int metaanimais = 0; 
   int metaarvores = 0;

 const char* nomesItens[5] = {"Gravetos", "Rocha", "Frutas", "Animais", "Arvores"};
 char iconesItens[5] = {'g', 'r', 'f', 'n', 'a'};
 
  int  objetivoescolhido = 0;

    char tecla;
    
 cout << "Seja muito bem vindo(a), aventureiro(a)! Escolha um objetivo para sua jornada: " << endl;
 cout << "   1 . Luz e calor: voce deve coletar 4 gravetos e 2 rochas." << endl;
 cout << "   2 . Comida: voce deve coletar 1 fruta e 3 animais." << endl;
 cout << "   3 . Abrigo: voce deve coletar 5 gravetos e 4 rochas." << endl;
 cout << "   4 . Construcao: voce deve coletar 8 rochas e 4 arvores;" << endl;
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

   
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            int chance = rand() % 100; 

            if (chance < 15) {          
                mapa[i][j] = 'g'; 
            } else if (chance < 30) {   
                mapa[i][j] = 'r'; 
            } else if (chance < 40) {   
                mapa[i][j] = 'f'; 
            } else if (chance < 50) {   
                mapa[i][j] = 'n'; 
            } else if (chance < 65) {  
                mapa[i][j] = 'a'; 
            } else {                    
                mapa[i][j] = '.'; 
            }
        }
    }

    
    while (true) {
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        cout << "===========================================" << endl;
        cout << "          INVENTARIO DO JOGADOR            " << endl;
        cout << "===========================================" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "->" << nomesItens[i] << ": " << inventario[i] << endl;
        }
        cout << "===========================================" << endl;
        
        
        char itemAtual = mapa[playerX][playerY];

     
        if (itemAtual != '.') {
            if (itemAtual == 'g') inventario[0]++;    
            else if (itemAtual == 'r') inventario[1]++; 
            else if (itemAtual == 'f') inventario[2]++; 
            else if (itemAtual == 'r') inventario[3]++; 
            else if (itemAtual == 'a') inventario[4]++; 

           
            mapa[playerX][playerY] = '.';
        }

        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (i == playerX && j == playerY) {
                    cout << 'P' << ' '; 
                } else {
                    cout << ' ' << mapa[i][j] << ' '; 
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
        if ((tecla == 's' || tecla == 'S') && playerX < 11) {
            playerX++; 
        }
        if ((tecla == 'a' || tecla == 'A') && playerY > 0) {
            playerY--; 
        }
        if ((tecla == 'd' || tecla == 'D') && playerY < 11) {
            playerY++; 
        }

        if (tecla == 'q' || tecla == 'Q') {
            break; 

        }
    }
    
    cout << "Jogo encerrado!" << endl;
    return 0;
}
