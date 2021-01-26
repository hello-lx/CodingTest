class Solution {
public:
    int Partition(vector<int> &vec, int &low, int &high)
    {
        int temp;
        int left = low, pivot = vec[low];
        while(low < high)
        {
            while(low < high && vec[high] >= pivot)
                high--;
            while(low < high && vec[low] <= pivot)
                low++;

            if(low < high)
            {
                temp = vec[low];
                vec[low] = vec[high];
                vec[high] = temp;
            }
        }
        
        temp = vec[low];
        vec[low] = vec[left];
        vec[left] = temp;

        return low;
    }

    void quickSort(vector<int> &vec, int low, int high){
        if(low>=high)
            return;
        
        while(low < high)
        {
            int pivotPos = Partition(vec, low, high);
            quickSort(vec, low, pivotPos-1);
            quickSort(vec, pivotPos+1, high);
        }
    }


    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> fun;
        quickSort(nums1, 0, nums1.size()-1);
        quickSort(nums2, 0, nums2.size()-1);

        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                i++;
                j++;
                fun.push_back(nums1[i]);
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return fun;
    }
};