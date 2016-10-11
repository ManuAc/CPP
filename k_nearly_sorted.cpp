#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
  int size;
  int *arr;

public:
  MinHeap(int size, int arr[]);
  int extractMin();
  int replaceMin(int n);
  void heapify(int index);
};

MinHeap::MinHeap(int size, int arr[]) {
  this->size = size;
  this->arr = arr;

  // Building the heap of size k+1
  int i = size/2 - 1;
  while(i >= 0)
    heapify(i--);
}

int MinHeap::replaceMin(int n) {
  int root = arr[0];
  arr[0] = n;
  
  if(n > root)
    heapify(0);

  return root;
}

int MinHeap::extractMin() {
  int root = arr[0];
  if(size > 1) {
    arr[0] = arr[size - 1];
    size--;
    heapify(0);
  }
  return root;
}

void MinHeap::heapify(int index) {
  int smallest = index;
  int l = (2*index) + 1;
  int r = (2*index) + 2;

  if(l < size && arr[l] < arr[smallest])
    smallest = l;

  if(r < size && arr[r] < arr[smallest])
    smallest = r;

  if(smallest != index) {
    swap(arr[index], arr[smallest]);

    // Since the tree is modified, call heapify on the modified root node
    heapify(smallest);
  }
}

void sortk(int arr[], int n, int k) {
  int *temp = new int[k+1];

  for(int i=0; i<=k; i++)
    temp[i] = arr[i];

  MinHeap h(k+1, temp);

  for(int i=k+1, ti = 0; ti < n; ti++, i++){
    if(i < n)
      arr[ti] = h.replaceMin(arr[i]);
    else
      arr[ti] = h.extractMin();
  }
}

int main() {
    // Sorted arr = [2, 3, 6, 8, 12, 56]
  int v[] = {2, 6, 3, 12, 56, 8};
  int n = sizeof(v)/sizeof(v[0]);
  int k = 2;

  sortk(v, n, k);
  
  // Sorted array
  for(int i : v)
    cout << i << " ";

  return 0;
}