

public class GraphMatrix {

    static void printGraph(int[][] graph){
        int n = graph.length;
        for(int i=1; i<n; i++){
            System.out.print("Node: " + i + " -> ");
            for(int j=1; j<n; j++){
                if(graph[i][j] == 1){
                    System.out.print(j + ", ");
                }
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int[][] edgeList = {
            {1,2}, {2,3}, {3,4}, {4,2}, {1,3}
        };
        
        int n = edgeList.length;
        int[][] adjecencyMatrix = new int[n][n];

        for (int i=0; i<n; i++){
            int a = edgeList[i][0];
            int b = edgeList[i][1];

            adjecencyMatrix[a][b] = 1;
            adjecencyMatrix[b][a] = 1;
        }

        printGraph(adjecencyMatrix);

    }
}
