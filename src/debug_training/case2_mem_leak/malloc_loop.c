/******************************************************************************/
/* メモリリークプログラム
/*
/* 50%の確率で、メモリリークを発生させます。
/*
/* L.28のmemsetの有無によって、リークの仕方が変わる事も確認して見て下さい。
/*
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>	/* for malloc free*/
#include <string.h>	/* for memset */
#include <unistd.h>	/* for usleep */

#define LOOP_MAX		(1000000)
#define MALLOC_SIZE		(4096*1024)
#define SLEEP_uS_TIME	(500*1000)

int main()
{
	void* pBuff;
	int loop;

	for( loop = 0 ; loop < LOOP_MAX ; loop++ )
	{
		pBuff = malloc(MALLOC_SIZE);

		/* 物理メモリは使用して初めて消費される */
//		memset( pBuff, 0x00, MALLOC_SIZE );

		usleep(SLEEP_uS_TIME);

		if( loop % 2 )
		{
			free(pBuff);
		}
		else
		{
			/* Memory Leak */
		}
	}

    return 0;
}
