#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    string nums[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string sig[3] = {"Shi", "Bai", "Qian"};
    vector<string> vec;
    if(s[0]=='-') {
        vec.push_back("Fu");
//         cout << "Fu" << endl;
        s = s.substr(1);
//         cout << s << endl;
    }
    if(s.length()==9) {
//         cout << "Yi" << endl;
        vec.push_back(nums[s[0]-'0']);
        vec.push_back("Yi");
        s = s.substr(1);
    }
    if(s.length() > 4) {
        int len = s.length()-4;
        for(int i=0; i<len; ++i) {
            vec.push_back(nums[s[i]-'0']);
            if(len-i-2>=0 && s[i]!='0') vec.push_back(sig[len-i-2]);
        }
        vec.push_back("Wan");
        s = s.substr(len);
    }
//     cout << s << endl;
    int len = s.length();
    for(int i=0; i<len; ++i) {
        vec.push_back(nums[s[i]-'0']);
        if(len-i-2>=0 && s[i]!='0') vec.push_back(sig[len-i-2]);
    }
    for(int i=0; i<vec.size()-1; ++i) {
        if(vec[i]=="Shi" && vec[i+1]=="ling") vec[i+1]="null";
        else if(vec[i]=="ling" && (vec[i+1]=="ling" || vec[i+1]=="Wan")) vec[i]="null";
    }
    vector<string> res;
    for(int i=0; i<vec.size(); ++i) {
        if(vec[i]!="null") res.push_back(vec[i]);
    }
    if((res.size()>1) && res[res.size()-1]=="ling") res.erase(res.end());
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << " \n"[i==res.size()-1];
    }
}