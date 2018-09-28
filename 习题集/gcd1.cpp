#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//int gcd(int a,int b){
//    if (a%b == 0) {
//        return b;
//    }else return gcd(b, a%b);
//}
int main(){
    int a,b,as,bs;
    cin >> a >> b;
    if (a < b) {
        int c;
        c = a;
        a = b;
        b = c;
    }
    //cout << gcd(a, b) << " " << a*b/gcd(a, b);
    as = a;
    bs = b;
    while (1) {
        if (as % bs == 0) {
            cout << bs << " " << a*b/bs;
            break;
        }else{
            int cs;
            cs = bs;
            bs = as % bs;
            as = cs;
        }
    }
    
    return 0;
}