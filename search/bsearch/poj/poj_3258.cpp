/*
 * =====================================================================================
 *
 *       Filename:  poj_3258.cpp
 *
 *    Description:  http://poj.org/problem?id=3258
 *					题目大意：一群奶牛在玩踩房子的游戏，它们需要从河的一边一直踩石子跳到
 *					另一边。邪恶的老农John为了让奶牛们加强锻炼，从N个石头中搬走M个，企图
 *					增加相邻两块石头之间的距离。
 *					现在要求的问题是，搬走M个石头后，相邻石头之间最短距离的最大值是多少。
 *					该问题求的是一个最小值的上界，可以用二分法查找符合条件的最小值的上界。
 *
 *
 *        Version:  1.0
 *        Created:  2013年07月01日 21时20分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  李海鑫 (xavier), xavier.ssdut@gmail.com
 *        Company:  ssdut.dlut.edu.cn
 *
 * =====================================================================================
 */

#include	<cstdio>
#include	<algorithm>

int L, N, M;
int rock_dis[50005];

bool check_if_ok(const int& step)
{
	int counter = 0; //根据当前的步长,统计有多少块石头可以搬走
	int j = 0;	//某奶牛所站的石块

	for( int i = 1; i < N + 1 ; i++ )
	{
		//奶牛从j跳到i的距离<=step，说明这块石头可以搬走
		if (rock_dis[i] - rock_dis[j] <= step)
		{
			counter ++;
		}
		else
		{
			j = i;//石块不能搬走，奶牛要跳到i上去
		}
	}

	//这里需要注意，最后一跳是跳上岸，也就是说这块
	//“石头”是不能搬走的。考虑现在奶牛在j石块上，往
	//岸上跳，如果L-rock_dis[j]<step的话，说明本次
	//跳跃最短的步长就是L-rock_dis[j]，也就是说，哪怕
	//j石头之前所有的石头都被搬走，也是可以的。出现这种
	//情况，就直接判断该步长是合适的就可以了。
	if(L-rock_dis[j] < step)
		return true;
	return counter > M;
}

int main(int argc, char *argv[])
{
	scanf("%d %d %d", &L,&N,&M);
	rock_dis[0] = 0;

	for( int i = 1; i < N+1 ; i++ )
	{
		scanf("%d", &rock_dis[i]);
	}

	rock_dis[N+1] = L;
	std::sort(rock_dis, rock_dis+N+1);	

	//low必须是min(delta rock_dis)
	int low = L;
	for( int i = 1; i < N+2 ; i++ )
	{
		low = std::min(low, rock_dis[i] - rock_dis[i-1]);
	}
	
	int high = L+1;//N和M都有可能为0
	int mid = -1;
	int max_min_step = L;

	while(low < high)	//搜索空间为[low,high)
	{
		mid = low + ((high-low)>>1);
		if(check_if_ok(mid))
		{
			max_min_step = mid;//当前这个步长合适
			//去[low, mid)空间中看看是否有更小并且也合适的步长
			high = mid;
		}
		else
		{
			//步长太小
			//去[mid+1, high)空间中查看是否有合适的步长
			low = mid + 1;
		}
	}
	printf("%d\n", max_min_step);
	return 0;
}
