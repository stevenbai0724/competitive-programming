import java.io.*;
import java.util.*;
public class template{  //class name must be same as the file name, so template.java must start with public class template
    public static void main(String [] args){
        Scanner sc = new Scanner (System.in);

        //N
        //N lines for the student's answer
        //N lines for the corrcet answers


        /*
        3
        A
        B
        A
        A
        A
        B
        */

        int n = sc.nextInt();

        String[] student = new String[n+1];
        String[] answer = new String[n+1];

        //input for student

        for(int i=1;i<=n;i++){
            student[i] = sc.next();
        }

        //student[] = {"", "A", "B", "A"}

        //input for teacher
        for(int i=1;i<=n;i++){
            answer[i] = sc.next();
        }

        int ans = 0;

        for(int i=1;i<=n;i++){
            if(student[i].equals(answer[i])) ans++;
        }

        System.out.println(ans);


    }
}