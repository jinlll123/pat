#include<bits/stdc++.h>
using namespace std;
bool isLegal(string s) {
    int i = 0, len = s.length(), p = -1;
    if(s[i] == '-') ++i;
    for(; i<len; ++i) {
        if(s[i]=='.') {
            if(p==-1) {
                p=i;
            }else {
//                 cout << "double point\n";
                return false;
            }
        }
        else if('0'<=s[i] && s[i]<='9') continue;
        else {
//             cout << "inlegal char\n";
            return false;
        }
    }
    if(p!=-1 && len-p-1>2) {
//         cout << "decimal length = " << len-p-1 << endl;
        return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    string s;
    vector<double> vec;
    double tmp, sum=0;
    for(int i=0; i<n; ++i) {
        cin >> s;
//         cout << ">>>>  " << s << endl;
        if(isLegal(s)) {
            tmp = stod(s);
            if(abs(tmp) <= 1000.0) {
                sum += tmp;
                vec.push_back(tmp);
            }
            else {
                printf("ERROR: %s is not a legal number\n", s.c_str());
            }
            
        }
        else {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }
    if(vec.size()==0) {
        printf("The average of 0 numbers is Undefined\n");
    }
    else if(vec.size()==1) {
        printf("The average of 1 number is %.2f\n", sum);
    }
    else {
        printf("The average of %d numbers is %.2f\n", vec.size(), sum/vec.size());
    }
}