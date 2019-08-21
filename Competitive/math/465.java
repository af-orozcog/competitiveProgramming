import java.util.Scanner;
import java.math.*;

public class Main{
	public static void main(String args[]){
		BigInteger comp = new BigInteger("1");
		comp = comp.shiftLeft(31);
		comp = comp.subtract(new BigInteger("1"));
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String vals = sc.nextLine();
			String sepa[] = vals.split(" ");
			BigInteger a = new BigInteger(sepa[0]);
			BigInteger b = new BigInteger(sepa[2]);
			BigInteger val;
			if(sepa[1].compareTo("*") == 0)
				val = a.multiply(b);
			else
				val = a.add(b);
			System.out.println(vals);
			if(a.compareTo(comp) > 0)
				System.out.println("first number too big");
			if(b.compareTo(comp) > 0)
				System.out.println("second number too big");
			if(val.compareTo(comp) > 0)
				System.out.println("result too big");
		}
	}
}