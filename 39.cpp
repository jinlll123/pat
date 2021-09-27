#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    map<string, vector<int>> mp;
    int idx, num;
    string name;
    for(int i=0; i<k; ++i) {
        cin >> idx >> num;
        for(int j=0; j<num; ++j) {
            cin >> name;
            mp[name].push_back(idx);
        }
    }
    for(int i=0; i<n; ++i) {
        cin >> name;
        cout << name;
        cout << " " << mp[name].size();
        sort(mp[name].begin(), mp[name].end());
        for(auto i : mp[name]) {
            cout << " " << i;
        }
        cout << endl;
    }
    
}