import java.util.*;

public class BinarySearchKokoEatingBananas {

    public static int hoursTaken(ArrayList<Integer> nums, int speed){
        int n = nums.size();
        int hrs = 0;
        for(int i = 0; i<n; i++){
            hrs += Math.ceil((double)nums.get(i) / (double)speed);
        }
        return hrs;
    }

    public static int minEatingSpeed(ArrayList<Integer> nums, int h){
        int low = 1;
        int high = Collections.max(nums);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int hrs = hoursTaken(nums, mid);
            if(hrs <= h){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            ArrayList<Integer> nums = new ArrayList<>();
            for(int i=0; i<n; i++){
                nums.add(sc.nextInt());
            }
            int h = sc.nextInt();
            int eatingSpeed = minEatingSpeed(nums, h);
            System.out.println("Minimum banana eating speed should be : " + eatingSpeed);
    }
}
