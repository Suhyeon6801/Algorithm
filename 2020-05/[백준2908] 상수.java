import java.util.Scanner;
import java.lang.String;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		
		a=reverse(a);
		b=reverse(b);
		
		if(a.compareTo(b)>0)
			System.out.println(a);
		else
			System.out.println(b);
	}
	
	public static String reverse(String str) {
		return (new StringBuffer(str).reverse().toString());
	}
}