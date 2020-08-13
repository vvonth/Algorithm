package programming2020_08_13;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Åé´Ï¹ÙÄû {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		gear = new int[4][8];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 4; i++) {
			String str = br.readLine();
			for(int j=0;j<str.length();j++) {
				gear[i][j]=str.charAt(j)-'0';
			}
		}
		String str=br.readLine();
		StringTokenizer st=new StringTokenizer(str);
		int R=Integer.parseInt(st.nextToken());
		for(int i=0;i<R;i++) {
			str=br.readLine();
			st=new StringTokenizer(str);
			int num=Integer.parseInt(st.nextToken())-1;
			int dir=Integer.parseInt(st.nextToken());
			rotate(num,dir);
		}
		int result=0;
		if(gear[0][0]==1)
		{
			result+=1;
		}
		if(gear[1][0]==1) {
			result+=2;
		}
		if(gear[2][0]==1)
			result+=4;
		if(gear[3][0]==1)
			result+=8;
		System.out.println(result);
	}
	
	static int[][]gear;
	
	private static void rotate(int num, int dir) {
		// TODO Auto-generated method stub
		//12½Ã¹æÇâÀÌ 0¹ø ÀÎµ¦½º...
		//0¹ø Åé´Ï¹ÙÄûÀÇ 2¹ø ÀÎµ¦½º ==1¹ø Åé´Ï¹ÙÄûÀÇ 6¹ø ÀÎµ¦½º ¸Â´êÀººÎºÐ ÀÎµ¦½º 2:6
		//dir==1 ½Ã°è¹æÇâ, dir==-1 ¹Ý½Ã°è¹æÇâ
		int indexArr[]=check(num);
		if(dir==1) {
			int start=gear[num][7];
			for(int i=7;i>0;i--) {
				gear[num][i]=gear[num][i-1];
			}
			gear[num][0]=start;
		}else {
			int end=gear[num][0];
			for(int i=1;i<8;i++) {
				gear[num][i-1]=gear[num][i];
			}
			gear[num][7]=end;
		}
		int idx=num-1;
		int direction=-dir;
		while(idx>=indexArr[0]) {
			if(direction==1) {
				int start=gear[idx][7];
				for(int i=7;i>0;i--) {
					gear[idx][i]=gear[idx][i-1];
				}
				gear[idx][0]=start;
			}else {
				int end=gear[idx][0];
				for(int i=1;i<8;i++) {
					gear[idx][i-1]=gear[idx][i];
				}
				gear[idx][7]=end;
			}
			direction=-direction;
			idx--;
		}
		idx=num+1;
		direction=-dir;
		while(idx<=indexArr[1]) {
			if(direction==1) {
				int start=gear[idx][7];
				for(int i=7;i>0;i--) {
					gear[idx][i]=gear[idx][i-1];
				}
				gear[idx][0]=start;
			}else {
				int end=gear[idx][0];
				for(int i=1;i<8;i++) {
					gear[idx][i-1]=gear[idx][i];
				}
				gear[idx][7]=end;
			}
			direction=-direction;
			idx++;
		}
//		for(int i=0;i<4;i++)
//			System.out.println(Arrays.toString(gear[i]));
	}

	private static int[] check(int num) {
		// TODO Auto-generated method stub
		int leftIdx=num-1;
		int rightIdx=num+1;
		int start=num;
		while(leftIdx>=0) {
			if(gear[start][6]==gear[leftIdx][2]) {
				break;
			}
			start--;
			leftIdx--;
		}
		leftIdx++;
		start=num;
		
		while(rightIdx<4) {
			if(gear[start][2]==gear[rightIdx][6]) {
				
				break;
			}
			start++;
			rightIdx++;
		}
		rightIdx--;
		int tmp[]= {leftIdx,rightIdx};
		return tmp;
	}

}
