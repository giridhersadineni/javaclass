import java.io.*;
import java.util.Scanner;
class readnumbers{
    public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);
            System.out.println("enter a number");
            int n=sc.nextInt();
            System.out.println("enter another number");
            int m=sc.nextInt();
            int sum=n+m;
            System.out.println("The sum of both numbers is "+sum);
            sc.close();
    }
   
}