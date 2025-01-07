import java.util.*;

public class BinarySearchNthRoot {

    public static int midRaisedn(int num, int m, int n){
        long ans = 1;
        for(int i=0; i<n; i++){
            ans = ans * num;
            if(ans > m){
                return 2;
            }
        }
        if(ans == m){
            return 1;
        }
        return 0;
    }

    public static int nthRoot(int m, int n){
        int low = 1;
        int high = m;
        while(low <= high){
            int mid = low + (high - low)/2;
            int midRaised = midRaisedn(mid, m, n);
            if(midRaised == 1){
                return mid;
            }
            else if (midRaised == 0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println("N-th root is " + nthRoot(m, n));
    }
}
