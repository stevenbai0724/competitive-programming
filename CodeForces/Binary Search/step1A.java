import java.util.*;
import java.io.*;
public class step1A {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int n = readInt();
        int q = readInt();
        int[]array = new int[n];
        

        for(int i = 0; i<n ; i++){
            array[i] = readInt();
        }

        for(int i = 0; i<q; i++){
            int x = readInt();
            
            if(Arrays.binarySearch(array, x) >=0) System.out.println("YES");
            else System.out.println("NO");
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