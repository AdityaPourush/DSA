// Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

import java.util.Scanner;

public class longestSubArraywithSumKPN {

    public static int longestSubarrayLengthBruteForce(int arr[], long k){
        int n = arr.length;
        int len = 0;
        for(int i=0; i<n; i++){
            int sum = arr[i];
            for(int j=i+1; j<n; j++){
                sum+=arr[j];
                if(sum == k){
                    len = Math.max(len, j-i+1);
                }
            }
        }
        return len;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }

            long k = sc.nextLong();
            int ans = longestSubarrayLengthBruteForce(arr, k);
            System.out.print(ans);
        }
    }
    
}
