/* Java
class Solution {  
    public int quick(int[] prices){
        int max=0;
        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]>prices[i])
            max+=(prices[i+1]-prices[i]);
        }
        return max;
    }
    
    public int maxProfit(int k, int[] prices) {
        int len=prices.length;
       
      if(len==1||len==0||prices==null||k==0){
          return 0;
      }
      if(k>=len/2){
        return quick(prices);
      }  
        int []buy=new int[k+1];
        int []sell=new int[k+1];
        for(int i=0;i<=k;i++){
            buy[i]=Integer.MIN_VALUE;
        }
        for(int i=0;i<len;i++){   
            for (int j = 0; j<k; j++) {
                buy[j+1] = Math.max(buy[j+1], sell[j] - prices[i]);
                sell[j+1] = Math.max(buy[j+1] + prices[i], sell[j+1]);
            }
            
        }
        return sell[k];
        
    }
}
*/

#include <vector>
using namespace std;
#define INT_MIN -999999999

class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
     int quick(vector<int> &prices){
         int max = 0;
         for(int i=0; i<prices.size()-1; i++)
            if(prices[i+1] > prices[i])
                max += prices[i+1] - prices[i];
        
        return max;
     }
     
    int maxProfit(int K, vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if((len==1) || (len==0) || (K==0))
            return 0;
        if(K>=len/2) return quick(prices);

        vector<int> sell(K+1, 0);
        vector<int> buy(K+1, INT_MIN);
        
        for(int i=0; i<len; i++)
            for(int j=0; j<K; j++){
                buy[j+1] = max(buy[j+1], sell[j]-prices[i]);
                sell[j+1] = max(buy[j+1] + prices[i], sell[j+1]);
            }
        
        return sell[K];
    }
};
