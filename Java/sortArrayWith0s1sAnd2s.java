import java.util.*;

public class sortArrayWith0s1sAnd2s {

    public static void sort(ArrayList<Integer> arr){
        int n = arr.size();
        int cnt0 = 0, cnt1 = 0;

        for(int i=0; i<n; i++){
            if(arr.get(i) == 0) cnt0++;
            else if(arr.get(i) == 1) cnt1++;
        }

        for(int i=0; i<cnt0; i++){
            arr.set(i, 0);
        }
        for(int i=cnt0; i<cnt0+cnt1; i++){
            arr.set(i, 1);
        }
        for(int i=cnt0+cnt1; i<n; i++){
            arr.set(i, 2);
        }
    }

    public static void sortPointers(ArrayList<Integer> arr){
        int n=arr.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(arr.get(mid) == 0){
                Collections.swap(arr, low, mid);
                low++;
                mid++;
            } 
            else if(arr.get(mid) == 1){
                mid++;
            }
            else if(arr.get(mid) == 2){
                Collections.swap(arr, mid, high);
                high--;
            }
        }
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for(int i=0; i<n; i++){
                int k = sc.nextInt();
                arr.add(k);
            }
            sortPointers(arr);
            System.out.print(arr);
        }
    }
}
