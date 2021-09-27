#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, z, a, b, len, k;
    string t;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> t;
        len = t.length()/2;
        k = pow(10, len);
        z = stoi(t.c_str());
        a = z/k;
        b = z%k;
//         cout << a << " " << b << endl;
        if(a==0 || b==0) {
            cout << "No\n";
        }
        else if(z%a!=0) {
            cout << "No\n";
        }
        else {
            z/=a;
            if(z%b!=0) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
}