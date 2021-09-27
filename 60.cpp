#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int findP(string a) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == '.') {
            return i;
        }
    }
    return a.length();
}
int findN(string a) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != '0') {
            return i;
        }
    }
    return a.length();
}
int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int p = findP(a), q = findP(b);
    if(p!=a.length()) a.erase(a.begin() + p);
    if(q!=b.length()) b.erase(b.begin() + q);
//     cout << p << " " << q << endl;
    int k = findN(a), t = findN(b);
    int r1=(k==a.length() ? 0:p - k), r2=(t==b.length() ? 0:q - t);
    string at = a.substr(k), bt = b.substr(t);
    for (int i = at.length(); i < n; ++i) at += "0";
    for (int i = bt.length(); i < n; ++i) bt += "0";
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (at[i] != bt[i]) {
            flag = false;
            break;
        }
    }
    if (r1 != r2) flag = false;
    if (flag) {
        printf("YES 0.");
        for (int i = 0; i < n; ++i) cout << at[i];
        printf("*10^%d\n", r1);
    }
    else {
        printf("NO 0.");
        for (int i = 0; i < n; ++i) cout << at[i];
        printf("*10^%d 0.", r1);
        for (int i = 0; i < n; ++i) cout << bt[i];
        printf("*10^%d\n", r2);
    }
}