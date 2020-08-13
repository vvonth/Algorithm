package programming2020_08_10;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
// �ϴ� �����Ҷ��� �������� ������ ȸ������ �ʰ� �״�� ȸ�������� �� ���� ȸ���� ������... ���� �迭 �� ����..
public class �κ�û�ұ� {
	static int R;
	static int C;
	static int room[][];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		room = new int[R][C];
		str = br.readLine();
		st = new StringTokenizer(str);
		int sr = Integer.parseInt(st.nextToken());
		int sc = Integer.parseInt(st.nextToken());
		int sd = Integer.parseInt(st.nextToken());
		for (int r = 0; r < R; r++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int c = 0; c < C; c++) {
				room[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		// ���� : {0,��}, {1,��},{2,��},{3,��}
		// ��ĭ: 0, �� : 1
		clean(sr, sc, sd);
	}
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	private static void clean(int sr, int sc, int sd) {
		int cnt = 0;
		while (true) {
			if (room[sr][sc] == 0) {
				cnt++;
				room[sr][sc] = 2;
				//print();
			}
			if (sd > 0) {
				sd -= 1;
			} else {
				sd = 3;
			}
			// ���ʹ��� Ž��
			//System.out.println("����: "+sd);
			int nr = sr + dx[sd];
			int nc = sc + dy[sd];
			// ����� Ž�� ���ǹ�..û���� ���� �ִٸ� 4������
			if (!c(sr, sc)) {
				//System.out.println("�����Ѵ�");
				sd=(sd+1)%4;
				sr -= dx[sd];
				sc -= dy[sd];
				if (room[sr][sc] == 1) {
					//System.out.println("�����ߴµ� ���̳� Ż��");
					break;
				}
				continue;
			}
			if (a(nr, nc)) {
				sr = nr;
				sc = nc;
			} else {
				continue;
			}
		}
		System.out.println(cnt);
	}
	private static boolean c(int sr, int sc) {
		// TODO Auto-generated method stub
		boolean flag = false;
		for (int k = 0; k < 4; k++) {
			int nr = sr + dx[k];
			int nc = sc + dy[k];
			if (nr >= 0 && nr < R && nc >= 0 && nc < C && room[nr][nc] == 0) {
				flag = true;
			}
		}
		return flag;
	}
	private static boolean a(int nr, int nc) {
		// TODO Auto-generated method stub
		if (room[nr][nc] == 0) {
			return true;
		}
		return false;
	}
	private static void print() {
		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				System.out.print(room[r][c]+" ");
			}
			System.out.println();
		}
		System.out.println("--------------");
	}
}
