#include <iostream>
#include <vector>
using namespace std;


int Partition(vector<int> &arr, int low, int high)
{
    int left=low, pivot=arr[low], temp;

    while(low < high)
    {
        while(low < high && arr[high] > pivot)
            high--;
        while(low < high && arr[low] < pivot)
            low++;
        
        if(low < high)
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = arr[low];
        }
    }

    temp = arr[left];
    arr[left] = arr[low];
    arr[low] = temp;

    return low;
} 


void quickSort(vector<int> &arr, int low, int high)
{
    while(low < high)
    {
        int pivotPos = Partition(arr, low, high);
        Partition(arr, low, pivotPos-1);
        Partition(arr, pivotPos+1, high);
    }
}


int test(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    quickSort(arr, low, high);
    
    return arr[k-1];
}


int main(int argc, char* argv[])
{
    return 0;
}