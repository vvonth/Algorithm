package programming2020_09_02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class 아기상어 {
	static int N;
	static int[][] sea;
	static shark babyShark;
	static List<fish> list;

	static class shark {
		int r;
		int c;
		int size;
		int eatCnt;

		public shark(int r, int c, int size) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
			this.size = size;
			this.eatCnt = 0;
		}
	}

	static class fish {
		int r;
		int c;
		int size;
		int dist;

		public fish(int r, int c, int size) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
			this.size = size;
			this.dist = 0;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		sea = new int[N][N];
		visited = new boolean[N][N];
		dist = new int[N][N];
		list = new ArrayList<>();
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < N; c++) {
				sea[r][c] = Integer.parseInt(st.nextToken());
				if (sea[r][c] == 9) {
					sea[r][c] = 0;
					babyShark = new shark(r, c, 2);
				} else if (sea[r][c] >= 1 && sea[r][c] <= 6) {
					list.add(new fish(r, c, sea[r][c]));
				}
			}
		}
		int time = 0;
		while (true) {
			init();
			visited[babyShark.r][babyShark.c] = true;
			move();
			for (int i = 0; i < list.size(); i++) {
				int fr = list.get(i).r;
				int fc = list.get(i).c;
				list.get(i).dist = dist[fr][fc];
			}
			Collections.sort(list, new Comparator<fish>() {

				@Override
				public int compare(fish o1, fish o2) {
					// TODO Auto-generated method stub
					if (o1.dist == o2.dist) {
						if (o1.r == o2.r) {
							return o1.c - o2.c;
						}
						return o1.r - o2.r;
					}
					return o1.dist - o2.dist;
				}
			});
			int idx = list.size();
			for (int i = 0; i < list.size(); i++) {
				fish fs = list.get(i);
				if (fs.dist != 0 && fs.size < babyShark.size) {
					babyShark.eatCnt += 1;
					babyShark.r = fs.r;
					babyShark.c = fs.c;
					sea[fs.r][fs.c] = 0;
					if (babyShark.eatCnt == babyShark.size) {
						babyShark.size += 1;
						babyShark.eatCnt = 0;

					}
					time += fs.dist;
					idx = i;
					break;
				}
			}
			if (idx < list.size()) {
				list.remove(idx);
			} else {
				break;
			}

		}
		System.out.println(time);
	}

	private static void init() {
		// TODO Auto-generated method stub
		for (int r = 0; r < N; r++) {
			Arrays.fill(visited[r], false);
			Arrays.fill(dist[r], 0);
		}
	}

	static int dx[] = { 0, 0, 1, -1 };
	static int dy[] = { 1, -1, 0, 0 };
	static boolean visited[][];
	static int dist[][];

	private static void move() {
		// TODO Auto-generated method stub
		Queue<shark> q = new LinkedList<>();
		q.add(babyShark);
		while (!q.isEmpty()) {
			shark bs = q.poll();
			for (int k = 0; k < 4; k++) {
				int nr = bs.r + dx[k];
				int nc = bs.c + dy[k];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || sea[nr][nc] > bs.size || visited[nr][nc])
					continue;
				visited[nr][nc] = true;
				dist[nr][nc] = dist[bs.r][bs.c] + 1;
				q.add(new shark(nr, nc, bs.size));
			}
		}
	}

}
