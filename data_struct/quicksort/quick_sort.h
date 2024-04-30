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
// 不大于枢轴,在枢轴之后的元素不小于枢轴的,并返回枢轴的位置
{
//---------------------------begin---------------------------
    
    while(low<high)
    {
        while(low<high && elem[high]>=elem[low])
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







//------------------------ ---end------------------------------
}


/// <summary>
/// 对序列按照关键字从小到大进行排序
/// </summary>
/// <param name="elem">待排序序列</param>
/// <param name="n">序列中元素个数</param>

template <class ElemType>
void QuickSortHelp(ElemType elem[], int low, int high)
 {
    if (low < high) {
        int pivot = Partition(elem, low, high); 

        QuickSortHelp(elem, low, pivot - 1); 
        QuickSortHelp(elem, pivot + 1, high);
    }
}

template <class ElemType>
void QuickSort(ElemType elem[], int n)
// 操作结果:对数组elem进行快速排序
{
	//-----------------------begin---------------------
        QuickSortHelp(elem, 0, n - 1);
        Print(elem,n);

    //------------------- ----end----------------------
}
