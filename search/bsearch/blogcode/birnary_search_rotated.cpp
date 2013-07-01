#include <cstdio>

template<typename T, typename V>
int birnary_search_rotated(T array[], const int& array_len, const V& value)
{
    int high = array_len-1;   //有效搜索空间为[0, high]
    int mid = -1;
    int low = 0;

    while(low <= high)   //搜索空间[low, high]
    {
        mid = low + ((high-low)>>1);
    	if(array[low] <= array[mid])	//[low,mid]有序
		{	
			if(array[low] <= value && value <= array[mid])	//value在[low,mid]中
			{
				if (value < array[mid])
				{
					high = mid - 1; //搜索空间变为[low, mid-1]
				}
				else
				{
					return mid;
				}
			}
			else
			{
				low = mid + 1;	//去[mid+1,high]中搜索
			}
		}
		else// if (array[mid] <= array[high])	//[mid, high]有序
		{
			if (array[mid] <= value && value <= array[high])
			{
				if (array[mid] < value)
				{
					low = mid + 1;//搜索空间变为[mid+1,high]
				}
				else
				{
					return mid;
				}
			}
			else
			{
				high = mid - 1;	//去[low, mid-1]中搜索
			}
		}
    }
    
    return -1;
}

void test_birnary_search_rotated()
{		//		0   1  2  3  4  5  6
    int a1[] = {11, 13,19,2, 3, 5, 7};
    int a2[] = {2,  2, 2, 2, 2, 2, 2};
    int a3[] = {1,  2, 2, 2, 4, 4, 5};
    
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 7));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 13));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 6));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 7, 20));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1, 6, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a1+1, 6, 2));
    
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a2, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a2, 7, 3));
    
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a3, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a3, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a3, 7, 4));
    fprintf(stdout, "pos = %d\n", birnary_search_rotated(a3, 7, 5));
}

int main(int argc, char* argv[])
{
    test_birnary_search_rotated();
    return 0;
}