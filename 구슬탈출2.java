package programming2020_08_04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 구슬탈출2 {
	static char[][] map;
	static int R;
	static int C;

	public static class node {
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
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		int blueR = 0;
		int blueC = 0;
		int redR = 0;
		int redC = 0;
		for (int r = 0; r < R; r++) {
			str = br.readLine();
			for (int c = 0; c < C; c++) {
				map[r][c] = str.charAt(c);
				if (map[r][c] == 'B') {
					blueR = r;
					blueC = c;
					map[r][c]='.';
				} else if (map[r][c] == 'R') {
					redR = r;
					redC = c;
					map[r][c]='.';
				}
			}
		}
		game(1, blueR, blueC, redR, redC,-1);
		if(result==11) {
			System.out.println(-1);
		}else {
			System.out.println(result);
		}
	}

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };
	static boolean redAnswer;
	static boolean blueAnswer;
	static int result=11;

	private static void game(int cnt, int blueR, int blueC, int redR, int redC, int last) {
		// TODO Auto-generated method stub
//		int nbr = blueR;
//		int nbc = blueC;
//		int nrr = redR;
//		int nrc = redC;
		if(cnt>10)
			return;
		for (int k = 0; k < 4; k++) {
			if(k==last)
				continue;
			node blue = move(blueR, blueC, k, 0);
			node red = move(redR, redC, k, 1);
			//System.out.println(blue.r+ " "+blue.c+" "+red.r+" "+red.c);
			
			if (redAnswer&&blueAnswer) {
				blueAnswer=false;
				redAnswer=false;
				continue;
			}else if(blueAnswer) {
				blueAnswer=false;
				continue;
			}else if (redAnswer) {
				result = Math.min(cnt, result);
				redAnswer=false;
				continue;
			} else {
				if (k == 0) {
					if (blue.r == red.r&&blue.c==red.c) {
						if (blueR < redR) {
							blue.r--;
						} else {
							red.r--;
						}
					}
				} else if (k == 1) {
					if (blue.r == red.r&&blue.c==red.c) {
						if (blueR < redR) {
							red.r++;
						} else {
							blue.r++;
						}
					}
				} else if (k == 2) {
					if (blue.r == red.r&&blue.c==red.c) {
						if (blueC < redC) {
							blue.c--;
						} else {
							red.c--;
						}
					}
				} else {
					if (blue.r == red.r&&blue.c==red.c) {
						if (blueC < redC) {
							red.c++;
						} else {
							blue.c++;
						}
					}
				}
			}
			game(cnt+1,blue.r,blue.c,red.r,red.c,k);
		}
	}

	private static node move(int nr, int nc, int k, int color) {
		// TODO Auto-generated method stub
		while (true) {
			nr += dx[k];
			nc += dy[k];
		//	System.out.println(nr+" "+nc+" "+color);
			// 구멍에 빠지는지 체크해야함 이따가....
			if(map[nr][nc]=='#') {
				nr-=dx[k];
				nc-=dy[k];
				break;
			}
			if (map[nr][nc] == 'O') {
				if (color == 0) {
					blueAnswer = true;
				} else {
					redAnswer = true;
				}
				break;
			}
			
		}
		return new node(nr, nc);
	}

	public static void print() {
		for (int r = 0; r < R; r++) {
			for(int c=0;c<C;c++) {
				System.out.print(map[r][c]);
			}
			System.out.println();
		}
		System.out.println("--------------------end-------------------");
	}

}
