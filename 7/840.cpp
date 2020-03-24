#include <vector>
using namespace std;


class NumArray {

private:
    vector<int> arr;


public:
    NumArray(vector<int> nums) {
        arr = nums;
    }
    
    void update(int i, int val) {
        arr[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int left=i; left<=j; left++)
            sum += arr[left];
        return sum;
    }

};
