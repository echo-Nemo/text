#include<stdio.h>
#define MAX 1000

int cur = 0;

void Merge(P B[], int n, int left, int mid, int right)//A[]����� �ϲ�
{
	int n1, n2,L[MAX/2],R[MAX/2],i;
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++)
		L[i] = B[i + left];
	L[n1] = 10000;////����L[]�����ĩβ�����ܴ� �����������Ƚ�
	for (i = 0; i < n2; i++)
		R[i] = B[i + mid];
	R[n2] = 10000;//����R[]�����ĩβ�����ܴ� �����������Ƚ�
	int s = 0,j = 0;
	for(int k=left;k<right;k++)//����K��Ϊ�����¹������������A[]
	{//k��left ��ʼ �������ǰ���������û������  �ڵ���ʱ��ֵ��left ��right
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

void Mergesort(P B[], int n, int left,  int right)//��A[]�ָ� ������ ���ϲ�
{
	if (left+1 < right)//�ر�ע���±� left�Ľ���
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