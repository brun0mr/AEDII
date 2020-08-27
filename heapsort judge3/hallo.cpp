
// C++ program for implementation of Heap Sort 
#include <iostream> 
  
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  

void buildheap (int arr[], int n){
    int i;
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
}
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    int i;
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    int i;
    for (i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int tam,i;
    cin >> tam;
    int arr[tam],arr2[tam];
    for ( i = 0; i < tam; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < tam; i++)
    {
        arr2[i] = arr[i];
    }
    
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    buildheap(arr2,n);
    heapSort(arr, n); 
    printArray(arr2,n);
    printArray(arr, n); 
} 
