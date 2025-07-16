package org.thou.array;

public class _27_RemoveElement {
    //b1: duyet mang
    //b2: xoa phan tu bang cach dich cac phan tu con lai ve ben trai
    public static int removeElement(int[] nums, int val) {
        int n = nums.length;
        for (int i = 0; i < n; ){
            if(nums[i] == val){
                for(int j = i; j < n - 1; j++){
                    nums[j] = nums[j+1];
                }
                n--;
            }else{
                i++; // chi tang i neu khong xoa phan tu
            }
        }
        return n;
    }

    public static void main(String[] args) {
        int [] nums = {1, 3, 2, 5};
        int val = 3;
        System.out.println(removeElement(nums, val));
    }
}
