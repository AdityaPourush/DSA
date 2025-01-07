import java.util.*;

public class BinarySearchMinimumDaysToMakeBouquets {

    public static boolean possibleToMakeMBouquets(ArrayList<Integer> bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int flowerCount = 0;
        int bouquetCount = 0;
        for(int i=0; i<n; i++){
            if(bloomDay.get(i) <= day){
                flowerCount++;
            }
            else {
                bouquetCount += (flowerCount/k);
                flowerCount = 0;
            }
        }
        bouquetCount += (flowerCount/k);
        return (bouquetCount >= m);
    }

    public static int minDays(ArrayList<Integer> bloomDay, int m, int k){
        int mini = Collections.min(bloomDay);
        int maxi = Collections.max(bloomDay);

        int low = mini;
        int high = maxi;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(possibleToMakeMBouquets(bloomDay, mid, m, k)){
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
        ArrayList<Integer> bloomDay = new ArrayList<>();
        for(int i=0; i<n; i++){
            bloomDay.add(sc.nextInt());
        }
        int m = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(minDays(bloomDay, m, k));
    }
}
