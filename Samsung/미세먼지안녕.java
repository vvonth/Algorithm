package programming2020_09_03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미세먼지안녕 {
	static int R;
	static int C;
	static int T;
	static int[][] room;
	static int[][] copy;
	static Queue<pos> dummy;
	static pos[] ac;

	static class pos {
		int r;
		int c;
		int val;
		public pos(int r, int c,int val) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
			this.val=val;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		room = new int[R][C];
		copy=new int[R][C];
		ac = new pos[2];
		dummy = new LinkedList<>();
		int cnt = 0;
		for (int r = 0; r < R; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < C; c++) {
				room[r][c] = Integer.parseInt(st.nextToken());
				if (room[r][c] == -1) {
					ac[cnt++] = new pos(r, c,-1);
				} else if (room[r][c] > 0) {
					dummy.add(new pos(r, c,room[r][c]));
					
				}
			}
		}
		
		for (int t = 1; t <= T; t++) {
			spread();
			//print();
			clean();
			//print();
			group();
		}
		int result=0;
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				if(room[r][c]>0) {
					result+=room[r][c];
				}
			}
		}
		System.out.println(result);
	}

	
	private static void group() {
		// TODO Auto-generated method stub
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				if(room[r][c]>0) {
					dummy.add(new pos(r,c,room[r][c]));
				}
			}
		}
	}

	private static void print() {
		System.out.println("--------print--------");
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				System.out.print(room[r][c]+" ");
			}
			System.out.println();
		}
		System.out.println("--------end--------");
	}
	private static void clean() {
		// TODO Auto-generated method stub
		int sr=ac[0].r;
		int sc=ac[0].c;
		sr+=dx[0];
		sc+=dy[0];
		int tmp=room[sr][sc];
		room[sr][sc]=0;
		int past=tmp;
		for(int k=0;k<4;k++) {
			while(true) {
				sr+=dx[k];
				sc+=dy[k];
				if(sr<0||sr>=R||sc<0||sc>=C||room[sr][sc]==-1) break;
				past=tmp;
				tmp=room[sr][sc];//현재를 저장
				room[sr][sc]=past;
			}
			sr-=dx[k];
			sc-=dy[k];
		}
		room[ac[0].r][ac[0].c]=-1;
		sr=ac[1].r;
		sc=ac[1].c;
		sr+=dm[0];
		sc+=dn[0];
		tmp=room[sr][sc];
		room[sr][sc]=0;
		for(int k=0;k<4;k++) {
			while(true) {
				sr+=dm[k];
				sc+=dn[k];
				if(sr<0||sr>=R||sc<0||sc>=C||room[sr][sc]==-1) break;
				past=tmp;
				tmp=room[sr][sc];//현재를 저장
				room[sr][sc]=past;
			}
			sr-=dm[k];
			sc-=dn[k];
		}
		room[ac[1].r][ac[1].c]=-1;
	}
	static int dm[]= {0,1,0,-1};
	static int dn[]= {1,0,-1,0};
	static int dx[] = { 0,-1,0,1};
	static int dy[] = { 1,0,-1,0};

	private static void spread() {
		// TODO Auto-generated method stub
		
		while (!dummy.isEmpty()) {
			pos p = dummy.poll();
			int count = 0;
			int sd = p.val / 5;
			for (int k = 0; k < 4; k++) {
				int nr = p.r + dx[k];
				int nc = p.c + dy[k];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C || room[nr][nc] == -1)
					continue;
				count++;
				room[nr][nc] += sd;

			}
			room[p.r][p.c]-=sd*count;
		}
	}

}
