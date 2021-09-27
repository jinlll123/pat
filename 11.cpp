#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    double res = 1;
    vector<int> vec(3);
    for(int i=0; i<3; ++i) {
        double mx = 0, tmp;
        for(int j=0; j<3; ++j) {
            cin >> tmp;
            if(tmp > mx) {
                mx = tmp;
                vec[i] = j;
            }
        }
//         cout << "mx " << mx << endl;
        res *= mx;
    }
    res = (res*0.65-1)*2;
    string str = "WTL";
    for(int i=0; i<3; ++i) cout << str[vec[i]] << " ";
    cout << fixed << setprecision(2) << res << endl;
}