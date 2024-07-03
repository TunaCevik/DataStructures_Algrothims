#include <stdio.h>

#define POSSIBLE 1
#define IMPOSSIBLE -1

void PrintTable_Possibilities(int location[8][8], int horizontal[], int vertical[], int PossibleArr[], int RowLoc, int ColLoc);
int Possibility_Checker(int horizontal[], int vertical[], size_t X, int RowLocation, int ColumnLocation);

int main() {
    const int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    int location[8][8] = {0};
    int RowLocation = 3, ColumnLocation = 4;
    int PossibleArr[8];
    int PossibleMoves = 0;

    while (PossibleMoves != -1) {
        for (size_t x = 0; x < 8; x++) {
            PossibleArr[x] = Possibility_Checker(horizontal, vertical, x, RowLocation, ColumnLocation);
        }

        PrintTable_Possibilities(location, horizontal, vertical, PossibleArr, RowLocation, ColumnLocation);
        printf("Which move do you want to make (0-7, -1 to exit): ");
        scanf("%d", &PossibleMoves);

        if (PossibleMoves >= 0 && PossibleMoves < 8 && PossibleArr[PossibleMoves] == POSSIBLE) {
            location[RowLocation][ColumnLocation] = '*';  // Mevcut konumu işaretle
            RowLocation += vertical[PossibleMoves];
            ColumnLocation += horizontal[PossibleMoves];
            location[RowLocation][ColumnLocation] = 'K';  // Yeni konumu işaretle
        }
    }

    return 0;
}

int Possibility_Checker(int horizontal[], int vertical[], size_t X, int RowLocation, int ColumnLocation) {
    RowLocation += vertical[X];
    ColumnLocation += horizontal[X];

    if (RowLocation >= 0 && RowLocation < 8 && ColumnLocation >= 0 && ColumnLocation < 8) {
        return POSSIBLE;
    } else {
        return IMPOSSIBLE;
    }
}

void PrintTable_Possibilities(int location[8][8], int horizontal[], int vertical[], int PossibleArr[], int RowLoc, int ColLoc) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (location[i][j] == 'K') {
                printf(" K ");
            } else if (location[i][j] == '*') {
                printf(" * ");
            } else {
                int isPossible = -1;
                for (int k = 0; k < 8; k++) {
                    if (i == RowLoc + vertical[k] && j == ColLoc + horizontal[k] && PossibleArr[k] == POSSIBLE) {
                        isPossible = k;
                        break;
                    }
                }
                if (isPossible != -1) {
                    printf(" %d ", isPossible);
                } else {
                    printf(" . ");
                }
            }
        }
        printf("\n");
    }
}
