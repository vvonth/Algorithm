package programming2020_08_23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class 치킨배달 {
	static int N;
	static int M;
	static int city[][];
	
	public static class node{
		int r;
		int c;
		public node(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r=r;
			this.c=c;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		StringTokenizer st=new StringTokenizer(str);
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		city=new int[N][N];
		house=new ArrayList<>();
		chicken=new ArrayList<>();
		int cnt=0;
		for(int r=0;r<N;r++) {
			str=br.readLine();
			st=new StringTokenizer(str);
			for(int c=0;c<N;c++) {
				city[r][c]=Integer.parseInt(st.nextToken());
				if(city[r][c]==1) {
					house.add(new node(r,c));
				}
				if(city[r][c]==2) {
					cnt++;
					chicken.add(new node(r,c));
				}
			}
		}
		//0:빈칸, 1: 집, 2: 치킨집
		visited=new boolean[N][N];
		q=new LinkedList<>();
		result=Integer.MAX_VALUE;
		select(0,0,cnt-M);
		System.out.println(result);
	}
	static int result;
	private static void select(int row, int cnt,int L) {
		// TODO Auto-generated method stub
		if(cnt==L) {
			//치킨거리구하기
			result=Math.min(result,calc());
			return;
		}
		for(int r=row;r<N;r++) {
			for(int c=0;c<N;c++) {
				if(city[r][c]==2) {
					city[r][c]=0;
					select(r,cnt+1,L);
					city[r][c]=2;
				}
			}
		}
		
	}
	private static int calc() {
		// TODO Auto-generated method stub
		int cnt=0;
		for(node n : house)
			cnt+=bfs(n.r,n.c);		
		return cnt;
	}
	static int dx[]= {1,-1,0,0};
	static int dy[]= {0,0,1,-1};
	static boolean visited[][];
	static Queue<node> q;
	static List<node> house; 
	static List<node> chicken; 
	private static int bfs(int r, int c) {
		// TODO Auto-generated method stub
		int minResult=Integer.MAX_VALUE;
		for(int nr=0;nr<N;nr++) {
			for(int nc=0;nc<N;nc++) {
				if(city[nr][nc]==2) {
					minResult=Math.min(minResult,Math.abs(nr-r)+Math.abs(nc-c));
				}
			}
		}
			
		return minResult;
	}

}
