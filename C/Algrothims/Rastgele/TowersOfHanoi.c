#include <stdio.h>

void hanoi(int n, char kaynak, char yardimci, char hedef) {
    if (n == 1) {
        printf("Disk 1'i %c'den %c'ye tasi\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, hedef, yardimci);
    printf("Disk %d'i %c'den %c'ye tasi\n", n, kaynak, hedef);
    hanoi(n - 1, yardimci, kaynak, hedef);
}

int main() {
    int diskSayisi;
    printf("Hanoi Kuleleri cozumu icin disk sayisini girin: ");
    scanf("%d", &diskSayisi);
    hanoi(diskSayisi, 'A', 'B', 'C');
    return 0;
}
