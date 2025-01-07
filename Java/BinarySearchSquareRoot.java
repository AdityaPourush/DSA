import java.util.*;
import java.text.DecimalFormat;

public class BinarySearchSquareRoot {

    public static int SquareRoot(int num){
        int low = 1;
        int high = num;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid * mid <= num){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#.000");
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // System.out.println(df.format(Math.sqrt(n)));
        System.out.println("Square Root: " + SquareRoot(n));
    }
}
