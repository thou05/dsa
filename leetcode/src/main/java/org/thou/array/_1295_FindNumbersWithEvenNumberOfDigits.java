package org.thou.array;

public class _1295_FindNumbersWithEvenNumberOfDigits {
    //b1: duyet mang
    //b2: dem so chu so cua tung phan tu

    public static int findNumbers(int[] nums) {
        int count = 0;
        for(int x : nums){
            //ktra so chu so cua a
            if(countNumberOfDigits(x) % 2 == 0){
                count++;
            }

        }
        return count;
    }

    private static int countNumberOfDigits(int x) {
        int count = 0;
        int result = x;
        while (result != 0) {
            result = x / 10;
            x = result;
            count++;
        }
        return count;
    }


    public static void main(String[] args) {
        int[] nums = {12, 345, 2, 6, 7896};
        System.out.println(countNumberOfDigits(234));
        System.out.println(findNumbers(nums));
    }
}
