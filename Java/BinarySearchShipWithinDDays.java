import java.util.*;

public class BinarySearchShipWithinDDays {
    
    public static int daysToShip(ArrayList<Integer> weights, int minWeight){
        int n = weights.size();
        int days = 1;
        int currWeight = 0;
        for(int i=0; i<n; i++){
            if(currWeight + weights.get(i) > minWeight){
                currWeight = weights.get(i);
                days++;
            }
            else {
                currWeight += weights.get(i);
            }
        }
        return days;
    }

    public static int shipWithinDays(ArrayList<Integer> weights, int days){
        int n = weights.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += weights.get(i);
        }
        int low = Collections.max(weights);
        int high = sum;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(daysToShip(weights, mid) <= days){
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
        ArrayList<Integer> weights = new ArrayList<>();
        for(int i=0; i<n; i++){
            weights.add(sc.nextInt());
        }
        int days = sc.nextInt();
        System.out.println(shipWithinDays(weights, days));
        // System.out.println(daysToShip(weights, days));
    }
}
