/*
    1. 获取并对字符串进行拆分及排序重组相关预处理
    2. 对字符串数组进行排列并重复此步骤进行筛选
        1). 设定置换元素index（默认为**-1**，代表不进行元素置换）
        2). 从数组最高位项向下依次递减获取对应的置换元素及其下标值
        3). 若当前位项元素（nums[i]）大于待置换元素（nums[i-1]），则将index值更新为待置换元素项下标值并中止当前的循环置换操作。
        4). 对数组元素进行置换，原理同3所述。
        5). 重置后需要对原字符串进行还原。
        6). 返回并将当前置换结果存入结果集数组。
*/


/* ==================== JAVA ====================
public class Solution {
    // * @param str: A string
    // * @return: all permutations
    public List<String> stringPermutation2(String str) {
        // write your code here
       List<String> result = new ArrayList<String>();
        char[] s = str.toCharArray();
        Arrays.sort(s);
        result.add(String.valueOf(s));
        while ((s = nextPermutation(s)) != null) {
            result.add(String.valueOf(s));
        }
        return result;        
    }
    
    public char[] nextPermutation(char[] nums) {
        int index = -1;
        for(int i = nums.length -1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }
        if(index == -1){
            return null;
        }
        for(int i = nums.length -1; i > index; i--){
            if(nums[i] > nums[index]){
                char temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        reverse(nums,index+1,nums.length-1);
        return nums;
        
    }    
    
    public void reverse(char[] num, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }    
}
*/



int main(int argc, char** argv)
{
    
    return 0;
}