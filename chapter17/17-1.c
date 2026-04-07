// ビンソート
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 整列の対象となるデータの型
typedef struct {
    // 整列のキー
    // キーが-1のとき、ビンは空である
    int key;

    // その他の情報
    int other;
} DATA;

// キーは0からMまでの範囲の整数
#define M 100

// ビンソートに使用するビン
DATA bin[M+1];

// 大きさnの配列aをビンソートする
void bin_sort(DATA a[], int n) {
    int i, j;

    // ビンを空にする
    for (i = 0; i <= M; i++) {
        bin[i].key = -1;
    }

    // 配列aのデータを順番にビンに振り分ける
    for (i = 0; i < n; i++) {
        bin[a[i].key] = a[i];
    }

    // データをビンから（昇順に）取り出して、配列がaに戻す
    j = 0;
    for (i = 0; i <= M; i++) {
        if (bin[i].key != -1) {
            a[j++] = bin[i];
        }
    }
}

int main(void) {
    int i;
    int n = 10;
    DATA a[10];

    srand((unsigned int)time(NULL));

    // ランダムなデータを生成
    printf("整列前:\n");
    for (i = 0; i < n; i++) {
        a[i].key   = rand() % (M + 1);
        a[i].other = i;
        printf("  a[%d]: key=%d, other=%d\n", i, a[i].key, a[i].other);
    }

    bin_sort(a, n);

    printf("整列後:\n");
    for (i = 0; i < n; i++) {
        printf("  a[%d]: key=%d, other=%d\n", i, a[i].key, a[i].other);
    }

    return 0;
}
