import java.util.*;

public class FractionalKnapSack {
    double fractionalKnapsack(List<Integer> val, List<Integer> wt, int capacity) {
        int n = val.size();
        // Create an array of indices and sort based on value/weight ratio in descending order
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;

        Arrays.sort(indices, (a, b) -> {
            double ratioA = (double) val.get(a) / wt.get(a);
            double ratioB = (double) val.get(b) / wt.get(b);
            return Double.compare(ratioB, ratioA); // Sort descending
        });

        double totalValue = 0;
        for (int i : indices) {
            if (capacity == 0) break; // Early exit if knapsack is full
            int weight = wt.get(i);
            int value = val.get(i);

            if (weight <= capacity) {
                totalValue += value;
                capacity -= weight;
            } else {
                // Take the fractional part
                totalValue += ((double) value / weight) * capacity;
                capacity = 0;
            }
        }
        return totalValue;
    }
    
    public static void main(String[] args){
        
    }
}
