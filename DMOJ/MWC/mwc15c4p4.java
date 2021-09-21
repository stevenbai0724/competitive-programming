import java.util.*;
import java.io.*;

public class mwc15c4p4{

    public static void main(String[]args){

        Scanner sc = new Scanner (System.in);

        int nodes = sc.nextInt();
        int edges = nodes;
        int start;
        int end;
        ArrayList<Integer>adj[] = new ArrayList[nodes+1];

        for (int i = 1; i<= nodes; i++){
            adj[i] = new ArrayList();

        }

        for(int i = 0; i<nodes; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj[x].add(y);
 
        }

        start = sc.nextInt();
        end = sc.nextInt();

        Queue<Integer>q = new LinkedList();
        boolean[]vis = new boolean[nodes + 1];
        q.add(start);
        vis[start] = true;

        while(q.isEmpty() == false){
            int cur = q.poll();

            for(int i = 0; i<adj[cur].size(); i++){
                int nxt = adj[cur].get(i);
                if (vis[nxt] ==false){
                    vis[nxt] = true;
                    q.add(nxt);
                }

            }

        }

        if(vis[end] == true)
            System.out.println("Tangled");

        else
            System.out.println("Not Tangled");







    }
    
}