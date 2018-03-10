#include<stdio.h>
#define MAX 1000

int cur = 0;

void Merge(P B[], int n, int left, int mid, int right)//A[]排序后 合并
{
	int n1, n2,L[MAX/2],R[MAX/2],i;
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++)
		L[i] = B[i + left];
	L[n1] = 10000;////假设L[]数组的末尾的数很大 更加用于做比较
	for (i = 0; i < n2; i++)
		R[i] = B[i + mid];
	R[n2] = 10000;//假设R[]数组的末尾的数很大 更加用于做比较
	int s = 0,j = 0;
	for(int k=left;k<right;k++)//定义K是为了重新构造有序的数组A[]
	{//k从left 开始 当数组的前面或后面可能没放数据  在调用时赋值给left 和right
		if (L[s] < R[j])
		{
			B[k] = L[s];
			s++;
		}
		else
		{
			B[k] = R[j];
				j++;
		}
		cur++;
	}
}

void Mergesort(P B[], int n, int left,  int right)//将A[]分割 再排序 并合并
{
	if (left+1 < right)//特别注意下标 left的界限
	{
		int mid = (left + right) / 2;
		Mergesort(B, n, left, mid);
		Mergesort(B, n, mid, right);
		Merge(B, n, left, mid, right);
	}
}

int main()
{
	int n, A[MAX], i;
	printf("please input n\n");
	scanf("%d", &n);
	printf("please input n numbers\n");
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	Mergesort(A, n, 0, n);
	for (i = 0; i < n; i++)
		printf("%5d", A[i]);
	printf("\n");
	printf("%d\n", cur);
	system("pause\n");
	return 0;
}