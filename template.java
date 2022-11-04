import java.util.*;
import java.io.*;

public class template{

    public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    boolean asdf = true;

    for (int i = 0; i < s.length(); i = i + 2){

        int j = i + 1;

        if ((s.charAt(i) == '(') && (s.charAt(j) == ')')){

            asdf = true;

        }
        else if ((s.charAt(i) == '[') && (s.charAt(j) == ']')){

            asdf = true;

        }
        else if ((s.charAt(i) == '{') && (s.charAt(j) == '}')){

            asdf = true;

        }
        else{

            asdf = false;
            break;

        }

    }
    
    System.out.println(asdf);

}

}