#include<iostream>
#include<vector>
using namespace std;

void heapify(int arr[], int n, int index) {
  int largest = index;
  int l = (2*index) + 1;
  int r = (2*index) + 2;

  if(l < n && arr[l] > arr[largest])
    largest = l;

  if(r < n && arr[r] > arr[largest])
    largest = r;

  if(largest != index) {
    swap(arr[index], arr[largest]);

    // Since the tree is modified, call heapify on the modified root node
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n) {
  // Build the heap in thee bottom up manner
  // A heap is a complete binary tree so element afte ciel (n/2)-1 are leaf nodes.
  // Left child = 2*i + 1
  // Right child = 2*i + 2
  for(int i=(n/2)-1; i >=0; i--)
    heapify(arr, n, i);

  for(int i=n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int n;
  cin >> n;
  int v[n];

  for(int i=0; i<n; i++)
    cin >> v[i];

  heapsort(v, n);
  
  // Sorted array
  for(int i : v)
    cout << i << " ";

  return 0;
}