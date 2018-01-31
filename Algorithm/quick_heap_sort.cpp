#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arry, int lo, int hi);
void qsort(vector<int> &arry, int lo, int hi);
void qsort_3way(vector<int> &arry, int lo, int hi);
void sink(vector<int> &arry, int k, int N);
void heap_sort(vector<int> &arry);

int main()
{

	vector<int> v ={8,-4,-45,-1,-1,-1,-1,12,-12,-12,-12,-12,12,12};

	qsort(v, 0, v.size()-1);
	//qsort_3way(v, 0, v.size()-1);
	//heap_sort(v);

	for(auto x:v)
		cout<<x<<" ";

	return 0;
}

void qsort(vector<int> &arry, int lo, int hi)
{
	if(lo >= hi)	return;  //递归出口 && 注意是等于

	int j = partition(arry, lo, hi);  //获取j的位置，分区

	qsort(arry, lo, j-1);  //左区分治
	qsort(arry, j+1, hi);  //右区分治
}

int partition(vector<int> &arry, int lo, int hi)
{
	int i=lo, j=hi+1;
	int pivot = arry[lo];

	while(true)
	{
		while( j>lo && arry[--j]>pivot ); //从后面找比pivot小的元素
	
		while( i<hi && arry[++i]<pivot ); //从前面找比pivot大的元素

		if(i >= j)	break; //注意是等于号

		swap(arry[i], arry[j]);
	}

	swap(arry[lo], arry[j]); //确定j的位置

	return j;
}

void qsort_3way(vector<int> &arry, int lo, int hi)
{
	if(lo >= hi) return;

	int lt=lo, i=lo+1, gt=hi;
	int pivot = arry[lo];

	while(i <= gt)
	{
		if(arry[i]<pivot)
			swap(arry[lt++], arry[i++]); //i++, 应为 lt->pivot, 交换后lt++ -> pivot, i++处理新数
		else if(arry[i]>pivot)
			swap(arry[gt--], arry[i]); //注意i不变，因为从后面换过来，不知道大小
		else
			i++;
	}

	qsort_3way(arry,lo,lt-1);
	qsort_3way(arry,gt+1,hi);
}

void heap_sort(vector<int> &arry)
{
	int N = arry.size()-1; //N为最后一个下标 [0..N]上操作

	for(int k = N/2; k >=0; k--)
		sink(arry,k,N);

	while(N > 0)
	{
		swap(arry[N--], arry[0]);
		sink(arry,0,N);
	}

}

void sink(vector<int> &arry, int k, int N)
{
	while( 2*k+1 <= N)  // 数组为[0..N]
	{
		int j = 2*k+1;
		if(j<N && arry[j]<arry[j+1])  j++;
		
		if(arry[k]>=arry[j])  break;

		swap(arry[k], arry[j]);

		k = j; //继续下沉
	}

}
