//https://dmoj.ca/problem/gfssoc2j3
import java.util.*;
import java.io.*;

public class gfssoc2j3 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        
        int sum = 0;
        Boolean plus = true;
        while(true){
            int n = sc.nextInt();
            char c = sc.next().charAt(0);

            if(plus==true)sum+=n;
            else sum-=n;

            if(c=='M')plus = false;
            if(c=='P')plus = true;

            if(c=='=')break;

        }
        System.out.println(sum);

      
    }
}