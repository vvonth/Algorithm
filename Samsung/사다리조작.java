package programming2020_08_19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.SynchronousQueue;

public class 사다리조작 {
	public static class node {
		int r;
		int c;

		public node(int r, int c) {
			// TODO Auto-generated constructor stub
			this.r = r;
			this.c = c;
		}
	}

	static int R;
	static int C;
	static int[][] map;
	static int result;
	static List<node> list;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		C = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		map = new int[R][C];
		for (int i = 0; i < S; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			map[r - 1][c] = 1;

		}
		result = Integer.MAX_VALUE;
		boolean flag = false;
		for (int c = 0; c < C; c++) {
			if (!move(c, map)) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			result = 0;
		} else {
			// print();
			// 사다리선 추가
			list = new ArrayList<>();
			addLadder();
			// 1개 추가
			for (int i = 0; i < list.size(); i++) {
				int r = list.get(i).r;
				int c = list.get(i).c;
				flag = false;
				map[r][c] = 1;
				for (int k = 0; k < C; k++) {
					if (!move(k, map)) {
						flag = true;
						break;
					}
				}
				map[r][c] = 0;
				if (!flag) {
					result = 1;
					break;
				}

			}
			// 사다리 2개 추가
			if (flag) {
				for (int i = 0; i < list.size(); i++) {
					int r1 = list.get(i).r;
					int c1 = list.get(i).c;
					map[r1][c1] = 1;
					for (int j = i + 1; j < list.size(); j++) {
						int r2 = list.get(j).r;
						int c2 = list.get(j).c;
						// System.out.println("r2: " + r2 + " c2: " + c2);
						if (check(r2, c2)) {
							flag = false;
							map[r2][c2] = 1;
							for (int k = 0; k < C; k++) {
								if (!move(k, map)) {
									flag = true;
									break;
								}
							}
							map[r2][c2] = 0;
							if (!flag) {
								result = 2;
								break;
							}
						}
					}
					map[r1][c1] = 0;
					if (!flag) {
						break;
					}
				}
			}
			if (flag) {
				//System.out.println("진입");
				for (int i = 0; i < list.size() - 1; i++) {
					int r1 = list.get(i).r;
					int c1 = list.get(i).c;
					map[r1][c1] = 1;
					for (int j = i + 1; j < list.size(); j++) {
						int r2 = list.get(j).r;
						int c2 = list.get(j).c;
						if (check(r2, c2)) {
							map[r2][c2] = 1;
							for (int k = j + 1; k < list.size(); k++) {
								int r3 = list.get(k).r;
								int c3 = list.get(k).c;
								if (check(r3, c3)) {
									flag = false;
									map[r3][c3] = 1;
									for (int m = 0; m < C; m++) {
										if (!move(m, map)) {
											flag = true;
											break;
										}
									}
									map[r3][c3] = 0;
									if (!flag) {
										result = 3;
										break;
									}
								}
							}
							map[r2][c2] = 0;
							if (!flag) {
								break;
							}
						}
					}
					map[r1][c1] = 0;
					if (!flag) {
						break;
					}
				}
			}
		}
		if (result == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(result);
		}
	}

	private static boolean check(int r, int c) {
		// TODO Auto-generated method stub
		if (map[r][c] == 0) {
			if (c + 1 < map[r].length && map[r][c + 1] == 0 && map[r][c - 1] == 0) {
				return true;
			} else if (c == C - 1) {
				if (map[r][c - 1] == 0) {
					return true;
				}
			}
		}
		return false;
	}

	static void addLadder() {
		for (int r = 0; r < R; r++) {
			for (int c = 1; c < C; c++) {
				if (map[r][c] == 0) {
					if (c + 1 < map[r].length && map[r][c + 1] == 0 && map[r][c - 1] == 0) {
						list.add(new node(r, c));
					} else if (c == C - 1) {
						if (map[r][c - 1] == 0) {
							list.add(new node(r, c));
						}
					}
				}
			}
		}
	}

	static boolean move(int cIdx, int[][] ladder) {
		int rIdx = 0;
		int start = cIdx;
		// System.out.println("start: "+start);
		while (rIdx < ladder.length) {
			if (cIdx + 1 < ladder[rIdx].length && ladder[rIdx][cIdx + 1] == 1) {
				cIdx++;
			} else if (ladder[rIdx][cIdx] == 1 && cIdx - 1 >= 0) {
				cIdx--;
			}
			// System.out.println("cIdx: "+cIdx);
			rIdx++;
		}
		if (start == cIdx) {
			return true;
		}
		return false;
	}

	static void print() {
		System.out.println("-----------print----------");
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				System.out.print(map[r][c] + " ");
			}
			System.out.println();
		}
	}
}
