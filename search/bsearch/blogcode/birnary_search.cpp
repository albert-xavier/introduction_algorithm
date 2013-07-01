#include <iostream>

using namespace std;

//正确版本
template<typename T, typename V>
int birnary_search(T array[], const int& array_len, const V& value)
{
    int high = array_len-1;	//有效数据空间是[low,high]
	int low = 0;
	int mid = -1;
	
	while(low <= high)	//while循环中的搜索空间是[low, high]
	{
		mid = low + ((high-low)>>1);//防止溢出
		if(value < array[mid])
		{
			high = mid-1;//搜索空间改为[low, mid-1]
		}
		else if (array[mid] < value)
		{
			low = mid+1; //搜索空间改为[mid+1, high)
		}
		else
		{
			return mid;
		}
	}
	
	return -1;
}

//测试代码
void test_birnary_search()
{
    int array[] = {2, 3, 5, 7, 11, 13, 19};
	
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 7));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 13));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 6));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 2));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 1));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 19));
	fprintf(stdout, "pos = %d\n", birnary_search(array, 7, 20));
}

int main(int argc, char** argv)
{
    test_birnary_search();
    return 0;
}