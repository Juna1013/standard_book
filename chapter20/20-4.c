// nクイーン（すべての解を表示する）
#include <stdio.h>

void try_all(int a) {
    int b;

    // 左から右に向かって順番にクイーンが置けるかどうかを調べる
    for (b = 0; b < N; b++) {

        // a行目のb番目に置けるかどうか調べる
        if (col[b] == FREE &&
            up[a+b] == FREE &&
            down[a - b + (N-1)] == FREE) {

                // 置くことができた
                // 場所を記録してリセットする
                pos[a] = b;
                col[b] = NOT_FREE;
                up[a+b] = NOT_FREE;
                down[a - b + (N-1)] = NOT_FREE;

                // N個のクイーンをすべて置くことが出来れば成功である
                if (a + 1 >= N) print_queens();
                else try_all(a+1);

                // クイーンを取り除く
                pos[a] = -1;
                col[b] = FREE;
                up[a+b] = FREE;
                down[a - b + (N-1)] = FREE;
            }
    }
}