import java.util.*;
import java.util.stream.Collectors;

class Main {
    static class Edge {
        int from;
        int to;
        int cost;

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    static int V; 
    static int E; 
	static Edge[] edges;
	
	static int[] d;
	
	static int INF = Integer.MAX_VALUE/2; 

    /*
	 * @param s　idx for start V
     * true if negative cost is detected
     */
	static boolean bellman_ford(int s) {
        d = new int[V];
        Arrays.fill(d, INF); 
        d[s] = 0;

        int cnt = 0;
        while(cnt < V) {
            boolean end = true;
            for (Edge e : edges) {
                if (d[e.from] != INF && d[e.from] + e.cost < d[e.to]) {
                    d[e.to] = d[e.from] + e.cost;
                    end = false;
                }
            }
            if (end) break;
            cnt++;
        }
        return (cnt == V);
    }

    public static void main(String[] args) {
        V = 5;
        E = 7;
        edges = new Edge[E];
        Edge edge = new Edge(0, 1, 2); edges[0] = edge;
        edge = new Edge(1, 3, 7); edges[1] = edge;
        edge = new Edge(2, 1, 4); edges[2] = edge;
        edge = new Edge(3, 2, 2); edges[3] = edge;        
        edge = new Edge(3, 0, 5); edges[4] = edge; 
        edge = new Edge(0, 4, 6); edges[5] = edge; 
        edge = new Edge(4, 3, 2); edges[6] = edge; 

        bellman_ford(1);

        print();

        return;
    }

    static void print() {
        for (int e : d) {
            System.out.println(e);
        }
    }
}