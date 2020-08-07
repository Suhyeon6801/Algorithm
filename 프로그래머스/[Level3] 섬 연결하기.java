import java.util.ArrayList;
import java.util.Collections;

class Solution {
    static class Edge implements Comparable<Edge>{
        int from, to, cost;

        public Edge(int a, int b, int c){
            this.from=a;
            this.to=b;
            this.cost=c;
        }

        @Override
        public int compareTo(Edge arg0) {
            return this.cost-arg0.cost;
        }
    }

    static int par[] = new int[110];

    static int find(int x) {
        if(par[x]==x)	return par[x];
        else
            return find(par[x]);
    }

    static void merge(int a, int b) {
        int pa=find(a);
        int pb=find(b);

        par[pb]=pa;
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int len = costs.length;
		        
        for(int i=0; i<n; i++)
            par[i]=i;

        ArrayList<Edge> edge=new ArrayList<>();
        for(int i=0; i<len; i++) {	
            edge.add(new Edge(costs[i][0],costs[i][1],costs[i][2]));
        }

        Collections.sort(edge);
        
        int cnt=0;
        for(int i=0; i<len; i++) {
            int node1=edge.get(i).from;
            int node2=edge.get(i).to;
            
            if(find(node1)!=find(node2)) {
                merge(node1, node2);
                answer+=edge.get(i).cost; 		
                cnt++;

                if(cnt==n-1)	break;
            }
        }
        
        return answer;
    }
}