#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    int p(0),i;
    if(a.size() < b.size()||(a.size() == b.size() && a < b)) {
        swap(a,b);
        p = 1;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    char c[501];
    string s;
    for(int i = 0; i < b.size(); i++){
        if(a[i] < b[i]){
            a[i] += 10;
            a[i+1] -= 1;
        }
        c[i] = a[i] - b[i] + '0';
    }
    for(long i = b.size(); i < a.size(); i++) c[i] = a[i];
    c[a.size()] = '\0';
    for(i = a.size() - 1; i >= 0; i--) if(c[i] != '0') break;
    if(p) cout << "-";
    for(int j = i; j >= 0; j--)
        cout << c[j];
    cout << endl;
    return 0;
}