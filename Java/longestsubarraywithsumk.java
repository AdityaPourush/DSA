import java.util.*;

public class longestsubarraywithsumk {

public static int getLongestSubArray(int[] arr, long k){
    int n = arr.length;

    int len = 0;
    for(int i=0; i<n; i++){
        long sum = 0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum == k){
                len = Math.max(len, j-i+1);
            }
        }
    }
    return len;
}
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = 0;
            n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i]=sc.nextInt();
            }

            long k;
            k = sc.nextLong();
            int ans = getLongestSubArray(arr, k);
            System.out.print(ans);
        }
    }  
}