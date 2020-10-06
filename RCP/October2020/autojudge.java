import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class autojudge {
	public static void main(String[] args) throws Exception{
		ArrayList<String> veredictos = new ArrayList<>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String name = bf.readLine();
		String data[] = bf.readLine().split("\\.");
		if(!data[0].equals(name) || data.length !=2) {
			veredictos.add("Compile Error");
		}
		String extenciones []= {"c", "cpp", "java", "py"};
		boolean match = false;
		for(int i = 0; i<extenciones.length && data.length>1; ++i) {
			if(extenciones[i].equals(data[1])) {
				match = true;
			}
		}
		if(!match) {
			veredictos.add("Compile Error");
		}
		data = bf.readLine().split(" ");
		int r = Integer.parseInt(data[0]);
		int d = Integer.parseInt(data[1]);
		int e = Integer.parseInt(data[2]);
		if(r!=0) {
			veredictos.add("Run-Time Error");
		}
		if(e>d) {
			veredictos.add("Time Limit Exceeded");
		}
		int c = Integer.parseInt(bf.readLine());
		ArrayList<String> r1 = new ArrayList<>(), r2 = new ArrayList<>();
		for(int i = 0; i<c; ++i) {
			r1.add(bf.readLine());
		}
		int t = Integer.parseInt(bf.readLine());
		for(int i = 0; i<t; ++i) {
			r2.add(bf.readLine());
		}
		match = true;
		for(int i = 0; i<Math.min(r1.size(), r2.size()); ++i) {
			if(!r1.get(i).equals(r2.get(i))) {
				match = false;
			}
		}
		if(!match || c != t) {
			veredictos.add("Wrong Answer");
		}
		veredictos.add("Correct");
		System.out.println(veredictos.get(0));
	}
}
