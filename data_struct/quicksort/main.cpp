#include <iostream>					// 编译预处理命令
#include "quick_sort.h"
using namespace std;

#define MAXSIZE 100

int main()
{
	/*int n = 10;
	int arr[12] = {7, 1, 4, 6, 8, 9, 5, 2, 3, 10};*/

	int n;
	cin >> n;
	if (n > MAXSIZE) return 0;

	int arr[MAXSIZE] = { 0 };
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

    QuickSort(arr, n); 
	return 0;						
}