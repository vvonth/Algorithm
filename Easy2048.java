package programming2020_08_04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Easy2048 {
	static int N;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		N=Integer.parseInt(str);
		int[][] board=new int[N][N];
		for(int r=0;r<N;r++) {
			str=br.readLine();
			StringTokenizer st=new StringTokenizer(str);
			for(int c=0;c<N;c++) {
				board[r][c]=Integer.parseInt(st.nextToken());
			}
		}
		move(0,board);
		System.out.println(result);
	}
	static int result;
	private static void move(int cnt,int[][] copy) {
		// TODO Auto-generated method stub
		if(cnt==5) {
			int maxvalue=0;
			for(int r=0;r<N;r++) {
				for(int c=0;c<N;c++) {
					maxvalue=Math.max(copy[r][c], maxvalue);
				}
			}
			result=Math.max(result, maxvalue);
			return;
		}
		move(cnt+1,left(sum(left(copy))));
		move(cnt+1,left(sum(left(rotate(copy)))));
		move(cnt+1,left(sum(left(rotate(rotate(copy))))));
		move(cnt+1,left(sum(left(rotate(rotate(rotate(copy)))))));
	}
	private static int[][] rotate(int[][] arr) {
		int[][] tmp=new int[N][N];
		for(int c=0;c<N;c++) {
			for(int r=N-1;r>=0;r--) {
				tmp[c][N-1-r]=arr[r][c];
			}
		}
		return tmp;
	}
	private static int[][] left(int [][] arr) {
		int[][] tmp=new int[N][N];
		for(int r=0;r<N;r++) {
			int tmpC=0;
			for(int c=0;c<N;c++) {
				if(arr[r][c]!=0) {
					tmp[r][tmpC++]=arr[r][c];
				}
			}
		}
		return tmp;
	}
	private static int[][] sum(int[][] tmp) {
		// TODO Auto-generated method stub
		for(int r=0;r<N;r++) {
			for(int c=0;c<N;c++) {
				if(c>0&&tmp[r][c]==tmp[r][c-1]) {
					tmp[r][c-1]*=2;
					tmp[r][c]=0;
				}
			}
		}
		return tmp;
	}
}
