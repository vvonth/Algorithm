package programming2020_08_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class ¿¬±¸¼Ò {
	public static class node {
		int r;
		int c;

		public node(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
		}
	}
	static List<node> list;
	static int R;
	static int C;
	static int[][]map;
	static Queue<node> virus;
	static int result;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new int[R][C];
		list=new ArrayList<>();
		virus=new LinkedList<node>();
		for (int r = 0; r < R; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < C; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
				if(map[r][c]==0) {
					list.add(new node(r,c));
				}else if(map[r][c]==2) {
					virus.add(new node(r,c));
				}
			}
		}
		comb(0,0,new int[3]);
		System.out.println(result);
	}

	private static void comb(int idx, int cnt, int[] arr) {
		// TODO Auto-generated method stub
		if(cnt==arr.length) {
			result=Math.max(result,bfs());
			return;
		}
		
		for(int i=idx;i<list.size();i++) {
			map[list.get(i).r][list.get(i).c]=1;
			comb(i+1,cnt+1,arr);
			map[list.get(i).r][list.get(i).c]=0;
		}
	}

	private static int bfs() {
		// TODO Auto-generated method stub
		Queue<node> copy=new LinkedList<>(virus);
		int[][] cmap=new int[R][C];
		for(int i=0;i<R;i++)
			System.arraycopy(map[i], 0, cmap[i], 0, map[i].length);
		
		int dx[]= {1,-1,0,0};
		int dy[]= {0,0,1,-1};
		while(!copy.isEmpty()) {
			node tmp=copy.poll();
			for(int k=0;k<4;k++) {
				int nr=tmp.r+dx[k];
				int nc=tmp.c+dy[k];
				if(nr>=0&&nr<R&&nc>=0&&nc<C&&cmap[nr][nc]==0) {
					cmap[nr][nc]=1;
					copy.add(new node(nr,nc));
				}
			}
		}
		int cnt=0;
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				if(cmap[r][c]==0) cnt++;
			}
		}
		return cnt;
	}

}
