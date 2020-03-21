/* Python3
import random

class RandomizedSet:
    
    def __init__(self):
        # do intialization if necessary
        self.d = []

    """
    @param: val: a value to the set
    @return: true if the set did not already contain the specified element or false
    """
    def insert(self, val):
        # write your code here
        if val not in self.d:
            self.d.append(val)

    """
    @param: val: a value from the set
    @return: true if the set contained the specified element or false
    """
    def remove(self, val):
        # write your code here
        if val in self.d:
            self.d.remove(val)

    """
    @return: Get a random element from the set
    """
    def getRandom(self):
        # write your code here
        return random.choice(self.d)
*/



#include <vector>
#include <map>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    map<int, int> dict;
public:
    RandomizedSet() {
        // do intialization if necessary
    }

/*
* @param val: a value to the set
* @return: true if the set did not already contain the specified element or false
*/
bool insert(int val) {
    // write your code here
        if(dict.count(val)){
            return false;
        }
        nums.push_back(val);
        dict[val]=nums.size()-1;
    }

    /*
    * @param val: a value from the set
    * @return: true if the set contained the specified element or false
    */
    bool remove(int val) {
        // write your code here
        if(!dict.count(val)){
            return false;
        }         
        nums[dict[val]] = nums[nums.size()-1];  
        dict[nums[nums.size()-1]]=dict[val];
        
        nums.pop_back();  
        dict.erase(val);  
        return true;  
    }

    /*
    * @return: Get a random element from the set
    */
    int getRandom() {
        // write your code here
        return nums[rand() % nums.size()];
    }
};
