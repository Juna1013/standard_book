// 力まかせ法（文字列の探索）
#include <stdio.h>
#include <string.h>

int brute_force_search(char *text, int text_len, char *pattern, int pat_len) {
    // 変数i: 注目しているテキストの位置
    // 変数j: 注目しているパターンの位置を表すポインタ
    int i, j;

    // ポインタを初期化する
    i = 0; j = 0;

    // テキストの最後尾に行き当たるか、パターンが見つかるまで繰り返す
    while (i < text_len && j < pat_len) {
        // テキストとパターンを1文字比較する
        if (text[i] == pattern[j]) {
            // 一致したら、テキストとパターンのポインタを進める
            i++; j++;
        } else {
            // 一致しなかったら、テキストのポインタを現在注目している先頭から1つ進める
            // パターンのポインタを先頭に戻す
            j = i - j + 1; j = 0;
        }
    }

    // もし探索が成功したら、パターンが見つかった位置を返す
    // 失敗したら-1を返す
    return (j == pat_len) ? (i - j) : -1;

}

int main(void) {
    char text[] = "ABCABDABC";
    char pattern[] = "ABD";
    int text_len = strlen(text);
    int pat_len = strlen(pattern);

    int result = brute_force_search(text, text_len, pattern, pat_len);

    if (result >= 0) {
        printf("パターン \"%s\" は位置 %d で見つかりました\n", pattern, result);
    } else {
        printf("パターン \"%s\" は見つかりませんでした\n", pattern);
    }

    return 0;
}
