#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hello.h"

#define	DEBUG_PRINT	printf

void choice( int resp_pattern )
{
	/* ランダムシードを与える */
	srand( (unsigned)time(NULL) );

	/* 応答パターン(0～2)をランダムに選択 */
	resp_pattern = rand()%3;

//	DEBUG_PRINT("resp_pattern in choice() = %d\n", resp_pattern );
}

int main()
{
	/* 初期化 */
	int resp_pattern = 0;

	printf("Hello!!\nHow are you?\n");

//	DEBUG_PRINT("resp_pattern before choice() = %d\n", resp_pattern );

	/* 応答パターンを選択 */
	choice( resp_pattern );

//	DEBUG_PRINT("resp_pattern after choice() = %d\n", resp_pattern );

	/* 応答パターンを出力 */
	printf("%s", &resp_string[resp_pattern][0] );

    return 0;
}
