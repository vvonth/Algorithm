package programming2020_08_15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class 감시 {
	static int R;
	static int C;
	public static class node{
		int idx;
		int r;
		int c;
		public node(int idx, int r, int c) {
			// TODO Auto-generated constructor stub
			this.idx=idx;
			this.r=r;
			this.c=c;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		StringTokenizer st=new StringTokenizer(str);
		R=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		int [][] room=new int[R][C];
		list=new ArrayList<>();
		for(int r=0;r<R;r++) {
			str=br.readLine();
			st=new StringTokenizer(str);
			for(int c=0;c<C;c++) {
				room[r][c]=Integer.parseInt(st.nextToken());
				if(room[r][c]>0&&room[r][c]<6) {
					list.add(new node(room[r][c],r,c));
				}
			}
		}
		//6은 벽@@, 1~5는 CCTV
		int size=list.size();
		result=Integer.MAX_VALUE;
		perm(0,new int[size],room);
		if(result==Integer.MAX_VALUE)
			result=0;
		System.out.println(result);
	}
	
	static List<node> list;
	static int dir[][]= {{1,0},{0,1},{-1,0},{0,-1}};
	static int result;
	private static void perm(int idx, int[] tmp,int[][]room) {
		// TODO Auto-generated method stub
		if(idx==tmp.length) {
			int tmpIdx=0;
			int[][] copy=new int[R][C];
			for(int r=0;r<R;r++) {
				System.arraycopy(room[r], 0, copy[r], 0, room[r].length);
			}
			for(node n : list) {
				copy=watch(n,tmp[tmpIdx++],copy);
			}
			//print(copy);
			int cnt=0;
			for(int r=0;r<R;r++) {
				for(int c=0;c<C;c++) {
					if(copy[r][c]==0)
						cnt++;
				}
			}
			
			result=Math.min(result, cnt);
			return;
		}
		for(int i=0;i<4;i++) {
			tmp[idx]=i;
			perm(idx+1,tmp,room);
		}
	}
	private static int[][] work(int nr, int nc,int idx, int [][] room){
		//true로 하고 안에서 조건주는것이 편하다..
		while(true) {
			nr+=dir[idx%4][0];
			nc+=dir[idx%4][1];
			if(nr<0||nr>=R||nc<0||nc>=C||room[nr][nc]==6)
				break;
			if(room[nr][nc]>0&&room[nr][nc]<6)
				continue;
			if(room[nr][nc]==0||room[nr][nc]==7)
				room[nr][nc]=7;
			
		}
		return room;
	}
	
	private static int[][] watch(node n, int idx,int[][] room) {
		// TODO Auto-generated method stub
		int nr=n.r;
		int nc=n.c;
		if(n.idx==1) {
			room=work(nr,nc,idx,room);
		}else if(n.idx==2) {
			room=work(nr,nc,idx,room);
			room=work(nr,nc,idx+2,room);
		}else if(n.idx==3) {
			room=work(nr,nc,idx,room);
			room=work(nr,nc,idx+1,room);
		}else if(n.idx==4){
			for(int i=0;i<3;i++) {
				room=work(nr,nc,idx+i,room);
			}
		}else {
			for(int i=0;i<4;i++) {
				room=work(nr,nc,idx+i,room);
			}
		}
		return room;
	}
	private static void print(int[][] room) {
		System.out.println("------------print----------");
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				System.out.print(room[r][c]+" ");
			}
			System.out.println();
		}
	}
}
