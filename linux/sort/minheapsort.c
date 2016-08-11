/*************************************************************************
	> File Name: minheapsort.c
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 14 Jun 2015 04:20:21 PM CST
 ************************************************************************/

void MinHeapFixup(int a[], int i)
{
	int j, temp;
	temp = a[i];
	j = (i-1) / 2;//parent node
	while(j >= 0)
	{
		if(a[j] <= temp)
			break;

		a[i] = a[j];	//把较大的子节点往下移动，替换它的子节点
		i = j;
		j = (i - 1)/2;
	}
	a[i] = temp;
}

void MinHeapAddNumber(int a[], int n, int nNum)
{
	a[n] = nNum;
	MinHeapFixup(a, n);
}

void MinHeapFixdown(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i + 1;
	while(j < n)
	{
		if(j+1<n && a[j+1] < a[j])
			j++;
		if(a[j] >= temp)
			break;

		a[i] = a[j];
		i = j;
		j = 2*i +1;
	}
	a[i] = temp;
}

void MinheapsortTodescendarray(int a[], int n)
{
	for(int i = n-1; i >= 1; i--)
	{
		Swap(a[i], a[0]);
		MinHeapFixdown(a, 0, i);
	}
}
