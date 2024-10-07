import java.util.*;

public class KadaneAlgorithmMaximumSubArraySum {

    public static int bruteForceMaxSum(int[] arr){
        int n = arr.length;
        int maxSum = -999;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum+=arr[k];
                }
                maxSum = Math.max(maxSum, sum);
            }
        }
        return maxSum;
    }

    public static int betterMaxSum1(int[] arr){
        int n = arr.length;
        int maxSum = Integer.MIN_VALUE;
        for(int i = 0; i<n; i++){
            int sum = arr[i];
            for(int j=i+1; j<n; j++){
                sum+=arr[j];
                
                maxSum = Math.max(maxSum, sum);
            }
        }
        return maxSum;
    }

    public static int optimalMaxSum(int[] arr){
        int n=arr.length;
        int sum = arr[0];
        int maxSum = arr[0];
        for(int i=1; i<n; i++){
            sum+=arr[i];
            if(sum < 0){
                sum = 0;
            }
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }

    public static int optimalReturnsSubarray(int[] arr){
        int n = arr.length;
        int sum = 0;
        int maxSum = 0;
        int startIndex = 0;
        int start = 0;
        int endIndex = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum < 0){
                sum = 0;
                start = i+1;
            }
            if(sum > maxSum){
                maxSum = sum;
                startIndex = start;
                endIndex = i;
            }
        }

        for(int i=startIndex; i<=endIndex; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        return maxSum;
    }

    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            int ans = optimalReturnsSubarray(arr);
            System.out.print(ans);
        }
    }
    
}
