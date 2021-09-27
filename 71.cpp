#include<iostream>
#include<map>
#include<string>
using namespace std;
bool islownum(char c) {
    if('0'<=c && c<='9') return true;
    if('a'<=c && c<='z') return true;
    return false;
}
int main() {
    map<string, int> mp;
    string str, tmp="";
    getline(cin, str);
    for(int i=0; i<str.length(); ++i) {
        if(islownum(str[i])) tmp+=str[i];
        else if('A'<=str[i] && str[i]<='Z'){
            tmp += (str[i]-'A'+'a');
        }
        else {
//             cout << "i= " << i << "   tmp= " << tmp << endl;
            if(tmp=="") continue;
            else {
                mp[tmp]++;
                tmp = "";
            }
        }
    }
    if(tmp != "") mp[tmp]++;
    int cnt = 0;
    for(auto it : mp) {
        if(it.second == cnt) {
            tmp = tmp < it.first ? tmp : it.first;
//             cnt = it.second;
        }
        else if(it.second > cnt) {
            tmp = it.first;
            cnt = it.second;
        }
    }
    cout << tmp << " " << cnt << endl;
}