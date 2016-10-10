#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<int> a(n);
		
		for(int a_i = 0; a_i < n; a_i++) {
			cin >> a[a_i];
		}

		vector<int>::iterator it;
		int pcount = 0;
		for(it = a.begin(); it != a.end(); it++) {
			if (*it <= 0)
				pcount += 1;
		}
		string res = (pcount < k) ? "YES" : "NO";
		cout << res << endl;
	}
	return 0;
}
