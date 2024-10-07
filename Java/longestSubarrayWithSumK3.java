import java.util.*;

/**
 * longestSubarrayWithSumK3
 */
public class longestSubarrayWithSumK3 {

    public static int getLongestSubArray(int arr[], long k){
        int n = arr.length;
        int l=0, r=0;
        long sum = arr[0];
        int maxLen = 0;
        while(r < n){
            while(l <= r && sum > k){
                sum-=arr[l];
                l++;
            }

            if(sum == k){
                maxLen=Math.max(maxLen, r-l+1);
            }

            r++;
            if(r<n)sum+=arr[r];
        }
        return maxLen;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner (System.in)){
            int n;
            n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }

            long k;
            k = sc.nextLong();
            int ans = getLongestSubArray(arr, k);
            System.out.print(ans);
        }
    }
}