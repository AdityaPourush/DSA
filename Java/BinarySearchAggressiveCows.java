import java.util.*;

public class BinarySearchAggressiveCows {

    public static boolean fitsAllCows(ArrayList<Integer> nums, int k, int dist){
        int n = nums.size();
        int currPos = nums.get(0);
        int cowsPlaced = 1;
        for(int i=1; i<n; i++){
            if(nums.get(i) - currPos >= dist){
                currPos = nums.get(i);
                cowsPlaced++;
                if(cowsPlaced == k){
                    return true;
                }
            }
        }
        return false;
    }

    public static int maxMinDistance(ArrayList<Integer> nums, int k){
        // sorting the array
        Collections.sort(nums);
        // maximum range : max(stalls) - min(stalls)

        int low = 1;
        int high = nums.get(nums.size() - 1) - nums.get(0);
        int ans = 0;

        // binary search between 1 and max to find if that fits to keep the cows
        while(low <= high){
            int mid = low + ((high - low)/2);

            if(fitsAllCows(nums, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid -1; 
            }
        }
        return ans;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> stalls = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            stalls.add(sc.nextInt());
        }
        int k = sc.nextInt();
        int minDistance = maxMinDistance(stalls, k);
        System.out.println(minDistance);
    }
}
