#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int Possibility_Checker(const int horizontal[], const int vertical[], size_t X, int RowLocation, int ColumnLocation);
size_t Secme(int location[][8], const int table[][8], int PossibleArr[], int RowLocation, int ColumnLocation, const int horizontal[], const int vertical[]);
void PrintTable(int location[8][8]);
#define UNVISITED 0
#define POSSIBLE 1
#define IMPOSSIBLE -1

int main()
{
    const int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    const int table[8][8] = {
        {2,3,4,4,4,4,3,2},
        {3,4,6,6,6,6,4,3},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},    
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},       
        {3,4,6,6,6,6,4,3},      
        {2,3,4,4,4,4,3,2},                
        };

    int location[8][8] = {0};
    int RowLocation=0, ColumnLocation=0;
    int PossibleArr[8];
    int PossibleMoves = 0;


    




    unsigned int counter = 0;

    srand(time(NULL));


    while(counter < 10){
        unsigned int a = 0;
        while(a<64){
            for (size_t x = 0; x < 8; x++) PossibleArr[x] = Possibility_Checker(horizontal, vertical, x, RowLocation, ColumnLocation);
            
            size_t PossMove= Secme(location, table, PossibleArr, RowLocation, ColumnLocation, horizontal, vertical);
            if(PossMove == 8){
                
                PrintTable(location);
                printf("\nIt takes: %u moves. \tTable Number: %d\n",a, counter);
                break;
            }
            else if (PossibleMoves >= 0 && PossibleMoves < 8 && PossibleArr[PossibleMoves] == POSSIBLE) {
                location[RowLocation][ColumnLocation] = '*';  // Mevcut konumu işaretle
                RowLocation += vertical[PossMove];
                ColumnLocation += horizontal[PossMove];
                location[RowLocation][ColumnLocation] = 'K';  // Yeni konumu işaretle
                }
            
             a++;
        }           
            
        for(size_t i = 0; i<8; i++){
            for(size_t k = 0; k<8; k++){
                location[i][k] =0;
            }
        }
        
        RowLocation = ColumnLocation =0;
        counter++;
    }
    

    return 0;
}
 

int Possibility_Checker(const int horizontal[], const int vertical[], size_t X, int RowLocation, int ColumnLocation) 
{
    RowLocation += vertical[X];
    ColumnLocation += horizontal[X];

    if (RowLocation >= 0 && RowLocation < 8 && ColumnLocation >= 0 && ColumnLocation < 8) {
        return POSSIBLE;
    } else {
        return IMPOSSIBLE;
    }
}


size_t Secme(int location[][8], const int table[][8], int PossibleArr[], int RowLocation, int ColumnLocation, const int horizontal[], const int vertical[]) {
    int minTableValue = 10;
    size_t chosenMoves[8]; // En düşük table değerine sahip hareketlerin indekslerini saklar
    int chosenMoveCount = 0; // En düşük table değerine sahip hareket sayısı
    for (size_t PossMove = 0; PossMove < 8; PossMove++) {
        int yeniRow = RowLocation + vertical[PossMove];
        int yeniColumn = ColumnLocation + horizontal[PossMove];
        // Geçerli hareketin tahta sınırları içinde olduğunu ve ziyaret edilmediğini kontrol et
        if (PossibleArr[PossMove] == POSSIBLE && location[yeniRow][yeniColumn] == UNVISITED) {
            int currentValue = table[yeniRow][yeniColumn];
            if (currentValue < minTableValue) {
                minTableValue = currentValue;
                chosenMoves[0] = PossMove;
                chosenMoveCount = 1;
            } else if (currentValue == minTableValue) {
                chosenMoves[chosenMoveCount++] = PossMove;
            }
        }
    }

    if (chosenMoveCount > 0) {
        // En düşük table değerine sahip hareketler arasından rastgele birini seç
        return chosenMoves[rand() % chosenMoveCount];
    } else {
        // Eğer hiçbir hareket mümkün değilse, geçerli bir hareketin olmadığını belirten bir değer döndür
        return 8; // 8, geçerli bir hareket olmadığını gösterir
    }
}
void PrintTable(int location[8][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
                if(location[i][j] == '*') printf(" * ");
                else printf(" . ");
                
            }

            printf("\n");           
        }

}
