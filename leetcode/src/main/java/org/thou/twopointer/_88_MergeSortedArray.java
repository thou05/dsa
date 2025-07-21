package org.thou.twopointer;

public class _88_MergeSortedArray {
    public static void merge(int[] nums1, int m, int[] nums2, int n){
        int i = m - 1;
        int j = n - 1;
        int k = (m+n) - 1;

        while (k >= 0){
            if(j < 0){
                nums1[k] = nums1[i];
                i--;
            } else if (i < 0) {
                nums1[k] = nums2[j];
                j--;
            }else if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }

    public static void main(String[] args) {
        int[] nums1 = new int[]{1,2,3,4,5,0,0,0,0};
        int[] nums2 = new int[]{6,7,8,9};
        merge(nums1, 5, nums2, 4);
        System.out.println("DONE");
    }
}
