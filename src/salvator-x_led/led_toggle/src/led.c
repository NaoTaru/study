#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	/* O_RDWR */
#include <unistd.h>	/* write close sleep */

#include <led.h>

int led_ctrl( int val )
{
	int fd;
	char c;

	fd = open( LED4_DEVICE,  O_RDWR );

	if( fd < 0 )
	{
		perror("LED4_DEVICE device file open failed");
		exit(RET_NG);
	}

	if( val == 0 )
	{
		c = '0';
	}
	else
	{
		c = '1';
	}

	write( fd, &c, 1 );

	close( fd );

	return RET_OK;
}

int main()
{
	int i;

    printf("Hello,World!!\n");

	/* Toggle Output Level */
	for( i = 0 ; i < 1/*min*/ * 60/*sec*/ ; i++ )
	{
		sleep(1);

		if( i % 2 == 0 )
		{
			led_ctrl( LED_OFF );
		}
		else
		{
			led_ctrl( LED_ON );
		}
	}

    printf("Finish!\n");

    return RET_OK;
}
