// ヒープソート（昇順）
#include <stdio.h>

// ヒープソートの対象となる配列の大きさ
#define MAX_HEAP 1000

// ヒープソートの対象となる配列
// 実際に使用するのはa[1] ~ a[MAX_HEAP]のみで、a[0]は使用しないことに注意
int a[MAX_HEAP+1];

// 配列aに登録されている要素の個数
// 配列のうちa[1] ~ a[n]に要素が入っている
int n = 0;

// ヒープの先頭の要素を必要なところまで沈める
// ただし、a[from]をヒープの先頭、a[to]をヒープの最後の要素とする
void downheap(int from, int to) {
    int i, j;
    int val;

    // 沈められる要素の値をvalにセットしておく
    val = a[from];

    // 根から始めて、節iが子を持っている限り繰り返す
    i = from;
    while (i <= to/2) {
        // 節iの子のうち小さい方を節jとする
        j = i * 2;
        if (j+1 <= to && a[j] > a[j+1]) {
            j++;
        }

        // もし、親が子より大きくないという関係が成り立てば、これ以上進める必要はない
        if (val <= a[j]) {
            break;
        }

        // 節iに節jの値を入れて、節jに注目する
        a[i] = a[j];
        i = j;
    }

    // 先頭にあった要素を節iに入れる
    a[i] = val;
}

// 配列aをヒープソートする
void  heapsort() {
    int i;
    int tmp;

    // バラバラな配列をヒープ形式に整える
    for (i = n/2; i >= 1; i--) {
        downheap(i, n);
    }

    // ヒープから最大値を順に取り出して並べる
    for (i = n; i >= 2; i--) {
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        downheap(1, i-1);
    }
}

int main(void) {
    int i;

    // 入力
    while (scanf("%d", &a[n+1]) == 1) {
        n++;
    }

    heapsort();

    // 出力
    for (i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}