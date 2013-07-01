#include <cstdio>

template<typename T, typename V>
int birnary_search_last_pos(T array[], const int& array_len, const V& value)
{
    int last_pos = -1;  //保存最后一次找到value的位置
    int high = array_len;  //有效搜索空间为[0, array_len)
    int mid = -1;
    int low = 0;
    
    while(low < high)   //搜索空间为[low, high)
    {
        mid = low + ((high-low)>>1);
        if (value < array[mid])
        {
            high = mid ;    //搜索空间变为[low,mid)
        }
        else if (array[mid] < value)
        {
            low = mid + 1;  //搜索空间变为[mid+1, high)
        }
        else    
        {
            last_pos = mid; //记录找到的value的pos
            low = last_pos+1; //把搜索空间改为[last_pos+1, high)
        }
    }
    
    return last_pos;
}

void test_birnary_search_last_pos()
{
    int a1[] = {2, 3, 5, 7, 11, 13, 19};
    int a2[] = {2, 2, 2, 2, 2,  2,  2};
    int a3[] = {1, 2, 2, 2, 4,  4,  5};
    
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 7));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 13));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 6));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 7, 20));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1, 6, 19));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a1+1, 6, 2));
    
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a2, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a2, 7, 3));
    
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a3, 7, 2));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a3, 7, 1));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a3, 7, 4));
    fprintf(stdout, "pos = %d\n", birnary_search_last_pos(a3, 7, 5));
}

int main(int argc, char* argv[])
{
    test_birnary_search_last_pos();
    return 0;
}