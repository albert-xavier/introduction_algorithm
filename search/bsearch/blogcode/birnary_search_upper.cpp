#include <cstdio>

template<typename T, typename V>
int birnary_search_upper(T array[], const int& array_len, const V& value)
{
    int high = array_len;   //有效搜索空间为[0, high)
    int mid = -1;
    int low = 0;
    int upper_pos = -1;	//记录已经找到的上界

    while(low < high)   //搜索空间[low, high)
    {
        mid = low + ((high-low)>>1);
        if (value < array[mid])
        {
			upper_pos = mid;//记录已经找到的上界
            high = mid ;    //搜索空间变为[low, mid)
        }
        else if (array[mid] < value)
        {
            low = mid + 1;  //搜索空间变为[mid+1, high)
        }
        else 
        {
            low = mid + 1;//搜索空间变为[mid+1, high)
        }
    }
    
    return upper_pos;
}

void test_birnary_search_upper()
{		//		0  1  2  3  4   5   6
    int a1[] = {2, 3, 5, 7, 11, 13, 19};
    int a2[] = {2, 2, 2, 2, 2,  2,  2};
    int a3[] = {1, 2, 2, 2, 4,  4,  5};
    
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 7));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 13));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 6));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 7, 20));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1, 6, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a1+1, 6, 2));
    
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a2, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a2, 7, 3));
    
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a3, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a3, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a3, 7, 4));
    fprintf(stdout, "pos = %d\n", birnary_search_upper(a3, 7, 5));
}

int main(int argc, char* argv[])
{
    test_birnary_search_upper();
    return 0;
}