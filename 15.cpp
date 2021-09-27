#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isP(long long n) {
    if(n <= 1) return false;
    for(int i=2; i<=int(sqrt(n+1)); ++i) {
        if(n%i==0) return false;
    }
    return true;
//     if(n <= 1) return false;
//     int sqr = int(sqrt(n * 1.0));
//     for(int i = 2; i <= sqr; i++) {
//         if(n % i == 0)
//             return false;
//     }
//     return true;
}

int main() {
    long long n, d;
    while(true) {
        cin >> n;
        if(n < 0) break;
        cin >> d;
        if(n < 2) {
            cout << "No\n";
            continue;
        }
        if(!isP(n)) {
            cout << "No\n";
            continue;
        }
        vector<int> vec;
        while(n) {
            vec.push_back(n%d);
            n/=d;
        }
        long long res = 0;
        for(int i=0; i<vec.size(); ++i) {
            res = res*d + vec[i];
        }
//         cout << "res = " << res << endl;
        if(!isP(res)) cout << "No\n";
        else cout << "Yes\n";
    }
    
    
}