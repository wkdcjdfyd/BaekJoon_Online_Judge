import java.util.Scanner;

public class boj10871 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int max = sc.nextInt();
		
		for(int i=0; i<n; i++) {
			int num = sc.nextInt();
			
			if(num < max) {
				System.out.print(num + " ");
			}
		}

	}

}
