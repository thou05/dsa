//https://neetcode.io/problems/duplicate-integer

package org.thou.arrayandhashing;

import java.util.Arrays;

public class ContainsDuplicate {
    public boolean hasDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i = 1; i < nums.length; i++){
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }

}
