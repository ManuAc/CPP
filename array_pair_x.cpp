#include<iostream>
#define MAX 10000

using namespace std;

int main() {
	int i_size, *i_arr, i_sum;
	cin >> i_size;

	i_arr = (int*) malloc(i_size * sizeof(int));

	for(int i=0 ; i< i_size; i++)
		cin >> i_arr[i];

	cin >> i_sum;

	bool binMap[MAX] = {0};

	for(int j=0; j<i_size; j++){
		int pair = i_sum - i_arr[j];

		if(pair >= 0 && i_arr[pair])
			cout << "Pair: " << i_arr[j] << " : " << pair << endl;

		binMap[i_arr[j]] = 1;
	}
	return 0;
}