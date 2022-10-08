#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char * s){
    int symbol = 0, zero=0;
    int l = 0, r = 0;
    while (s[l] != '\0' && s[l] == ' ') l++;
    while (s[l] == '0') {
        l++;
        zero = 1;
    }
    if (zero && !isdigit(s[l])) return 0;
    if (s[l] == '+' ) {
        symbol = 1;
        l++;
    }
    else if (s[l] == '-') {
        symbol = -1;
        l++;
    }
    else if (isdigit(s[l])) {
        symbol = 1;
    }
    while (s[l] == '0') l++;
    if (s[l] == '\0') return 0;
    s = s + l;
    while (isdigit(s[r]) && r  < 10) r++;
    s[r] = '\0';
    long long ans = atoll(s);
    ans = ans * symbol;
    if (ans > INT_MAX) ans = INT_MAX;
    if (ans < INT_MIN) ans = INT_MIN;
    return ans;
}
int main() {
    const char *str = "  -000413243243432393 with words";
    char s[1000];
    int i  ;
    for (; str[i]!='\0'; i++) s[i] = str[i];
    s[i] = '\0';
    int ans = myAtoi(s);
    printf("%d\n", ans);
}