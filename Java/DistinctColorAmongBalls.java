import java.util.*;

public class DistinctColorAmongBalls {

    public static int[] queryResults(int limit, int[][] queries){
        int n = queries.length;
        HashMap<Integer, Integer> ball_to_color = new HashMap<>();
        HashMap<Integer, Integer> colorCounts = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();

        for (int[] query : queries) {
            if (colorCounts.containsKey(query[0])) {
                colorCounts.put(query[1], colorCounts.get(query[1]) - 1);
                if (colorCounts.get(query[1]) == 0) {
                    colorCounts.remove(query[1]);
                }
            }

            ball_to_color.put(query[0], query[1]);
            colorCounts.put(query[1], colorCounts.getOrDefault(query[1], 0) + 1);
            res.add(colorCounts.size());
        }
        return res.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        int limit = 4;
        int[][] queries = {{1,4},{2,5},{1,3},{3,4}};
        int[] res = queryResults(limit, queries);
        for(int x: res){
            System.out.println(x);
        }
    }
}
