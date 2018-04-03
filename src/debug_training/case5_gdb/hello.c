#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hello.h"

#define	DEBUG_PRINT	printf

void overwrite( int resp_pattern )
{
	/* 応答パターンの文字列を、喉が痛くて回答出来ない「X」で全て埋める */
	memset( &resp_string[resp_pattern], 'X', (size_t)&resp_string[resp_pattern] );

	return;
}

void choice( int resp_pattern )
{
	unsigned int seed;

	/* ランダムシード値を0初期化 */
	memset( &seed, 0x00, sizeof(seed) );

	/* ランダムシード値に時間を設定 */
	seed = time(NULL);

	/* ランダムシードを与える */
	srand( seed );

	/* 応答パターン(0～2)をランダムに選択 */
	resp_pattern = rand()%3;

	/* 応答パターン0以外の時、喉が痛くて回答不能にする */
	if( resp_pattern != 0 )
	{
		overwrite( resp_pattern );
	}

	return;
}

int main()
{
	/* 初期化 */
	int resp_pattern = 0;

	printf("Hello!!\nHow are you?\n");

	/* 応答パターンを選択 */
	choice( resp_pattern );

	/* 応答パターンを出力 */
	printf("%s", &resp_string[resp_pattern][0] );

    return 0;
}
