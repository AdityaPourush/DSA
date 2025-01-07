import java.util.*;

public class BinarySearchPeakElement {

    public static int peakIndex(ArrayList<Integer> nums){
        int n = nums.size();
        // if only one element in array
        if(n == 1){
            return 0;
        }
        // checking for 1st element
        if(nums.get(0) > nums.get(1)){
            return 0;
        }
        // checking for last element
        if(nums.get(n-1) > nums.get(n-2)){
            return n-1;
        }

        // main process
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            // if mid is peak
            if(nums.get(mid) > nums.get(mid - 1) && nums.get(mid) > nums.get(mid + 1)){
                return mid;
            }
            // if mid lies in left half(ascending), eliminate the left half
            else if(nums.get(mid) > nums.get(mid - 1)){
                low = mid + 1;
            }
            // if mid lies in right half(descending), eliminate the right half
            else if(nums.get(mid) > nums.get(mid + 1)){
                high = mid - 1;
            }
            // if more than one peak exists, we have to abandon any one half.
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("Peak element in an Array");
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> nums = new ArrayList<Integer>();
        System.out.println("Enter number of characters in array: ");
        int n = sc.nextInt();
        for(int i=0; i<n; i++){
            nums.add(sc.nextInt());
        }
        int ans = peakIndex(nums);
        System.out.println("The peak index is " + ans);
    }
}
