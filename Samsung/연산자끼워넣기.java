package programming2020_08_10;

import java.util.Arrays;
import java.util.Scanner;

public class ¿¬»êÀÚ³¢¿ö³Ö±â {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		A = new int[N];
		for (int i = 0; i < N; i++)
			A[i] = sc.nextInt();
		int op[] = new int[4];
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			op[i] = sc.nextInt();
			cnt += op[i];
		}
		// 0: µ¡¼À, 1: »¬¼À, 2: °ö¼À, 3: ³ª´°¼À
		int operation[] = new int[cnt];
		int opCnt = 0;
		for (int i = 0; i < 4; i++) {
			if (op[i] > 0) {
				op[i]--;
				operation[opCnt++] = i;
				i--;
				continue;
			}
		}
		chk = new boolean[operation.length];
		minResult = Integer.MAX_VALUE;
		maxResult = Integer.MIN_VALUE;
		perm(0, A[0],1, operation);
		System.out.println(maxResult);
		System.out.println(minResult);
	}

	static int A[];
	static boolean chk[];
	static int maxResult;
	static int minResult;

	private static void perm(int idx,int sum,int cnt,int[] operation) {
		// TODO Auto-generated method stub
		if (idx == operation.length) {
			//System.out.println(Arrays.toString(tmp));
			//System.out.println(value);
			minResult = Math.min(sum, minResult);
			maxResult = Math.max(sum, maxResult);
			return;
		}
		for (int i = 0; i < operation.length; i++) {
			if (!chk[i]) {
				chk[i] = true;
				if(operation[i]==0) {
					perm(idx + 1,sum+A[cnt],cnt+1, operation);
				}else if(operation[i]==1) {
					perm(idx+1,sum-A[cnt],cnt+1,operation);
				}else if(operation[i]==2) {
					perm(idx+1,sum*A[cnt],cnt+1,operation);
				}else {
					if(sum<0)
					{
						perm(idx+1,-(Math.abs(sum)/A[cnt]),cnt+1,operation);
					}else {
						perm(idx+1,sum/A[cnt],cnt+1,operation);
					}
				}	
				chk[i] = false;
			}
		}
	}

}
