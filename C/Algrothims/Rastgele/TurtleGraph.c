#include <stdio.h>
#include <stdlib.h>

enum PenDuration {UP = 1, DOWN};
enum Direction {RIGHT= 3, LEFT};
enum ArrayDirection {kuzey, dogu, guney, batı};

void PrintArray(int location[50][50]);

int Direction(int CurrentDirection, int Director);
int main(void)
{
    int location[50][50] = {0};
    enum PenDuration gamePenDuration;
    enum Direction gameDirection;
    enum ArrayDirection gameArrayDirection;
    
    gameArrayDirection = 0;
    gamePenDuration = 1;
    gameDirection = 3;
    
    int command;
    int step = 0; 
    
    size_t RowLocation=25, ColumnLocation = 25;
   
   
    while(1){
        scanf("%d",&command);
        if (command >= 1 && command <= 2){
            int pen = command;
            gamePenDuration =pen;
        }
        
        else if(command >= 3 && command <= 4){
            int RL = command;
            gameDirection = RL;
            gameArrayDirection = Direction(gameArrayDirection, gameDirection);
        }
        
        
        else if(command == 5){
            printf("%s","How many step/s you want to move: ");
            scanf("%d",&step);
            if(gamePenDuration == 2){
                switch(gameArrayDirection){
                    case kuzey:
                        for(size_t x = 0; x<step; x++)
                            location[RowLocation][ColumnLocation-x] = 1;
                        
                        ColumnLocation -= step;
                    break;
                    
                    case dogu:
                        for(size_t x = 0; x<step; x++)
                            location[RowLocation+x][ColumnLocation] = 1;           
                        
                        RowLocation += step;             
                    break;

                    case guney:
                        for(size_t x = 0; x<step; x++)
                            location[RowLocation][ColumnLocation+x] = 1;
                        
                        ColumnLocation += step;
                    break;

                    case batı:
                        for(size_t x = 0; x<step; x++)
                            location[RowLocation-x][ColumnLocation] = 1;
                        
                        RowLocation -= step;
                    break;
                }
            }

            else if(gamePenDuration == 1){
                switch(gameArrayDirection){
                    case kuzey:ColumnLocation -= step;   
                    break;
                    case dogu:RowLocation += step; 
                    break;
                    case guney:ColumnLocation += step;;
                    break;
                    case batı:RowLocation -= step;;
                    break;
                }
            }
        }
        else if(command == 6){
            PrintArray(location);
        }
        else if(command == 9){
            PrintArray(location);
            puts("PROGRAM END");  
        }
        else{
            printf("Please enter executable command");
        }
    
    }   
    return 0;
}

void PrintArray(int location[50][50])
{
    for(size_t i = 0; i<50; i++){
        for(size_t x =0; x<50; x++){
            if(location[i][x] == 0)
                printf(" 0 ");
            else
                printf(" X ");
        }
        puts("");
    }
}
int Direction(int CurrentDirection, int Director)
{
    //sağa dönme
    if (Director == 3){
        return (CurrentDirection+1)%4;
    }
    //sola dönme
    if(Director == 4){
        return (CurrentDirection-1+4)%4;
    }
}