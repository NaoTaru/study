#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	/* O_RDWR */
#include <unistd.h>	/* write close sleep */

#include <led.h>

int led_initialize( void )
{
	int fd_exp;
	int fd_dir;

	ssize_t write_size;

	int ret;

	fd_exp = open( SYS_CLASS_GPIO_EXPORT,  O_WRONLY );

	if( fd_exp < 0 )
	{
		perror("SYS_CLASS_GPIO_EXPORT open failed");
		return RET_NG;
	}

	write_size = write( fd_exp, GPIO_PIN_NUMBER, 3 );
	if( write_size != 3 )
	{
		perror("SYS_CLASS_GPIO_EXPORT write failed");
		return RET_NG;
	}

	ret = close( fd_exp );
	if( ret != 0 )
	{
		perror("SYS_CLASS_GPIO_EXPORT close failed");
		return RET_NG;
	}

	fd_dir = open( GPIO_LED_SYSFS_FILE_DIR,  O_RDWR );
	if( fd_dir < 0 )
	{
		perror("GPIO direction file open failed");
		return RET_NG;
	}

	write_size = write( fd_dir, "out", 3 );
	if( write_size != 3 )
	{
		perror("GPIO direction file write failed");
		return RET_NG;
	}

	ret = close( fd_dir );
	if( ret != 0 )
	{
		perror("GPIO direction file close failed");
		return RET_NG;
	}

	return RET_OK;
}



int led_ctrl( int val )
{
	int fd_val;
	int ret;

	ssize_t write_size;

	char c;

	fd_val = open( GPIO_LED_SYSFS_FILE_VALUE,  O_RDWR );
	if( fd_val < 0 )
	{
		perror("GPIO Value file open failed");
		return RET_NG;
	}

	if( val == LED_OFF )
	{
		c = '0';
	}
	else
	{
		c = '1';
	}

	write_size = write( fd_val, &c, 1 );
	if( write_size != 1 )
	{
		perror("GPIO Value file write failed");
		return RET_NG;
	}

	ret = close( fd_val );
	if( ret != 0 )
	{
		perror("GPIO Value file close failed");
		return RET_NG;
	}

	return RET_OK;
}



int main()
{
	int i;
	int ret;
	int val;

    printf("Hello,World!!\n");

	ret = led_initialize();

	/* Toggle Output Level */
	for( i = 0 ; i < 60 ; i++ )
	{
		usleep(250000);

		if( i % 2 == 0 )
		{
			val = LED_OFF;
		}
		else
		{
			val = LED_ON;
		}

		ret = led_ctrl( val );
		if( ret != RET_OK )
		{
			return RET_NG;
		}
	}

    printf("Finish!\n");

    return RET_OK;
}

