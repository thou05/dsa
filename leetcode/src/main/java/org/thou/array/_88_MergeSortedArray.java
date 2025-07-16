package org.thou.array;

//chèn
//a[k] > x -> ko co thi chen, co thi dich xuong 1 don vi

public class _88_MergeSortedArray {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int x: nums2) {
            ínsertIntoArray(x, nums1, m);
            m++;
        }

    }

    private static void ínsertIntoArray(int x, int[] nums1, int m) {
        boolean found = false;
        for(int i = 0; i < m; i++) {
            if(nums1[i] > x) {
                found = true;

                for(int j = m - 1; j >= i; j--){
                    nums1[j+1] = nums1[j];  // dich phan tu xuong 1 don vi
                }
                nums1[i] = x;
                break;
            }
        }
        if(!found) {
            nums1[m] = x; //chen vao cuoi
        }

    }

    public static void main(String[] args) {
        int [] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        merge(nums1, 3, nums2, 3);
        System.out.println("Done");
        for(int x : nums1) {
            System.out.print(x + " ");
        }
    }
}

