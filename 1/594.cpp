#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999


/*
   KMP
*/


class Solution {
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
      int strStr2(const char* source, const char* target) {
         // write your code here
         if(!source || !target)
            return -1;
         if(!*target)
            return 0;
         std::vector<int> lps(1,0);
         const char* p=target+1;
         int len=1,l=0;
         while(*p){
            if(*p==target[l]){
                ++l;
            }
            else if(l){
                l=lps[l-1];
                continue;
            }
            lps.push_back(l);
            ++len;
            ++p;
         }

         cout << "lps: ";
         for(int i=0; i<lps.size(); i++)
            cout << lps[i] << ", ";
         cout << endl;

         for(l=1;l<len-1;++l){
            auto prev=lps[l];
            cout << l << ": " << prev << ", ";
            
            if(prev>0 && target[l+1]==target[prev])
            {
                lps[l]=lps[prev-1];
                cout << lps[prev-1] << ", ";
            }
         }
         cout << endl;

         cout << "lps2: ";
         for(int i=0; i<lps.size(); i++)
            cout << lps[i] << ", ";
         cout << endl;

         for(l=0,p=source;l<len&&*p;++p){
            if(target[l]==*p){
                ++l;
            }
            else{
                while(l){
                    l=lps[l-1];
                    if(target[l]==*p){
                        ++l;
                        break;
                    }
                }
            }
        }
        return l>=len?p-source-len:-1;
    }
};

int main()
{
   char *source = "abcccbbcccbdef", *target = "bcbcbcb";
   Solution s;
   s.strStr2(source, target);
   return 0;
}
