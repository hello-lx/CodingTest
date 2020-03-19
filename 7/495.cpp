/* Java
public class Stack {
    private int initCapacity = 8;
    private Integer top = null;
    private int curIndex = 0;
    private Integer[] stack = new Integer[initCapacity];

    public void push(int t) {
        // write your code here
        int length = stack.length;
        if (curIndex == length) {
            resizeCapacity();
        }
        top = t;
        stack[curIndex++] = t;
    }

    // 扩容
    private void resizeCapacity() {
        int length = stack.length;
        if (length >= Integer.MAX_VALUE) {
            throw new RuntimeException("the stack max empty is" + Integer.MAX_VALUE);
        }
        Integer[] newStack = new Integer[length << 1];
        System.arraycopy(stack, 0, newStack, curIndex-1, length);
        stack = newStack;
    }

    public void pop() {
        // write your code here
         if(top==null){
            return;
        }
        stack[--curIndex]=null;
        if(curIndex==0){
            top = null;
        }else{
            top = stack[curIndex-1];
        }
        
    }

    public int top() {
        // write your code here
      
        return top;
    }

    public boolean isEmpty() {
        // write your code here
        return top == null;
    }
}
*/

