package programming2020_08_31;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class 인구이동 {

	static int N;
	static int L;
	static int R;
	static int[][] nation;
	static boolean visited[][];
	static List<node> list;

	static class node {
		int r;
		int c;

		public node(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		nation = new int[N][N];
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < N; c++) {
				nation[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		list = new ArrayList<>();
		visited = new boolean[N][N];
		int answer = 0;
		while (true) {
			initVisit();
			moveMan = false;
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (!visited[r][c]) {
						cnt = 1;
						list.clear();
						visited[r][c] = true;
						int sumMan = 0;
						list.add(new node(r, c));
						sumMan += findShare(r, c);
						if (cnt > 1) {
							int result = sumMan / cnt;
							input(result);
						}
					}
				}
			}
			if (!moveMan)
				break;
			else {
				answer++;
			}
		}
		System.out.println(answer);
	}

	private static void print() {
		// TODO Auto-generated method stub
		for (int r = 0; r < N; r++) {
			System.out.println(Arrays.toString(nation[r]));
		}
		System.out.println("-------------print-------------");
	}

	private static void input(int update) {
		// TODO Auto-generated method stub
		for (node n : list) {
			nation[n.r][n.c] = update;
		}
	}

	static boolean moveMan;
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };
	static int cnt;

	private static int findShare(int r, int c) {
		// TODO Auto-generated method stub
		int sumMan = nation[r][c];
		for (int k = 0; k < 4; k++) {
			int nr = r + dx[k];
			int nc = c + dy[k];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
				continue;
			int diff = Math.abs(nation[nr][nc] - nation[r][c]);
			if (diff >= L && diff <= R) {
				cnt += 1;
				visited[nr][nc] = true;
				moveMan = true;
				list.add(new node(nr, nc));
				sumMan += findShare(nr, nc);
			}
		}
		return sumMan;
	}

	private static void initVisit() {
		// TODO Auto-generated method stub
		for (int r = 0; r < N; r++) {
			Arrays.fill(visited[r], false);
		}
	}

}
