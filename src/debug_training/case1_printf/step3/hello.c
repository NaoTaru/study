#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hello.h"

void choice( int resp_pattern )
{
	/* ランダムシードを与える */
	srand( (unsigned)time(NULL) );

	/* 応答パターン(0～2)をランダムに選択 */
	resp_pattern = rand()%3;
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
