#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<long long> vec;
    for(int i=0; i<2; ++i) {
        int n, tmp;
        cin >> n;
        for(int j=0; j<n; ++j) {
            cin >> tmp;
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec[(vec.size()-1)/2] << endl;
}