import java.util.*;
import java.text.*;

public class MyClass {
    public static void main(String args[]) throws Exception{
        String days[] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		String dateString = "22/09/";
		dateString = dateString + (year+1867);
		
		Date check = new SimpleDateFormat("dd/MM/yyyy").parse(dateString);
	//	System.out.println(check);
		Calendar ca = Calendar.getInstance();
		ca.setTime(check);
		System.out.println(days[ca.get(Calendar.DAY_OF_WEEK)-1]);
    }
}