// 基数ソート
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// キーの分布を数え上げるための配列
#define M 15
#define MASK 0x0f
int count[M+1];

// 作業用に配列bを使用する
// 16bit長の値を、4bitずつ4回に渡って分布数え上げソートを適用する
void radix_sort(unsigned short a[], unsigned short b[], int n) {
    int i, bit;

    // 下位から上位に向かって、4bitずつ4回ループを実行する
    for (bit = 0; bit < 16; bit += 4) {
        // カウンタをすべて0にする
        for (i = 0; i <= M; i++) {
            count[i] = 0;
        }

        // キーを数え上げる
        for (i = 0; i < n; i++) {
            count[a[i]>>bit & MASK]++;
        }

        // 数え上げたキーの累積分布度数を求める
        for (i = 0; i < M; i++) {
            count[i+1] += count[i];
        }

        // 度数分布に従ってデータを配列aから配列bにコピーする
        for (i = n-1; i >= 0; i--) {
            b[--count[a[i]>>bit & MASK]] = a[i];
        } 

        // データを作業用配列bから配列aへコピーする
        for (i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
}

int main(void) {
    int i;
    int n = 10;
    unsigned short a[10], b[10];

    srand((unsigned int)time(NULL));

    printf("整列前:\n");
    for (i = 0; i < n; i++) {
        a[i] = (unsigned short)(rand() % 65536);
        printf("  a[%d] = %u\n", i, a[i]);
    }

    radix_sort(a, b, n);

    printf("整列後:\n");
    for (i = 0; i < n; i++) {
        printf("  a[%d] = %u\n", i, a[i]);
    }

    return 0;
}