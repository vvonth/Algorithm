package programming2020_08_05;

import java.util.Scanner;

public class ���谨�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0;i<A.length;i++) {
			A[i]=sc.nextInt();
		}
		int B = sc.nextInt();// �Ѱ������� �����Ҽ��ִ� �л���
		int C = sc.nextInt();// �ΰ������� ������ �� �ִ� �л���
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
