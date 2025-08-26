import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int[] nums = {14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14};
        int x = numSubseq(nums, 22);
        System.out.print(x);
    }

    public static int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int MOD = 1000000007;
        int n = nums.length;

        // Precompute powers of 2
        int[] pow = new int[n];
        pow[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i-1] * 2) % MOD;
        }

        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
    
    
}
