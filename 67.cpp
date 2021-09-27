#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n, t, cnt=0;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; ++i) {
        cin >> t;
        vec[t] = i;
    }
    for(int i=1; i<n; ++i) {
        if(vec[i] != i) {
            while(vec[0] != 0) {
                swap(vec[0], vec[vec[0]]);
                cnt++;
            }
            if(vec[i] != i) {
                swap(vec[0], vec[i]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}