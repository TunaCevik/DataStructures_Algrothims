#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define A(I, J) (*(a + (I)*n + (J)))
#define WORK(I, J) (*(work + (I)*(n+1) + (J)))

int gauss_jordan(
    double *a, // Katsayılar matrisi
    double b[], // Sağ taraf vektörü
    double *work, // Çalışma matrisi
    double x[], // Çözümler dizisi
    int n, // Denklem sayısı
    double tol // Pivot için minimum kabul edilebilir değer
) {
    double m, max, temp;
    int i, j, k, swap;

    // Çalışma matrisini ayarla
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            WORK(i, j) = A(i, j);
        }
        WORK(i, n) = b[i];
    }

    // Matrisin satırları üzerinde döngü
    for (i = 0; i < n; i++) {
        // Pivot seçimi
        max = 0.0;
        swap = i;
        for (k = i; k < n; k++) {
            temp = fabs(WORK(k, i));
            if (temp > max) {
                max = temp;
                swap = k;
            }
        }

        // Pivot yeterince büyük mü kontrol et
        if (max < tol) return FALSE;

        // Satırları değiştir
        if (swap != i) {
            for (k = 0; k <= n; k++) {
                temp = WORK(i, k);
                WORK(i, k) = WORK(swap, k);
                WORK(swap, k) = temp;
            }
        }

        // Eleme yap
        for (j = 0; j < n; j++) {
            if (j != i) {
                m = WORK(j, i) / WORK(i, i);
                for (k = i; k <= n; k++) {
                    WORK(j, k) -= m * WORK(i, k);
                }
            }
        }
    }

    // Çözümü hesapla
    for (i = 0; i < n; i++) {
        x[i] = WORK(i, n) / WORK(i, i);
    }

    return TRUE;
}

int main() {
    double coeff[3][3] = {{2, 3, 5}, {1, 2, 4}, {4, 7, 3}};
    double rhs[3] = {10, 5, 15};
    double place[3][4]; // Çalışma matrisi
    double answer[3]; // Çözüm vektörü
    int n = 3; // Denklem sayısı
    double tol = 0.00001; // Tolerans değeri

    if (gauss_jordan((double *)coeff, rhs, (double *)place, answer, n, tol)) {
        printf("Solution is: %lf %lf %lf\n", answer[0], answer[1], answer[2]);
    } else {
        printf("No solution found\n");
    }

    return 0;
}
