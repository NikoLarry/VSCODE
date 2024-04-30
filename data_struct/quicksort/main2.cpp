#include <iostream>					// 编译预处理命令
#include "sort_topk.h"
using namespace std;

#define MAXSIZE 100

int main()
{
	int n = 40;
	int arr[60] = {11, 12, 36, 51, 15, 7, 17, 38, 55, 26, 26, 9, 26, 12, 31, 39, 19, 24, 44, 68, 16, 8, 2, 23, 20, 0, 24, 44, 25, 43, 8, 4, 21, 39, 12, 24, 15, 1, 45, 13};
	int k = 6;

	/*int n, k;
	cin >> n >> k;
	if (n > MAXSIZE) return 0;*/

	/*int arr[MAXSIZE] = { 0 };
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}*/

    Sort_TopK(arr, n, k); 
	return 0;						
}