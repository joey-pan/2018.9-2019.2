#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    long lena, lenb, lenc;
    long i, j, x, a[1000], b[1000], c[1000];
    char s1[1000], s2[1000];
    cin >> s1 >> s2;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    lena = strlen(s1); lenb = strlen(s2);
    for(i = 0;i <= lena - 1; i++) a[lena-i] = s1[i] - '0';
    for(i = 0;i <= lenb - 1; i++) b[lenb-i] = s2[i] - '0';
    for(i = 1; i <= lena; i++){
        x=0;
        for(j = 1; j <= lenb; j++){
            c[i+j-1] = a[i] * b[j] + x + c[i+j-1];
            x = c[i+j-1] / 10;
            c[i+j-1] = c[i+j-1] % 10;
        }
        c[lenb+i] = x;
    }
    lenc = lena + lenb;
    while(c[lenc] == 0 && lenc > 1) lenc--;
    for(i = lenc; i >= 1; i--) cout << c[i];
    return 0;
}
