#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int Possibility_Checker(const int horizontal[], const int vertical[], size_t X, int RowLocation, int ColumnLocation);
size_t Secme(int location[][8], const int table[][8], int PossibleArr[], int RowLocation, int ColumnLocation, const int horizontal[], const int vertical[]);

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


    
    int movesCalc[1000];



    unsigned int counter = 0;

    srand(time(NULL));


    while(counter < 10){
        unsigned int a = 0;
        while(a<64){
            for (size_t x = 0; x < 8; x++) PossibleArr[x] = Possibility_Checker(horizontal, vertical, x, RowLocation, ColumnLocation);
            
            size_t PossMove= Secme(location, table, PossibleArr, RowLocation, ColumnLocation, horizontal, vertical);
            if (PossibleMoves >= 0 && PossibleMoves < 8 && PossibleArr[PossibleMoves] == POSSIBLE) {
                location[RowLocation][ColumnLocation] = '*';  // Mevcut konumu işaretle
                RowLocation += vertical[PossMove];
                ColumnLocation += horizontal[PossMove];
                location[RowLocation][ColumnLocation] = 'K';  // Yeni konumu işaretle
                }
            }           
            
            a++;
        }
        counter++;
    
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


size_t Secme(int location[][8], const int table[][8], int PossibleArr[], int RowLocation, int ColumnLocation, const int horizontal[], const int vertical[])
{


    
}
