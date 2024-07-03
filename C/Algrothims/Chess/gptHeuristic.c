#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define UNVISITED 0
#define VISITED 1

int checkMoveValidity(int x, int y, int visited[][N]);
void printBoard(int visited[][N]);

int main() {
    int horizontal[N] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[N] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int visited[N][N] = {UNVISITED}; // Tüm kareler başlangıçta ziyaret edilmemiş olarak işaretlenir
    int currentRow = 0; // Atın başlangıç satırı
    int currentColumn = 0; // Atın başlangıç sütunu
    int moveNumber, nextRow, nextColumn;
    int moveCounter = 1; // Hareket sayacı (başlangıç karesi zaten ziyaret edilmiş olarak kabul edilir)

    srand(time(NULL)); // Rastgelelik için seed ayarlanır

    visited[currentRow][currentColumn] = VISITED; // Başlangıç noktası ziyaret edildi olarak işaretlenir

    // Atın turu başlar
    while(moveCounter < N*N) {
        int possibleMoves[N] = {0}; // Her yöndeki mümkün hareketlerin geçerliliğini tutar
        int numPossibleMoves = 0; // Mümkün hareketlerin sayısı

        // Mümkün hareketleri bul
        for(moveNumber = 0; moveNumber < N; moveNumber++) {
            nextRow = currentRow + vertical[moveNumber];
            nextColumn = currentColumn + horizontal[moveNumber];
            if(checkMoveValidity(nextRow, nextColumn, visited)) {
                possibleMoves[numPossibleMoves++] = moveNumber; // Geçerli hareket kaydedilir
            }
        }

        if(numPossibleMoves == 0) {
            // Daha fazla hareket mümkün değil, tur sona erer
            printf("Tur bitti, toplam %d hareket yapıldı.\n", moveCounter);
            break;
        } else {
            // Rastgele bir mümkün hareket seçilir
            int moveChosen = possibleMoves[rand() % numPossibleMoves];
            currentRow += vertical[moveChosen];
            currentColumn += horizontal[moveChosen];
            visited[currentRow][currentColumn] = VISITED;
            moveCounter++;
        }
    }

    printBoard(visited);
    return 0;
}

int checkMoveValidity(int x, int y, int visited[][N]) {
    return x >= 0 && x < N && y >= 0 && y < N && visited[x][y] == UNVISITED;
}

void printBoard(int visited[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%2d ", visited[i][j]);
        }
        printf("\n");
    }
}
