package programming2020_08_05;

import java.util.Scanner;

public class 시험감독 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0;i<A.length;i++) {
			A[i]=sc.nextInt();
		}
		int B = sc.nextInt();// 총감독관이 응시할수있는 학생수
		int C = sc.nextInt();// 부감독관이 응시할 수 있는 학생수
		int result = A.length;
		for (int i = 0; i < A.length; i++) {
			int num = A[i] - B;
			if (num > 0) {
				if (num % C == 0) {
					result += num / C;
				} else {
					result += num / C + 1;
				}
			}
		}
		System.out.println(result);
	}

}
