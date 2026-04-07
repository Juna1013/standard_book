// 分布数え上げソート
#include <stdio.h>

typedef struct {
    int key;
    int other;
} DATA;

#define M 100
int count[M+1];

// 結果は配列bに得られる
void dist_count_sort(DATA a[], DATA b[], int n) {
    int i;

    for (i = 0; i <= M; i++) {
        count[i] = 0;
    }

    // キーを数え上げる
    for (i = 0; i < n; i++) {
        count[a[i].key]++;
    }

    // 数え上げたキーの累積度数分布を求める
    for (i = 0; i < M; i++) {
        count[i+1] += count[i];
    }

    // 度数分布に従ってデータを配列aから配列bにコピーする
    for (i = n-1; i >= 0; i--) {
        b[--count[a[i].key]] = a[i];
    }
}