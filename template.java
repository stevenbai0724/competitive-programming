import java.io.*;
import java.util.*;
public class template{  //class name must be same as the file name, so template.java must start with public class template
    public static void main(String [] args){
        Scanner sc = new Scanner (System.in);


// System.out.println(name.toUpperCase()); //"STEVEN"
// System.out.println(name.toLowerCase()); //"steven"
// System.out.println(name.charAt(0)); //S
// System.out.println(name.charAt(3)); //v
// System.out.println(name.substring(1,3)); //te
// System.out.println(name.substring(2,5)); //evE
// System.out.println(name.substring(1)); //tevEn
// String name = "StevEn";
// String greeting = "Hello and welcome";
// System.out.println(name.length()); //6
// System.out.println(name.equals("amogus")); //false
// System.out.println(name.equals("steven")); //false  
// System.out.println(name.equals("StevEn")); //true;
// System.out.println(name + " !"); //StevEn !
// System.out.println(greeting + ", " + name + "!"); //Hello and welcome, StevEn!

// int a = 5;
// int b = 2;
// double d = 2;

// System.out.println(a+b); //7;
// System.out.println(a-b); //3;
// System.out.println(a*b); //10;
// System.out.println(a/b); //2;
// System.out.println(a/d); //2.5;
// System.out.println(a%b); //1
// System.out.println((a+1)%b); //0;

// System.out.println(Math.max(5,8)); //8;
// System.out.println(Math.min(-7,-9)); //-9
// System.out.println(Math.floor(9.9)); //9.0
// System.out.println(Math.ceil(2.1)); //3.0
// System.out.println(Math.abs(9-20)); //11
// System.out.println(Math.random()); //random number from [0, 1)
// System.out.println(Math.sqrt(225)); //15.0;
// System.out.println(Math.pow(2,5)); //32.0

// == equal
// != not equal
// || or
// && and
// < less than
// <= less than or equal to
// > greater than
// >= greater than or equal to

        System.out.print("Enter the number of times to roll the die: ");
        int n = sc.nextInt();
        int sum = 0;
        for(int i=1;i<=n;i++){
            int rand = (int)(Math.random()*6);  // [0,6)
            rand++;
            System.out.println(rand);
            sum += rand;
        }
        System.out.println("The sum after rolling " + n + " times is " + sum);



    }
}