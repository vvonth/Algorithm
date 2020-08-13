package programming2020_08_11;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 스타트와링크 {
	static int N;
	static int S[][];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		S = new int[N][N];
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < N; c++) {
				S[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		result=Integer.MAX_VALUE;
		chk=new boolean[N];
		comb(0,0,new int[N/2]);
		System.out.println(result);
	}
	static boolean chk[];
	static int result;
	static int allCnt;
	private static void comb(int idx, int cnt, int[] arr) {
		// TODO Auto-generated method stub
		if(allCnt==(N*(N-1)/2)/2)
			return;
		if(idx==arr.length) {
			//System.out.println(Arrays.toString(arr));
			for(int i=0;i<arr.length;i++) {
				chk[arr[i]]=true;
			}
			int sum=0;
			for(int i=0;i<chk.length-1;i++) {
				if(chk[i]) {
					for(int j=i+1;j<chk.length;j++) {
						if(chk[j]) {
							sum+=S[i][j]+S[j][i];
						}
					}
				}else {
					for(int j=i+1;j<chk.length;j++) {
						if(!chk[j]) {
							sum=sum-(S[i][j]+S[j][i]);
						}
					}
				}
			}
			result=Math.min(result, Math.abs(sum));
			Arrays.fill(chk, false);
			allCnt++;
			return;
		}
		
		if(cnt==N) {
			return;
		}
		arr[idx]=cnt;
		comb(idx+1,cnt+1,arr);
		comb(idx,cnt+1,arr);
	}
}