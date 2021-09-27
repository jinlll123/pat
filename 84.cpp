#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    set<char> st;
    for(int i=0; i<b.length(); ++i) {
        if('a'<=b[i] && b[i]<='z') st.insert(b[i]-'a'+'A');
        else st.insert(b[i]);
    }
    string res = "";
    for(int i=0; i<a.length(); ++i) {
        if('a'<=a[i] && a[i]<='z') a[i] = a[i]-'a'+'A';
        if(st.find(a[i])==st.end()) {
            res += a[i];
            st.insert(a[i]);
        }
    }
    cout << res << endl;
}