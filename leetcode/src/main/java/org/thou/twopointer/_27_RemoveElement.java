package org.thou.twopointer;

public class _27_RemoveElement {
    public static int removeElement(int[] nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.length; i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

    public static void main(String[] args) {
        int [] nums = {1, 3, 2, 5};
        int val = 3;
        System.out.println(removeElement(nums, val));
    }
}
