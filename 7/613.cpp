#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int id, score;
    Student(): id(0), score(0){}
    Student(int a, int b): id(a), score(b){}
};

// int Partition(vector<int> &arr, int low, int high)
// {
//     int left=low, pivot=arr[low], temp;

//     while(low < high)
//     {
//         while(low < high && arr[high] > pivot)
//             high--;
//         while(low < high && arr[low] < pivot)
//             low++;
        
//         if(low < high)
//         {
//             temp = arr[low];
//             arr[low] = arr[high];
//             arr[high] = arr[low];
//         }
//     }

//     temp = arr[left];
//     arr[left] = arr[low];
//     arr[low] = temp;

//     return low;
// } 


// void quickSort(vector<int> &arr, int low, int high)
// {
//     while(low < high)
//     {
//         int pivotPos = Partition(arr, low, high);
//         Partition(arr, low, pivotPos-1);
//         Partition(arr, pivotPos+1, high);
//     }
// }


int test(vector<Student> &arr, int k)
{
    // 首先对arr根据id进行分割成多个子arr
    // 然后对每个子arr进行排序
    // 排序完毕后对每个学生取前5个的平均数
    vector<vector<Student>> students;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i].id > students.size())
        {
            vector<Student> s;
            s.push_back(arr[i]);
        }
        else
        {
            students[arr[i].id-1].push_back(arr[i]);
        }
    }

    int low = 0, high = arr.size() - 1;
    // quickSort(arr, low, high);
    
    return arr[k-1];
}


int main(int argc, char* argv[])
{
    return 0;
}