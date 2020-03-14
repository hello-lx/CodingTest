#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
         long sum = (int)key[0];
         for(int i=1;i<=key.length()-1;i++){
              sum = sum*33%HASH_SIZE+(int)key[i];
         }
         return (int)sum%HASH_SIZE;
    }
};
