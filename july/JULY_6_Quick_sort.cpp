class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low > high)
        {
            return;
        }
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int pivot = high;
        while (low < high)
        {
            while (arr[low] <= arr[pivot])
            {
                low++;
            }
            while (arr[high] > arr[pivot])
            {
                high--;
            }
            if (low < high)
            {
                swap(arr[low], arr[high]);
            }
        }
        swap(arr[pivot], arr[high]);
        return high;
    }
};