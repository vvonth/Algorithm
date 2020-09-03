package programming2020_09_03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.concurrent.SynchronousQueue;

public class ³¬½Ã¿Õ {
	static class shark {
		int r;
		int c;
		int speed;
		int dir;
		int size;
		public shark() {};
		public shark(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
		}
	}

	static int R;
	static int C;
	static List<shark> list;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		list = new ArrayList<>();
		for (int i = 0; i < M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			int r = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken())-1;
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			shark sh = new shark(r, c);
			sh.speed = s;
			sh.dir = d;
			if (sh.dir == 2) {
				sh.dir = 4;
			} else if (sh.dir == 4) {
				sh.dir = 2;
			}
			sh.size = z;
			list.add(sh);
		}
		int result=0;
		for (int t = 0; t < C; t++) {
			result+=take(t);
			move();
			List<shark> arr=eat();
			list.clear();
			list.addAll(arr);
//			System.out.println(t+"ÃÊ");
//			print();
		}
		System.out.println(result);
	}

	private static List<shark> eat() {
		// TODO Auto-generated method stub
		shark[][] sea=new shark[R][C];
		List<shark> tmp=new ArrayList<>();
		for(int i=0;i<list.size();i++) {
			int r=list.get(i).r;
			int c=list.get(i).c;
			int size=list.get(i).size;
			int dir=list.get(i).dir;
			int speed=list.get(i).speed;
			if(sea[r][c]==null) {
				shark sh=new shark(r,c);
				sh.size=size;
				sh.dir=dir;
				sh.speed=speed;
				sea[r][c]=sh;
			}else {
				if(sea[r][c].size<size) {
					sea[r][c].size=size;
					sea[r][c].dir=dir;
					sea[r][c].speed=speed;
				}
			}
		}
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				if(sea[r][c]!=null) {
					tmp.add(sea[r][c]);
				}
			}
		}
		return tmp;
	}
	private static void print() {
		int check[][]=new int[R][C];
		for(shark sh: list) {
			check[sh.r][sh.c]=1;
		}
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				System.out.print(check[r][c]+" ");
			}
			System.out.println();
		}
		System.out.println("=========End=========");
	}
	private static void move() {
		// TODO Auto-generated method stub
		for (shark sh : list) {
			int dir = sh.dir;
			int speed = sh.speed;
			int r = sh.r;
			int c = sh.c;
			for (int sp = 0; sp < speed; sp++) {
				if (r + dx[dir] < 0 || r + dx[dir] >= R || c + dy[dir] < 0 || c + dy[dir] >= C) {
					dir = 5 - dir;
				}
				r +=  dx[dir];
				c +=  dy[dir];
				
			}
			sh.r=r;
			sh.c=c;
			sh.dir=dir;
		}
	}

	static int dx[] = { 0, -1, 0, 0, 1 };
	static int dy[] = { 0, 0, -1, 1, 0 };

	// dir: {1, À§} {2,¾Æ·¡},{3, ¿À¸¥ÂÊ},{4,¿ÞÂÊ};
	private static int take(int col) {
		// TODO Auto-generated method stub
		int idx = 0;
		int r = R;
		int size=0;
		boolean eat = false;
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).c == col) {
				if (list.get(i).r < r) {
					r = list.get(i).r;
					idx = i;
					size=list.get(i).size;
					eat = true;
				}
			}
		}
		if (eat)
			list.remove(idx);
		return size;
	}
	
}
