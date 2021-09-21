import java.util.*;
import java.io.*;

public class mwc15c7p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int f = readInt();
        int r = readInt();
        
        int[][]array = new int[f][r];
        int[][]psa = new int[f][r];
        
        for (int i = 0 ; i<f; i++){
            for (int j = 0; j<r; j++){
                array[i][j] = readInt();
            }
        }
            
        for (int i = 0 ; i<f; i++){
            int sum = 0;
            for (int j = 0; j<r; j++){
                
                sum += array[i][j];
                psa[i][j] = sum;
            }
        }
        
        int q = readInt();
        
        for (int i = 0; i<q; i++){
            int a = readInt();
            int b = readInt();
            int c = readInt();
            
            if (a == 1)
            System.out.println(psa[c-1][b-1]);
            
            else
            System.out.println(psa[c-1][b-1] - psa[c-1][a-2]);
        }
        
        
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