package org.thou.array;

public class _485_MaxConsecutiveOnes {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                count = 0;
            }else {
                count++;
                if(max < count){
                    max = count;
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] a = {1,1,0,1,1,1};
        System.out.println(findMaxConsecutiveOnes(a));
    }
}
