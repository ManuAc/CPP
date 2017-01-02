#include<iostream>
using namespace std;

void printBinary(int x) {
  while(x) {
    int rem = x % 2;
    x = x/2;

    cout << rem;
  }
  cout << endl;
}

int main() {
  int x;

  cin >> x;
  printBinary(x);

  // Toggle the last bit
  x = (x & 1);
  printBinary(x);

  return 0;
}