#include <iostream>
using namespace std;

int main()
{
    int num = 2;
    if(num & 0x2)
        std::cout << "num: " << num << std::endl;
    
    return 0;
}
