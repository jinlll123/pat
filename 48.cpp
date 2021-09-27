#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n, m; 
    cin >> n >> m;
    vector<int> vec(n);
    for(int i=0; i<n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int l=0, r=n-1;
    while(l<r) {
        if(vec[l]+vec[r]==m) {
            cout << vec[l] << " " << vec[r] << endl;
            break;
        }
        else if(vec[l]+vec[r] > m) --r;
        else ++l;
    }
    if(l>=r) cout << "No Solution\n";
}