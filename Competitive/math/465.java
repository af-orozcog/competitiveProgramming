import java.util.Scanner;
import java.math.*;

public class Main{
	public static void main(String args[]){
		BigInteger comp = new BigInteger("1");
		comp = comp.shiftLeft(31);
		comp = comp.subtract(new BigInteger("1"));
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			BigInteger a = sc.nextBigInteger();
			char op = sc.next().charAt(0);
			BigInteger b = sc.nextBigInteger();
			BigInteger val;
			if(op == '*')
				val = a.multiply(b);
			else
				val = a.add(b);
			System.out.println(a + " " + op + " "+ b);
			if(a.compareTo(comp) > 0)
				System.out.println("first number too big");
			if(b.compareTo(comp) > 0)
				System.out.println("second number too big");
			if(val.compareTo(comp) > 0)
				System.out.println("result too big");
		}
	}
}