#include <vector>
#include <iostream>
using namespace std;

int main()
{
//     int num = 2;
//     if(num & 0x2)
//         std::cout << "num: " << num << std::endl;
    
    vector<int> nums;
    for(int i=0; i<5; i++)
        nums.push_back(i);
    
    nums[0] ^= nums[3];
    nums[3] ^= nums[0];
    nums[0] ^= nums[3];

// 01
// 10    
    
    for(int i=0; i<5; i++){
        cout << nums[i] << endl;
    }
    
    return 0;
}
