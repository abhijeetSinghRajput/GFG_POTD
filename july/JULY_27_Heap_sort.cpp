// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        // find minimum
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (i == largest)
            return;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        // last child will be at n-1
        // parent(n-1) = ((n-1) - 1)/2
        for (int i = ((n - 1) - 1) / 2; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // code here
        buildHeap(arr, n);
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};