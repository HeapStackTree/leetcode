#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * convert(char * s, int numRows){
    int n = strlen(s), r = numRows;
    if (r == 1 || r >= n) return s;
    char *ans = (char*)malloc(sizeof(char) * (n+1));
    int st = 0;
    int t = r * 2 - 2;
    for (int i = 0; i < r; ++i) { // 枚举矩阵的行
        for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
            ans[st++] += s[j + i]; // 当前周期的第一个字符
            if (0 < i && i < r - 1 && j + t - i < n) {
                ans[st++] += s[j + t - i]; // 当前周期的第二个字符
            }
        }
    }
    ans[st] = '\0';
    return ans;
}

int main() {
    const char *ori = "PAYPALISHIRING";
    int sl = strlen(ori);
    char *s = (char*)malloc(sizeof(char) * (sl + 1));
    strcpy(s, ori);
    int numRows = 3;
    char *ans = convert(s, numRows);
    printf("%s", ans);
    return 0;
}