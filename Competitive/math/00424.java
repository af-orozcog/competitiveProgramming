import java.util.Scanner;
import java.math.*;
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		while(true){
			BigInteger ad = sc.nextBigInteger();
			if(ad.compareTo(BigInteger.ZERO) == 0)
				break;
			ans = ans.add(ad);
		}
		System.out.println(ans);
	}
}