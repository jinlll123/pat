#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int main() {
	int add1, add2, n;
	cin >> add1 >> add2 >> n;
	vector<int> vec(100005, -1);
	int from, to;
	char c;
	for (int i = 0; i < n; ++i) {
		cin >> from >> c >> to;
		vec[from] = to;
	}
	int a = add1, b = add2, i=0;
	while (a != b && i < 2*n) {
        ++i;
		a = vec[a];
		if (a == -1) a = add2;
		b = vec[b];
		if (b == -1) b = add1;
	}
	if(a==b) printf("%05d", a);
    else cout << -1 << endl;
}