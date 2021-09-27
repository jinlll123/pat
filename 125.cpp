#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> pq;
    double t;
    for(int i=0; i<n; ++i) {
        cin >> t;
//         cout << t << " ";
        pq.push(t);
    }
//     cout << endl;
    while(pq.size()>1) {
        t = 0;
        for(int i=0; i<2; ++i) {
            t += pq.top();
            pq.pop();
        }
//         cout << t/2 << endl;
        pq.push(t/2);
    }
    cout << (int)pq.top() << endl;
}