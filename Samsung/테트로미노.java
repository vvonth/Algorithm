package programming2020_08_06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 테트로미노 {
	static int[][] board;
	static int N, M;
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };
	static int poly1[][] = { { 2, 2, 2 }, { 0, 0, 0 }, { 0, 2, 1 }, { 0, 0, 2 }, { 2, 2, 1 }, { 2, 0, 0 }, { 1, 2, 2 },
			{ 2, 1, 1 }, { 2, 2, 0 }, { 1, 1, 2 }, { 0, 2, 2 }, { 0, 2, 0 }, { 2, 1, 2 }, { 1, 2, 1 }, { 2, 0, 2 } };
	static int poly2[][] = { { 0, 2, 3, 0 }, { 2, 1, 0, 2 }, { 0, 3, 2, 0 }, { 2, 0, 1, 2 } };
	static int result;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		board = new int[N][M];
		for (int r = 0; r < N; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < M; c++) {
				board[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				for (int i = 0; i < 2; i++)
					result = Math.max(result, move(i, r, c));
			}
		}
		System.out.println(result);
	}

	private static int move(int i, int x, int y) {
		// TODO Auto-generated method stub
		int answer = -1;
		boolean flag = true;
		if (i == 0) {
			for (int r = 0; r < poly1.length; r++) {
				int nx = x;
				int ny = y;
				int sum = board[x][y];
				flag = true;
				for (int c = 0; c < poly1[r].length; c++) {
					nx += dx[poly1[r][c]];
					ny += dy[poly1[r][c]];
					if (!check(nx, ny)) {
						flag = false;
						break;
					}
					sum += board[nx][ny];
				}
				if (flag) {
					answer = Math.max(answer, sum);
				}
			}
		}else {
			for (int r = 0; r < poly2.length; r++) {
				int nx = x;
				int ny = y;
				int sum = board[x][y];
				flag = true;
				for (int c = 0; c < poly2[r].length; c++) {
					nx += dx[poly2[r][c]];
					ny += dy[poly2[r][c]];
					if (!check(nx, ny)) {
						flag = false;
						break;
					}
					if(c==2)
						continue;
					sum += board[nx][ny];
				}
				if (flag) {
					answer = Math.max(answer, sum);
				}
			}
		}
		return answer;
	}

	private static boolean check(int nx, int ny) {
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			return false;
		}
		return true;
	}
}
