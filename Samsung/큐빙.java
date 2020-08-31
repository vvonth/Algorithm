package programming2020_08_26;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 큐빙 {
	// 0: 윗면, 1: 왼쪽면 , 2: 앞면, 3: 뒷면, 4: 오른쪽면, 5: 아랫면
	static char[][][] cube = { { { 'w', 'w', 'w' }, { 'w', 'w', 'w' }, { 'w', 'w', 'w' } },
			{ { 'g', 'g', 'g' }, { 'g', 'g', 'g' }, { 'g', 'g', 'g' } },
			{ { 'r', 'r', 'r' }, { 'r', 'r', 'r' }, { 'r', 'r', 'r' } },
			{ { 'o', 'o', 'o' }, { 'o', 'o', 'o' }, { 'o', 'o', 'o' } },
			{ { 'b', 'b', 'b' }, { 'b', 'b', 'b' }, { 'b', 'b', 'b' } },
			{ { 'y', 'y', 'y' }, { 'y', 'y', 'y' }, { 'y', 'y', 'y' } } };

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		arr = new char[3][3];
		char[][][] copy = new char[6][3][3];
		for (int r = 0; r < 6; r++) {
			for (int c = 0; c < 3; c++) {
				for (int w = 0; w < 3; w++) {
					copy[r][c][w] = cube[r][c][w];
				}
			}
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int testCase = Integer.parseInt(str);
		for (int tc = 0; tc < testCase; tc++) {
			for (int r = 0; r < 6; r++) {
				for (int c = 0; c < 3; c++) {
					for (int w = 0; w < 3; w++) {
						cube[r][c][w] = copy[r][c][w];
					}
				}
			}
			str = br.readLine();
			int C = Integer.parseInt(str);
			str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			for (int c = 0; c < C; c++) {
				String method = st.nextToken();
				check(method.charAt(0), method.charAt(1));
			}
			for (int r = 0; r < 3; r++) {
				for (int w = 0; w < 3; w++) {
					System.out.print(cube[0][r][w]);
				}
				System.out.println();
			}
		}
	}

	private static void check(char ch, char op) {
		// TODO Auto-generated method stub
		String plane = "ULFBRD";
		if (plane.indexOf(ch) != 5) {
			if (op == '+') {
				rotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
			} else {
				rotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
				rotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
				rotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
			}
		} else {
			if (op == '-') {
				brotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
			} else {
				brotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
				brotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
				brotate(plane.indexOf(ch));
				move(plane.indexOf(ch));
			}
		}
	}

	private static void move(int index) {
		// TODO Auto-generated method stub
		if (index == 0) {
			updownmove(index, 0);
		} else if (index == 5) {
			updownmove(index, 2);
		} else if (index == 1) {
			leftmove(index);
		} else if (index == 2) {
			frontmove(index);
		} else if (index == 3) {
			backmove(index);
		} else {
			rightmove(index);
		}
	}

	static char[][] arr;

	// 윗면일때: (1,2,3,4)->r=0인 애들
	// 왼쪽면일때: (0,2,3,5)->c=0
	// 앞면일때 : (0{r=2},1{c=2},4{c=0},5{r=2})
	// 뒷면일때: (0{r=0},1{c=0},4{c=2},5{r=0})
	// 오른쪽면일때: (0,2,3,5)->c=2;
	// 아랫면일때: (1,2,3,4,)->r=2
	public static void brotate(int index) {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				arr[2 - c][r] = cube[index][r][c];
			}
		}
		for (int r = 0; r < 3; r++) {
			System.arraycopy(arr[r], 0, cube[index][r], 0, arr[r].length);
		}
	}

	public static void rotate(int index) {
		// 해당면 돌리기 오른쪽으로..
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				arr[c][2 - r] = cube[index][r][c];
			}
		}
		for (int r = 0; r < 3; r++) {
			System.arraycopy(arr[r], 0, cube[index][r], 0, arr[r].length);
		}

	}

	private static void backmove(int index) {
		char tmp[] = new char[3];
		for (int c = 0; c < 3; c++) {
			tmp[c] = cube[0][0][2 - c];
		}
		for (int c = 0; c < 3; c++)
			cube[0][0][c] = cube[4][c][2];
		for (int c = 0; c < 3; c++)
			cube[4][c][2] = cube[5][0][c];
		for (int c = 0; c < 3; c++)
			cube[5][0][c] = cube[1][2 - c][0];
		for (int c = 0; c < 3; c++)
			cube[1][c][0] = tmp[c];
	}

	private static void frontmove(int index) {
		char tmp[] = new char[3];
		for (int c = 0; c < 3; c++) {
			tmp[c] = cube[0][2][c];
		}
		for (int c = 0; c < 3; c++)
			cube[0][2][c] = cube[1][2 - c][2];
		for (int c = 0; c < 3; c++)
			cube[1][c][2] = cube[5][2][2 - c];
		for (int c = 0; c < 3; c++)
			cube[5][2][c] = cube[4][c][0];
		for (int c = 0; c < 3; c++)
			cube[4][c][0] = tmp[c];
	}

	private static void rightmove(int index) {
		char tmp[] = new char[3];
		for (int r = 0; r < 3; r++) {
			tmp[r] = cube[0][r][2];
		}

		for (int r = 0; r < 3; r++)
			cube[0][r][2] = cube[2][r][2];
		for (int r = 0; r < 3; r++)
			cube[2][r][2] = cube[5][2 - r][0];
		for (int r = 0; r < 3; r++)
			cube[5][r][0] = cube[3][r][0];
		for (int r = 0; r < 3; r++)
			cube[3][2 - r][0] = tmp[r];
	}

	private static void leftmove(int index) {
		char tmp[] = new char[3];
		for (int r = 0; r < 3; r++) {
			tmp[r] = cube[0][r][0];
		}

		for (int r = 0; r < 3; r++) {
			cube[0][r][0] = cube[3][2 - r][2];
		}
		for (int r = 0; r < 3; r++)
			cube[3][r][2] = cube[5][r][2];
		for (int r = 0; r < 3; r++)
			cube[5][r][2] = cube[2][2 - r][0];
		for (int r = 0; r < 3; r++)
			cube[2][r][0] = tmp[r];
	}

	private static void updownmove(int index, int row) {
		// TODO Auto-generated method stub
		System.arraycopy(cube[1][row], 0, arr[row], 0, 3);
		System.arraycopy(cube[2][row], 0, cube[1][row], 0, 3);
		System.arraycopy(cube[4][row], 0, cube[2][row], 0, 3);
		System.arraycopy(cube[3][row], 0, cube[4][row], 0, 3);
		System.arraycopy(arr[row], 0, cube[3][row], 0, 3);
	}
}
