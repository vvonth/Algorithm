package programming2020_08_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Επ»η {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		int N=Integer.parseInt(str);
		int []T=new int[N+1];
		int []P=new int[N+1];
		for(int i=1;i<=N;i++) {
			str=br.readLine();
			StringTokenizer st=new StringTokenizer(str);
			T[i]=Integer.parseInt(st.nextToken());
			P[i]=Integer.parseInt(st.nextToken());
		}
		int dp[]=new int[N+1];
		for(int i=1;i<=N;i++) {
			dp[i]=P[i];
		}
		for(int i=1;i<=N;i++) {
			if(N<i+T[i]-1) {
				dp[i]=0;
				continue;
			}
			for(int j=1;j<i;j++)
			{
				
				if(i-(j+T[j]-1)>0) {
					dp[i]=Math.max(dp[i],dp[j]+P[i]);
				}
			}
		}
		int result=dp[0];
		for(int i=1;i<=N;i++) {
			result=Math.max(result, dp[i]);
		}
		System.out.println(result);
	}

}
