package programming2020_09_02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class 나무재테크 {
	static int N;
	static int M;
	static int K;
	static int[][] A;
	static int[][] land;
	static PriorityQueue<tree> tmp;
	static Queue<tree> deadTree;

	public static class tree implements Comparable<tree> {
		int r;
		int c;
		int age;

		public tree(int r, int c, int age) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
			this.age = age;
		}

		@Override
		public int compareTo(tree o) {
			// TODO Auto-generated method stub
			return this.age - o.age;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		A = new int[N][N];
		land=new int[N][N];
		for(int r=0;r<N;r++)
			Arrays.fill(land[r], 5);
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < N; c++) {
				A[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		tmp=new PriorityQueue<>();
		PriorityQueue<tree> pq = new PriorityQueue<>();
		for (int i = 0; i < M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			int r = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken())-1;
			int age = Integer.parseInt(st.nextToken());
			pq.add(new tree(r, c, age));
		}
		deadTree = new LinkedList<>();
		for (int k = 1; k <= K; k++) {
			PriorityQueue<tree> newQ= spring(pq);
			pq.clear();
			pq.addAll(newQ);
			summer();
			newQ = fall(pq);
			pq.clear();
			pq.addAll(newQ);
			winter();
		}
		System.out.println(pq.size());
	}

	private static void winter() {
		// TODO Auto-generated method stub
		for(int r=0;r<N;r++)
			for(int c=0;c<N;c++)
				land[r][c]+=A[r][c];
	}

	static int dx[] = { 1, -1, 0, 0,1,-1,1,-1 };
	static int dy[] = { 0, 0, 1, -1,1,1,-1,-1 };

	private static PriorityQueue<tree> fall(PriorityQueue<tree> pq) {
		// TODO Auto-generated method stub
		tmp.clear();
		while (!pq.isEmpty()) {
			tree tr = pq.poll();
			if (tr.age % 5 == 0) {
				for (int k = 0; k < 8; k++) {
					int nr = tr.r + dx[k];
					int nc = tr.c + dy[k];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N)
						continue;
					tmp.add(new tree(nr,nc,1));
				}
			}
			tmp.add(tr);
		}
		return tmp;
	}

	private static void summer() {
		// TODO Auto-generated method stub
		while (!deadTree.isEmpty()) {
			tree tr = deadTree.poll();
			land[tr.r][tr.c] += tr.age / 2;
		}
	}

	private static PriorityQueue<tree> spring(PriorityQueue<tree> pq) {
		// TODO Auto-generated method stub
		int S = pq.size();
		tmp.clear();
		for (int s = 0; s < S; s++) {
			tree tr = pq.poll();
			int r = tr.r;
			int c = tr.c;
			int age = tr.age;
			if (land[r][c] >= age) {
				land[r][c] -= age;
				age += 1;
				tmp.add(new tree(r, c, age));
			} else {
				deadTree.add(new tree(r, c, age));
			}
		}
		return tmp;
	}

}
