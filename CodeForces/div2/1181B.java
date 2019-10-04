import java.util.*;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String check = sc.next();
		int mid = num / 2;
		if(check.charAt(mid) != '0'){
			if(num%2 == 0){
				BigInteger one = new BigInteger(check.substring(0,mid));
				BigInteger two = new BigInteger(check.substring(mid,num));
				one = one.add(two);
				System.out.println(one);
				return;
			}
			if(check.charAt(mid) < check.charAt(0)){
				BigInteger one = new BigInteger(check.substring(0,mid));
				BigInteger two = new BigInteger(check.substring(mid,num));
				one = one.add(two);
				System.out.println(one);
				return;
			}
			else{
				BigInteger one = new BigInteger(check.substring(0,mid+1));
				BigInteger two = new BigInteger(check.substring(mid+1,num));
				BigInteger three = new BigInteger(check.substring(0,mid));
				BigInteger four = new BigInteger(check.substring(mid,num));
				one = one.add(two);
				three = three.add(four);
				if(one.compareTo(three) < 0)
					System.out.println(one);
				else
					System.out.println(three);
				return;
			}
		}
		else{
			int i = mid;
			while(check.charAt(i) == '0')
				--i;
			int j = mid;
			while(j < num && check.charAt(j) == '0' )
				++j;
			if(i == 0){
				BigInteger three = new BigInteger(check.substring(0,j));
				BigInteger four = new BigInteger(check.substring(j,num));
				three = three.add(four);
				System.out.println(three);
				return ;
			}
			if(j == num){
				BigInteger one = new BigInteger(check.substring(0,i));
			BigInteger two = new BigInteger(check.substring(i,num));
			one = one.add(two);
			System.out.println(one);
			return;
			}
			BigInteger one = new BigInteger(check.substring(0,i));
			BigInteger two = new BigInteger(check.substring(i,num));
			BigInteger three = new BigInteger(check.substring(0,j));
			BigInteger four = new BigInteger(check.substring(j,num));
			one = one.add(two);
			three = three.add(four);
			if(one.compareTo(three) < 0)
				System.out.println(one);
			else
				System.out.println(three);
		}
	}
}
