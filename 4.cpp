#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
#define ll long long
const ll INF = 1e18;

struct node {
	int id;
	vector<node*> chd;
	node(int _id = 0) : id(_id) {
		chd.resize(0);
	}
};

int main() {
	int n, m;
	// while (true) {
	cin >> n >> m;
    if(n==1) cout << "1\n";
	else if (n != 0) {
        map<int, node*> mp;
        for (int i = 0; i < m; ++i) {
            int id, k;
            cin >> id >> k;
            node* cur;
            if (mp.find(id) != mp.end()) cur = mp[id];
            else {
                cur = new node(id);
                mp[id] = cur;
            }
            int cid;
            for (int j = 0; j < k; ++j) {
                cin >> cid;
                if (mp.find(cid) != mp.end()) cur->chd.push_back(mp[cid]);
                else {
                    node* child_tmp = new node(cid);
                    cur->chd.push_back(child_tmp);
                    mp[cid] = child_tmp;
                }
            }
        }
        vector<int> res;
        queue<node*> q;
        q.push(mp[1]);
        while (true) {
            int cnt = 0;
            queue<node*> qt;
            while (!q.empty()) {
                node* nd = q.front();
                q.pop();
                if (nd->chd.size() == 0) cnt++;
                else {
                    for (auto cnd : nd->chd) {
                        qt.push(cnd);
                    }
                }
            }
            res.push_back(cnt);
            if (qt.size() == 0) break;
            q = qt;
            // cout << "qsize  " << q.size() << " " << qt.size() << endl;
        }
        cout << res[0];
        for(int i=1; i<res.size(); ++i) {
            cout << " " << res[i];
        }
        cout << endl;
    }
	
	// }
}