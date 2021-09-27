#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
map<string, set<int>> title, author, key, pub, year;
void myquery(map<string, set<int>>& mp, string par) {
    if (mp.find(par) != mp.end()) {
        for (int i : mp[par]) {
            printf("%07d\n", i);
        }
    }
    else {
        cout << "Not Found\n";
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    int tid;
    string ttitle, tauthor, tkey, tpub, tyear;
    for (int i = 0; i < n; ++i) {
        scanf("%d\n", &tid);
        getline(cin, ttitle);
        title[ttitle].insert(tid);
        getline(cin, tauthor);
        author[tauthor].insert(tid);
        while (cin >> tkey) {
            key[tkey].insert(tid);
            char c = getchar();
            if (c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(tid);
        getline(cin, tyear);
        year[tyear].insert(tid);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d: ", &num);
        string qs;
        getline(cin, qs);
        cout << num << ": " << qs << endl;
        if (num == 1) myquery(title, qs);
        else if (num == 2) myquery(author, qs);
        else if (num == 3) myquery(key, qs);
        else if (num == 4) myquery(pub, qs);
        else if (num == 5) myquery(year, qs);
    }
}