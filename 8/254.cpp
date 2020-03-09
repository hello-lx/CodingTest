class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        // write your code here
        int a=1;
        double sum=0;
        while(sum<n){
            sum += a;
            a++;
        }
        return a-1;
    }
};
