#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int a[505];
int b[505];
int main(){
    string x, y;
    cin >> x >> y;
    int w1 = x.length();
    for(int i = w1; i >= 1; i--) a[i] = x[w1 - i]-'0';
    int w2 = y.length();
    for(int i = w2; i >= 1; i--) b[i] = y[w2 - i] - '0';
    int s = max(w1,w2);
    for(int i = 1; i <= s; i++){
        a[i] += b[i];
        if(a[i] >= 10){
            a[i] -= 10;
            a[i+1] += 1;
        }
    }
    if(a[s+1] != 0) printf("%d",a[s+1]);
    for(int i = s; i >= 1; i--) printf("%d",a[i]);
    return 0;
}