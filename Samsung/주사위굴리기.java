package programming2020_08_06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 주사위굴리기 {
	//변수
	static int N,M,X,Y,K;
	static int map[][];
	static int cmd[];
	static int dice[];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		StringTokenizer st=new StringTokenizer(str);
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		X=Integer.parseInt(st.nextToken());
		Y=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		map=new int[N][M];
		cmd=new int[K];
		dice=new int[6];
		for(int r=0;r<N;r++) {
			str=br.readLine();
			st=new StringTokenizer(str);
			for(int c=0;c<M;c++) {
				map[r][c]=Integer.parseInt(st.nextToken());
			}
		}
		str=br.readLine();
		st=new StringTokenizer(str);
		if(map[X][Y]==0) {
			map[X][Y]=dice[0];
			
		}else {
			dice[0]=map[X][Y];
			map[X][Y]=0;
		}
		int r=X;
		int c=Y;
		int dx[]= {0,0,0,-1,1};
		int dy[]= {0,1,-1,0,0};
		for(int i=0;i<K;i++) {
			int dir=Integer.parseInt(st.nextToken());
			r+=dx[dir];
			c+=dy[dir];
			if(r<0||r>=N||c<0||c>=M) {
				r-=dx[dir];
				c-=dy[dir];
				continue;
			}
			move(dir);
			if(map[r][c]==0) {
				map[r][c]=dice[0];
				
			}else {
				dice[0]=map[r][c];
				map[r][c]=0;
			}
			//System.out.println(Arrays.toString(dice));
			System.out.println(dice[2]);
		}	
	}
	
	private static void move(int dir) {
		// TODO Auto-generated method stub
		switch (dir) {
		case 1:
			east();
			break;
		case 2:
			west();
			break;
		case 3:
			north();
			break;
		default:
			south();
			break;
		}
	}

	private static void east()
	{
		int tmp=dice[3];
		for(int i=3;i>=1;i--) {
			dice[i]=dice[i-1];
		}
		dice[0]=tmp;
	}
	private static void west() {
		int tmp=dice[0];
		for(int i=0;i<3;i++) {
			dice[i]=dice[i+1];
		}
		dice[3]=tmp;
	}
	private static void north() {
		int tmp=dice[4];
		dice[4]=dice[2];
		dice[2]=dice[5];
		dice[5]=dice[0];
		dice[0]=tmp;
	}
	private static void south() {
		int tmp=dice[0];
		dice[0]=dice[5];
		dice[5]=dice[2];
		dice[2]=dice[4];
		dice[4]=tmp;
	}
}
