#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b);
void swap(int a,int b);
int main(){
    int a,b;
    cin >> a >> b;
    if (a < b) swap(a,b);
    cout << gcd(a, b) << " " << a*b/gcd(a, b);
    return 0;
}
int gcd(int a,int b){
    if (a%b == 0) {
        return b;
    }else return gcd(b, a%b);
}
void swap(int a,int b){
    int c;
    c = a;
    a = b;
    b = c;
    return;
}