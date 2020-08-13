package programming2020_08_13;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 경사로 {
	static int N;
	static int L;
	static int map[][];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < N; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		// 경사로의 길이: L , 높이 : 1
		int result=0;
		for (int r = 0; r < N; r++) {
			result+=find(map[r]);
			//System.out.println("r: "+r+" "+result);
		}
		int k[][]=rotate();
		
		for(int r=0;r<N;r++) {
			result+=find(k[r]);
		//	System.out.println("r: "+r+" "+result);
		}
		System.out.println(result);
	}

	private static int[][] rotate() {
		int [][]tmp=new int[N][N];
		for(int r=0;r<N;r++) {
			for(int c=0;c<N;c++) {
				tmp[r][c]=map[N-c-1][r];
			}
		}
		return tmp;
	}
	
	private static int find(int[] road) {
		boolean[] chk = new boolean[road.length];
		Arrays.fill(chk, false);
		// TODO Auto-generated method stub
		// 겹치는부분 생각할것 경사로 놨는데 겹치는부분...
		int diff = 0;
		boolean Lflag = true;
		for (int c = 1; c < N; c++) {
			diff = Math.abs(road[c] - road[c - 1]);
			if (diff == 1) {
				if (road[c] < road[c - 1]) { // 오른쪽<왼쪽
					
					int idx = c;
					//System.out.println("진입: "+(idx+L-2));
					if (chk[idx]) {
						Lflag = false;
						break;
					}
					chk[idx] = true;
					for (int i = idx; i < idx + L - 1; i++) {
						if ((i+1)>=N||(road[i] != road[i + 1]) || chk[i + 1]) {
							Lflag = false;
							break;
						} else {
							chk[i + 1] = true;
						}
					}
				} else {
					
					int idx = c - 1;
				//	System.out.println("진입"+" "+(idx-L+1)+" "+chk[idx-L+1]);
					if (chk[idx]) {
						Lflag = false;
						break;
					}
					chk[idx] = true;
					for (int i = idx; i > idx - L +1; i--) {
						if ((i-1)<0||(road[i] != road[i - 1]) || chk[i - 1]) {
							Lflag = false;
							break;
						} else {
							chk[i - 1] = true;
						}
					}
				}
			}else if(diff>1){
				break;
			}

			if (!Lflag) {
				break;
			}
		}
		
		if (diff > 1||!Lflag) {
			return 0;
		}
		return 1;
	}

}
