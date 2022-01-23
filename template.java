import java.io.*;
import java.util.*;
public class template{  //class name must be same as the file name, so template.java must start with public class template
    public static void main(String [] args){
        Scanner sc = new Scanner (System.in);



        //input is N. N integers will follow, representing the values in the array of size N
        //then, the input is Q. Q lines will follow, each with integers a, 
        //output the sum of all integers between arr[a] and arr[b], 

        /*
            
            7 3 5 8 2 
            
            1 
            3 
            1 

            
            
            

        */
        int n = sc.nextInt();
        int[] arr = new int[N+1]; 

        //arr = {0,0,0,0,0,0,0}

        for(int i=1;i<=n;i++){
            arr[i] = sc.nextInt();
        }

        //arr = {0,7,3,5,8,2,8}

        int q = sc.nextInt();

        for(int i=1;i<=q;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int sum = 0;

            for(int j=a;j<=b;j++){
                sum += arr[j];
            }

            System.out.println(sum);

        }

        


    }
}