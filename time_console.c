#include <stdio.h>
#include <pthread.h>
//#include <sys/time.h>

//linux for sleep(seconds) and usleep(Microsecond)
//#include <unistd.h>
 
//windows for Sleep(millisecond)
//#include <windows.h> 

//创建线程函数返回类型
pthread_t thread[1]; 
 
/**
* 线程函数
**/
void *printThread()
{
	int h,min,s;
	char hbit,minbit,sbit;
	
	hbit = 0;
	minbit = 0;
	sbit = 0;
	
	printf("Input hour:\n");
	scanf("%d",&h);
	printf("Input minute:\n");
	scanf("%d",&min);
	printf("Input second:\n");
	scanf("%d",&s);
	for(; h < 24; h++)
	{
		if(hbit==0)
		{
			hbit = 1;
			printf("%2d:",h);
		}
		else
		{
			//退8格
			printf("\b\b\b\b\b\b\b\b%2d:",h); 
		}
		//即时标准输出(不带\n，不刷新不行)
		fflush(stdout);

		for(; min < 60; min++)
		{
			if(minbit==0)
			{
				minbit = 1;
				printf("%2d:",min);
			}
			else
			{
				//退5格:十分二十三秒: 10:23 ,共5个字符
				printf("\b\b\b\b\b%2d:",min); 
			}
			//即时标准输出(不带\n，不刷新不行)
			fflush(stdout);

			for(; s < 60; s++)
			{
				if(sbit==0)
				{
					sbit = 1;
					printf("%2d",s);
				}
				else
				{
					//退2格
					printf("\b\b%2d",s); 
				}
				//即时标准输出(不带\n，不刷新不行)
				fflush(stdout);
				//延时1秒
				sleep(1);
			}
			s %= 60;
		}
		min %= 60;
	}
	h %= 24;
}

int main()
{
	if(pthread_create(&thread[0], NULL, printThread, NULL)!=0)//创建线程
	{
		printf("Failed to create thread\n");
		return -1;
	}
	pthread_join(thread[0],NULL);//调用线程

	return 1;
}
