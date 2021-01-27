#include <iostream>
#include <vector>
using namespace std;

int sumK(vector<int> &vec, int i, int k)
{
    int s;
    for(int j=i; j<i+k; j++)
        s += vec[j];
    return s;
}

int test(vector<int> &vec, int k)
{
    if(vec.size() < k)
        return 0;
    
    int len = vec.size()-k;
    int maxValue=0, maxId=0, s;
    for(int i=0; i<len; i++)
    {
        s = sumK(vec, i, k);
        if(s > maxValue)
        {
            maxValue = s;
            maxId = i;
        }
    }

    return maxId;
}


int main(int argc, char* argv[])
{
    return 0;
}