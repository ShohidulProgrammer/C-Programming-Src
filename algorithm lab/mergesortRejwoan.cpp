#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a[100];

void Merge_Sort(int left, int right);
void Merge(int left, int center, int right);

int main()
{
	int n, i;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	for(i = 1; i <=n; i++)
		scanf("%d", &a[i]);

	Merge_Sort(1, n);

	for(i = 1; i < n+1; i++)
		printf("%d ", a[i]);

	return 0;
}


void Merge_Sort(int left, int right)
{
	if(left < right)
	{
		int center = (left+right) / 2;
		Merge_Sort(left, center);
		Merge_Sort(center + 1, right);
		Merge(left, center, right);
	}
}


void Merge(int left, int center, int right)
{
	int n1 = center - left + 1;  // To know the number of element
	int n2 = right - center;
	int L[n1+1], R[n2+1];

	for(int i = 1; i <= n1; i++)
		L[i] = a[left+i-1];

	for(int i = 1; i <= n2; i++)
		R[i] = a[center + i];

	L[n1+1] = 12345;
	R[n2+1] = 12345;

	int i = 1, j = 1;

	for(int k = left; k <= right; k++)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}
