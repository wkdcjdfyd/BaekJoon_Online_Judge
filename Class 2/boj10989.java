import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj10989 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int[] count = new int[10001];
		int n = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < n; i++) {
            count[Integer.parseInt(br.readLine())]++;
        }
		br.close();
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = 1; i < 10001; i++) {
			while(count[i] > 0) {
				sb.append(i).append('\n');
				count[i]--;
			}
		}
		System.out.print(sb);
	}

}