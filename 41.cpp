#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    map<int, int> mp;
    for(int i=0; i<n; ++i) {
        cin >> vec[i];
        mp[vec[i]]++;
    }
    int i=0;
    for(; i<n; ++i) {
        if(mp[vec[i]] == 1) {
            cout << vec[i] << endl;
            break;
        }
    }
    if(i>=n) cout << "None\n";
}