#include <vector>
using namespace std;

class Solution {
public:
    int Partition(vector<int> &nums, int &low, int &high){
        int temp;
        int left = low, pivot = nums[low];
        while(low < high)
        {
            while(low<high && nums[high] >= pivot)
                high--;
            while(low<high && nums[low] <= pivot)
                low++;
            if(low < high)
            {
                temp = nums[high];
                nums[high] = nums[low];
                nums[low] = temp;
            }
        }
        
        temp = nums[low];
        nums[low] = nums[left];
        nums[left] = temp;

        return low;
    }

    void qucikSort(vector<int> &nums, int low, int high){
        if(low >=high)
            return ;

        while(low < high)
        {
            int pivotPos = Partition(nums, low, high);
            qucikSort(nums, low, pivotPos-1);
            qucikSort(nums, pivotPos+1, high);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m; i<n; i++)
            nums1[i] = nums2[i-m];
        int low=0, high=nums1.size()-1;
        qucikSort(nums1, low, high);
    }
};

int main(int argc, char** argv)
{
    
    return 0;
}