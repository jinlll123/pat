#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
stack<int> stk;
vector<int> vec;
void fun(int num, int fg) {
    int l = 0, r = vec.size() - 1, mid, sign;
    while (l <= r) {
        mid = (l + r) / 2;
        if (vec[mid] >= num) {
            sign = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (fg == 2) {
        //         cout << vec[mid] << endl;
        vec.erase(vec.begin() + sign);
    }
    if (fg == 1) {
        if (vec.size()==0 || num > vec[vec.size() - 1]) vec.push_back(num);
//         if(vec.size()==0)
//             vec.push_back(num);
//         else if(vec[vec.size()-1]<num)
//             vec.insert(vec.end(),num);
        else vec.insert(vec.begin() + sign, num);
    }
}
int main() {
    int n, num;
    string s;
    s.resize(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", &s[0]);
        if (s[1] == 'o') {
            if (stk.empty()) printf("Invalid\n");
            else {
                num = stk.top();
                printf("%d\n", num);
                stk.pop();
                fun(num, 2);
            }
        }
        else if (s[1] == 'u') {
            scanf("%d", &num);
            fun(num, 1);
            stk.push(num);
        }
        else {
            if (stk.empty()) printf("Invalid\n");
            else {
//                 num = stk.size();
//                 if (num % 2 == 1) num = (num + 1) / 2;
//                 else num /= 2;
//                 printf("%d\n", vec[num - 1]);
                int pos;
                if(stk.size()%2==0) pos=stk.size()/2;
                else pos=(stk.size()+1)/2;
                printf("%d\n",vec[pos-1]);
            }
        }
    }
}