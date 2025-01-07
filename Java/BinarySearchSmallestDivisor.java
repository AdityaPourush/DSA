// Find the Smallest Divisor Given a Threshold

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

import java.util.*;

public class BinarySearchSmallestDivisor {

    public static int divideAllByMidAndSum(ArrayList<Integer> nums, int mid){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += Math.ceil((double)nums.get(i)/(double)mid);
        }
        return sum;
    }

    public static int smallestDivisor(ArrayList<Integer> nums, int threshold){
        int low = 1;
        int high = Collections.max(nums);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int divSum = (divideAllByMidAndSum(nums, mid));
            if(divSum <= threshold){
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
        int threshold = sc.nextInt();
        System.out.println(smallestDivisor(nums, threshold));
    }
}
