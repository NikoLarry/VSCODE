#include <stack>
using namespace std;


template<class ElemType>
void Print(ElemType elem[], int n)
// 操作结果: 显示数组elem的各数据元素值
{
	for (int i = 0; i < n; i++)
	{	// 显示数组elem
		std::cout << elem[i] << " ";
	}
	std::cout << std::endl;
}


template <class ElemType>
int Partition(ElemType elem[], int low, int high)
// 操作结果:交换elem[low .. high]中的元素,使枢轴移动到适当置,要求在枢轴之前的元素
//	不大于枢轴,在枢轴之后的元素不小于枢轴的,并返回枢轴的位置
{
//-----------------------begin----------------------
while (low<high)
{
	while(low<high && elem[low]<=elem[high])
	{
		high--;
	}
	ElemType temp = elem[low];
	elem[low] = elem[high];
	elem[high] = temp;
	while(low<high && elem[low]<=elem[high])
	{
		low++;
	}
	temp = elem[low];
	elem[low] = elem[high];
	elem[high] = temp;
}
return low;






//-----------------------end-----------------------
}


template <class ElemType>
void QuickSort_Nonrec_help(ElemType elem[], int low, int high)
// 操作结果:对数组elem进行快速排序
{
//-----------------------begin----------------------
	stack<int> T;
	T.push(low);
	T.push(high);
	while(!T.empty())
	{
		int right = T.top();
		T.pop();
		int left = T.top();
		T.pop();
		int pivot = Partition(elem,left,right);
		if(left<pivot-1)
		{
			T.push(left);
			T.push(pivot-1);
		}
		if(right>pivot+1)
		{
			T.push(pivot+1);
			T.push(right);
		}
	}

//-----------------------end-----------------------
}






/// <summary>
/// 对序列按照关键字从小到大进行排序（非递归方式实现）
/// </summary>
/// <param name="elem">待排序序列</param>
/// <param name="n">序列中元素个数</param>
template <class ElemType>
void QuickSort_Nonrec(ElemType elem[], int n)
// 操作结果:对数组elem进行快速排序
{
//-----------------------begin----------------------

	QuickSort_Nonrec_help(elem,0,n-1);
	Print(elem,n);

//-----------------------end-----------------------
}