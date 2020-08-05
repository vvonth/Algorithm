package programming2020_08_05;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class 뱀 {
	// 뱀의 머리가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝남...
	public static class node {
		int r;
		int c;

		public node(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
		}
	}

	public static class snake {
		int size;
		LinkedList<node> arr = new LinkedList<>();

		public snake() {
			// TODO Auto-generated constructor stub
			this.size = 1;
			arr.add(new node(0, 0));
		}
	}

	// 전역
	static int map[][];
	static int time[];
	static char rotate[];
	static int dx[] = { 0, 1, 0, -1 };// 오른쪽, 아래, 왼, 위(오른쪽90도방향)
	static int dy[] = { 1, 0, -1, 0 };
	static int appleCnt;
	static snake sn;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		map = new int[N][N];
		int K = sc.nextInt();
		for (int i = 0; i < K; i++) {
			// 사과의 위치
			int X = sc.nextInt();
			int Y = sc.nextInt();
			map[X-1][Y-1] = 1;
		}
		int L = sc.nextInt();
		time = new int[L];
		rotate = new char[L];
		for (int i = 0; i < L; i++) {
			int t = sc.nextInt();
			String C = sc.next();
			time[i] = t;
			rotate[i] = C.charAt(0);
		}
		int second = 0;
		int k = 0;
		int timeCnt = 0;
		appleCnt=K;
		sn=new snake();
		while (true) {
			second += 1;
			// 뱀은 처음에 오른쪽을 향한다..
			// 방향 계산할것..
			
			if (!move(k)) {
				break;
			}
			if (timeCnt<time.length&&time[timeCnt] == second) {
				if (rotate[timeCnt] == 'D') {
					k=(k+1)%4; //이걸 왜 고쳤지.. 이것때문에 틀렸네
					
					
				} else {
					if (k > 0) {
						k = (k - 1);
					} else {
						k = 3;
					}
				}
				timeCnt += 1;
			}
			//System.out.println("시간: "+second);
			//print();
		}
		System.out.println(second);
	}

	private static boolean move(int k) {
		// TODO Auto-generated method stub
		System.out.println(sn.arr.size());
		int nr = sn.arr.getLast().r + dx[k];
		int nc = sn.arr.getLast().c + dy[k];
		if(nr<0||nr>=map.length||nc<0||nc>=map.length)
			return false;
		
		if (map[nr][nc] == 1) {
			appleCnt--;
			sn.arr.add(new node(nr, nc));
			sn.size++;
			map[nr][nc] = 2;
		} else if (map[nr][nc] == 0) {
			sn.arr.add(new node(nr, nc));
			map[nr][nc]=2;
			map[sn.arr.getFirst().r][sn.arr.getFirst().c] = 0;
			sn.arr.removeFirst();
			
		}else {
			return false;
		}
		return true;
	}
	private static void print() {
		for(int r=0;r<map.length;r++) {
			for(int c=0;c<map.length;c++) {
				System.out.print(map[r][c]+" ");
			}
			System.out.println();
		}
		System.out.println("------------------end-------------");
	}
}
