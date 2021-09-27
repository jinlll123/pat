#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {return a > b;}
int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    
    int sum = 0, cnt = 0;
    for(int i=0; i<n/2; ++i) {
        sum += vec[i];
        sum -= vec[n-1-i];
    }
    if(n%2==1) {
        cnt = 1;
        sum += vec[n/2];
    }
    cout << cnt << " " << sum << endl;
}