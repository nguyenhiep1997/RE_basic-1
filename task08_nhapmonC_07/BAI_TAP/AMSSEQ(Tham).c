#include <stdio.h>;
#include <stdlib.h>;
#define max(a,b) ((a)>(b)?(a):(b))
#define sum(i) sum[i + 10020];
int main()
{
	int n, k, sum[20040], a[15000];
	FILE *fi = NULL;
	FILE *fo = NULL;
	fi = fopen("AMSSEQ.inp","r");
	fo = fopen("AMSSEQ.out","w");
	fscanf(fi,"%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d", &a[i]);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		{
			int tmpSum = sum[i - 1];
			for (int j = 1; j <= k; j++)
				tmpSum = max(tmpSum, sum[i - j]);
			sum[i] = a[i] + tmpSum;
		}
	fprintf(fo,"%d",max(sum[n], 0));
	fclose(fi);
	fclose(fo);
}
/*AMSSEQ - Dãy số
Cho 1 dãy số gồm N phần tử (N ≤ 10000), mỗi phần tử có 1 giá trị nằm trong khoảng [-1000, 1000]. Ban đầu, bạn sẽ ở vị trí ô số 0 với tổng điểm là 0. Mỗi nước đi, người chơi có thể di chuyển sang phải tối thiểu là 1 bước và tối đa là K bước (K ≤ 10) . Khi dừng lại ở 1 ô nào đó thì giá trị của ô đó sẽ được cộng vào tổng điểm. Bạn có thể dừng cuộc chơi bất cứ lúc nào. Hãy tìm cách chơi sao cho tổng điểm nhận được là nhiều nhất.

Dữ liệu vào
Dòng đầu tiên chứa 2 số N, K.
Dòng thứ 2 chứa N số của dãy, mỗi số cách nhau 1 dấu cách. Mỗi số nằm trong khoảng [-1000, 1000]
Dữ liệu ra
Số điểm lớn nhất có thể đạt được.
Giới hạn:

N ≤ 10000.
K ≤ 10.
Trong 20% số test có N ≤ 10
Ví dụ
Input:
5 2
-2 3 -6 -4 5

Output:
4

Giải thích:
- Ta có thể đi theo thứ tự 0 -> 2 -> 4 -> 5. Số điểm đạt được là 0 + 3 - 4 + 5 = 4. */
