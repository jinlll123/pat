#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
    string str;
    cin >> str;
    int res = 0;
    for(int i=0; i<str.length(); ++i) {
        res += (str[i] - '0');
    }
    if(res == 0) cout << "zero\n";
    else {
        vector<int> resv;
        while(res) {
            resv.push_back(res % 10);
            res /= 10;
        }
        reverse(resv.begin(), resv.end());
        cout << nums[resv[0]];
        for(int i=1; i<resv.size(); ++i) {
            cout << " " << nums[resv[i]];
        }
        cout << endl;
    }
}