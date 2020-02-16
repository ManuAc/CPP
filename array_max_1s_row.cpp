// Problem statement - https://practice.geeksforgeeks.org/problems/row-with-max-1s/0

#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
    
	while(n--) {

		int m, n;
		cin >> m >> n;

		int arr[m][n];

		for(int i=0; i<m; i++) {
		    
			for(int j=0; j<n; j++) {
				cin >> arr[i][j];
			}
		}

	    int max = 0;
	    int i = 0, j = n-1;

	    while(i < m && j >= 0) {
            
		    if(arr[i][j] == 1) {
			    j -= 1;
			    max = i;
		    } else {
			    i += 1;
		    }
    	}

		cout << max << endl;
	}

	return 0;
}