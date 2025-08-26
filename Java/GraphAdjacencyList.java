import java.util.*;

public class GraphAdjacencyList {

    static void printGraph(Map<Integer, List<Integer>> graph){
        for(Map.Entry<Integer, List<Integer>> entry: graph.entrySet()){
            int node = entry.getKey();
            List<Integer> neighbours = entry.getValue();
            System.out.println(node + " -> " + neighbours);
        }
    }
    
    public static void main(String[] args){
        
        int[][] edgeList = {
            {1,2}, {2,3}, {3,4}, {4,2}, {1,3}
        };

        int n = edgeList.length;
        Map<Integer, List<Integer>> adjacencyList = new HashMap<>();

        for(int i=0; i<n; i++){
            int a = edgeList[i][0];
            int b = edgeList[i][1];

            adjacencyList.putIfAbsent(a, new ArrayList<>());
            adjacencyList.get(a).add(b);
            adjacencyList.putIfAbsent(b, new ArrayList<>());
            adjacencyList.get(b).add(a);
        }

        printGraph(adjacencyList);
    }
}
