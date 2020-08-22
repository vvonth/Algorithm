package programming2020_08_22;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 드래곤커브 {
	static class node {
		int x;
		int y;

		public node(int x, int y) {
			// TODO Auto-generated constructor stub
			this.x = x;
			this.y = y;
		}
	}

	static int map[][];
	static int direct[][] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		map = new int[101][101];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int N = Integer.parseInt(str);
		for (int i = 0; i < N; i++) {
			str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());// 시작 방향
			int g = Integer.parseInt(st.nextToken());
			node start = new node(x, y);// 0세대
			List<node> target=draw(new node(x,y),dir,g);
			for(int j=0;j<target.size();j++) {
				//System.out.println(target.get(j).x+" "+target.get(j).y);
				int kx=target.get(j).x;
				int ky=target.get(j).y;
				if(kx>=0&&kx<=100&&ky>=0&&ky<=100) {
					map[ky][kx]=1;
				}
			}
		}
		System.out.println(find());
	}

	public static int find() {
		int cnt=0;
		for(int r=1;r<map.length;r++) {
			for(int c=1;c<map[r].length;c++) {
				if(map[r-1][c-1]==1&&map[r-1][c]==1&&map[r][c-1]==1&&map[r][c]==1) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	
	public static List<node> draw(node n, int dir, int gLimit) {
		int g = 1;
		int startX = n.x;
		int startY = n.y;
		int endX = n.x + direct[dir][0];
		int endY = n.y + direct[dir][1];// 끝점...기준으로 시계방향 회전..
		List<node> list = new ArrayList<node>();
		list.add(n);
		list.add(new node(endX, endY));
		for (int i = 0; i < gLimit; i++) {
			node last=rotate(list.get(list.size()-1),list.get(list.size()-2));//90도 회전한 좌표
			int lastX=last.x;
			int lastY=last.y;
			int size=list.size()-2;
			list.add(new node(lastX,lastY));
			for(int j=size;j>0;j--) {
				node newNode=rotate(list.get(j),list.get(j-1));//90도 회전한 좌표
				//새로운 값
				int ex=list.get(j).x;
				int ey=list.get(j).y;
				int diffx=lastX-ex;
				int diffy=lastY-ey;
				newNode.x+=diffx;
				newNode.y+=diffy;
				lastX=newNode.x;
				lastY=newNode.y;
				list.add(new node(lastX,lastY));
			}
		}
		return list;
	}

	public static node rotate(node end, node start) {
		int ex=end.x;
		int ey=end.y;
		int sx=start.x;
		int sy=start.y;
		int nx=0;
		int ny=0;
		if(ex>sx) {
			nx=ex;
			ny=ey-1;
		}else if(sx>ex) {
			nx=ex;
			ny=ey+1;
		}else if(sy>ey) {
			nx=ex-1;
			ny=ey;
		}else {
			nx=ex+1;
			ny=ey;
		}
		return new node(nx,ny);
	}

}
