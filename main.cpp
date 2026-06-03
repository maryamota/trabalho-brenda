#include <iostream>
#include <cstdlib> 

using namespace std;


const int LINHAS = 10;
const int COLUNAS = 15;


int playerX = 1; 
int playerY = 1;

int main() {
    char tecla;
    
    
    while (true) {
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                if (i == playerX && j == playerY) {
                    cout << 'P' << ' '; 
                } else {
                    cout << '.' << ' '; 
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
        }
    }
    
    cout << "Jogo encerrado!" << endl;
    return 0;
}