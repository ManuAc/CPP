#include <iostream>
using namespace std;


int main() {
	int n, i, count = 0;
	cin >> n;
	int arr[n];

	for(i = 0; i < n; i++)
		cin >> arr[i];

	if(n == 2 || n == 3)
		cout << (count + 1) << endl;
	else {
		i = 0;
		while(i < n-1) {
			if(i+2 < n && arr[i+2] == 0) {
				i += 2;
			} else if( i+1 < n && arr[i+1] == 0) {
				i += 1;
			}
			count += 1;
		}
	}

	cout << count << endl;

	return 0;
}
