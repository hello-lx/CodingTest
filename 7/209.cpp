/*  Python3
class Solution:
    """
    @param str: str: the given string
    @return: char: the first unique character in a given string
    """
    def firstUniqChar(self, str):
        # Write your code here
        if len(str) == 0: return
        
        d = {}
        
        for s in str:
            if s not in d: d[s] = 1
            else: d[s] += 1
            
        for k in d:
            if d[k]==1: return k
            
        return;
*/

#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here
        int s = str.size();
        
        for(int i=0; i<s; i++){
            int count = 0;
            for(int j=0; j<s; j++){
                if(str[i] == str[j])
                    count++;
                if(count > 1)
                    break;
            }
            
            if(count==1)
                return str[i];
        }
        
        return NULL;
    }
};
