#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Duvar '#'
#define Yol '.'

enum ArrayDirection {kuzey, dogu, guney, batı};
enum Direction {RIGHT=3,LEFT, FRONT = 5, BACK};

int Direction(int CurrentDirection, int Director);
bool checkerRight(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);
bool checkerLeft(const char MazeMap[][12], size_t RowLoaction, size_t ColumnLocation, int ArrayDirection);
bool checkerFront(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);
bool checkerBack(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);

int main(void)
{
    enum Direction gameDirection; // Sağ-Sol
    enum ArrayDirection gameArrayDirection; // Kuzey- guney- dogu- bati

    gameArrayDirection = dogu;
    gameDirection = RIGHT;

    const char MazeArray[12][12] = {
    //    0    1    2    3    4    5    6    7    8    9    10   11
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, // 0
        
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'}, // 1

        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'}, // 2

        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'}, // 3

        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'}, // 4

        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, // 5

        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, // 6
        
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, // 7
        
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'}, // 8

        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'}, // 9 

        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'}, // 10

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}  // 11
    };


    size_t RowLocation;
    size_t ColumnLocation = 0;
    bool (*Maker[4])(const char [][12], size_t, size_t, int) = {checkerRight, checkerFront, checkerLeft, checkerBack};

    for(size_t index =0; index<12; index++){
        /*Yol kısmından başlama*/
        if(MazeArray[index][0] == Yol){
            RowLocation = index;
            break;
        }
    }


    size_t StepSaverIndex = 1;
//    StepSaverROW[0] = RowLocation;
//    StepSaverColumn[0] = ColumnLocation;

    do{
        //CheckerRight : 0 ve Direction() kuzey mi güney mi dogu mu batı mı ona kara verecek
        // yeni gameArrayDirectionu oluşturma yeni RowLoaction ve ColumnLocation değerleri atama
        if(Maker[0](MazeArray, RowLocation, ColumnLocation, gameArrayDirection) == true){
            gameArrayDirection = Direction(gameArrayDirection, RIGHT);
            switch (gameArrayDirection)
            {
            case kuzey:
                RowLocation -= 1;
                break;
            case dogu:
                ColumnLocation += 1;
                break;
            case guney:
                RowLocation += 1;
                break;
            case batı:
                ColumnLocation -= 1;
            default:
                break;
            }
        }
        else if(Maker[1](MazeArray, RowLocation, ColumnLocation, gameArrayDirection) == true){
            gameArrayDirection = Direction(gameArrayDirection, FRONT);
            switch (gameArrayDirection)
            {
            case kuzey:
                RowLocation -= 1;
                break;
            case dogu:
                ColumnLocation += 1;
                break;
            case guney:
                RowLocation += 1;
                break;
            case batı:
                ColumnLocation -= 1;
                break;
            default:
                break;
            }
        }
        else if(Maker[2](MazeArray, RowLocation, ColumnLocation, gameArrayDirection)){
            gameArrayDirection = Direction(gameArrayDirection, LEFT);
            switch (gameArrayDirection)
            {
            case kuzey:
                RowLocation -= 1;
                break;
            case dogu:
                ColumnLocation += 1;
                break;
            case guney:
                RowLocation += 1;
                break;
            case batı:
                ColumnLocation -= 1;
                break;
            default:
                break;
            }
        }
        else if(Maker[3](MazeArray, RowLocation, ColumnLocation, gameArrayDirection )){
            gameArrayDirection = Direction(gameArrayDirection, BACK);
            switch (gameArrayDirection)
            {
            case kuzey:
                RowLocation -= 1;
                break;
            case dogu:
                ColumnLocation += 1;
                break;
            case guney:
                RowLocation += 1;
                break;
            case batı:
                ColumnLocation -= 1;
                break;
            default:
                break;
            }
           
        }
        else printf("WTF");


        printf("RowLocation[%-3zu] : %2zu, ColumnLocation[%-3zu] : %2zu \n", StepSaverIndex, RowLocation, StepSaverIndex, ColumnLocation);
        StepSaverIndex += 1;
    }while(ColumnLocation < 12 && StepSaverIndex < 144 && RowLocation <12); // 12 maze 'in bittiği column

    printf("\nStepSaverIndex : %zu", StepSaverIndex);


    

    return 0;
}


bool checkerRight(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    int Direction(int CurrentDirection, int Director);
    /*
        Right Olduğu için int Director hep RIGHT olacak CurrentDirection da ArrayDirection olacak
    */
    int direction = Direction(ArrayDirection, RIGHT);
    switch (direction)
    {
    case kuzey:
        return MazeMap[RowLocation-1][ColumnLocation] == Yol;
        break;
    case dogu:
        return MazeMap[RowLocation][ColumnLocation +1] == Yol;
        break;
    case guney:
        return MazeMap[RowLocation+1][ColumnLocation] == Yol;
        break;

    case batı:
        return MazeMap[RowLocation][ColumnLocation-1] == Yol;
        break;

    default:
        break;
    }
}

bool checkerFront(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    int Direction(int CurrentDirection, int Director);
    /*
        Front Olduğu için int Director hep FRONT olacak CurrentDirection da ArrayDirection olacak
    */
    int direction = Direction(ArrayDirection, FRONT);
    switch (direction)
    {
    case kuzey:
        return MazeMap[RowLocation-1][ColumnLocation] == Yol;
        break;
    case dogu:
        return MazeMap[RowLocation][ColumnLocation +1] == Yol;
        break;
    case guney:
        return MazeMap[RowLocation+1][ColumnLocation] == Yol;
        break;

    case batı:
        return MazeMap[RowLocation][ColumnLocation-1] == Yol;
        break;
        
    default:
        break;
    }
}

bool checkerBack(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    int Direction(int CurrentDirection, int Director);
    /*
        Back Olduğu için int Director hep BACK olacak CurrentDirection da ArrayDirection olacak
    */
    int direction = Direction(ArrayDirection, BACK);
    switch (direction)
    {
    case kuzey:
        return MazeMap[RowLocation-1][ColumnLocation] == Yol;
        break;
    case dogu:
        return MazeMap[RowLocation][ColumnLocation +1] == Yol;
        break;
    case guney:
        return MazeMap[RowLocation+1][ColumnLocation] == Yol;
        break;

    case batı:
        return MazeMap[RowLocation][ColumnLocation-1] == Yol;
        break;
        
    default:
        break;
    }
}

bool checkerLeft(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    int Direction(int CurrentDirection, int Director);
    int direction = Direction(ArrayDirection, LEFT);
    switch (direction)
    {
    case kuzey:
        return MazeMap[RowLocation-1][ColumnLocation] == Yol;
        break;
    case dogu:
        return MazeMap[RowLocation][ColumnLocation +1] == Yol;
        break;
    case guney:
        return MazeMap[RowLocation+1][ColumnLocation] == Yol;
        break;

    case batı:
        return MazeMap[RowLocation][ColumnLocation-1] == Yol;
        break;
        
    default:
        break;
    }
}

//void PrintingTheArray();




int Direction(int CurrentDirection, int Director)
{ 
    /*
    Geri döndüğü değer 4 yönden hangisine baktığını gösteriyor int şeklinde
    0: kuzey
    1: dogu
    2: guney
    3: batı
    */
    //sağa dönme
    if (Director == 3){
        return (CurrentDirection+1)%4;
    }
    // öne gitme
    if(Director == 5){
        return CurrentDirection;
    }
    if(Director == 4){
        return (CurrentDirection-1+4)%4;
    }
    //arkaya gitme
    if(Director == 6){
        return (CurrentDirection + 2) % 4;
    }
}