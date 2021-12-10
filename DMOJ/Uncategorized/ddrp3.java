import java.util.*;
import java.io.*;
public class tudorAndThePusheens {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int n = readInt(); //nodes
        int m = readInt(); //connections
        int start;
        int end;
        ArrayList<Integer>adj[] = new ArrayList[n + 1];

        for (int i = 1; i<=n; i++){
            adj[i] = new ArrayList();
        }

        for(int i = 0 ; i<m; i++){
            int x = readInt();
            int y = readInt();

            adj[x].add(y);
            adj[y].add(x);

        }

        start = readInt();
        end   = readInt();


        Queue<Integer>q = new LinkedList();
        boolean[]vis = new boolean[n + 1];
        int[] dis = new int[n +1];

        q.add(start);
        vis[start] = true;

        while(q.isEmpty() == false){
            int cur = q.poll();

            for(int i = 0; i<adj[cur].size(); i++){
                int nxt = adj[cur].get(i);

                if (vis[nxt] == false){
                    vis[nxt] = true;
                    dis[nxt] = dis[cur] + 1;
                    q.add(nxt);
                }
            }

        }
        System.out.println(m - dis[end]);

    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readChar () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}