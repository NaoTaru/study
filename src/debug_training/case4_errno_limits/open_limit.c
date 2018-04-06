#include <stdio.h>
#include <stdlib.h>		/* for malloc free */
#include <string.h>		/* for mem/str */
#include <unistd.h>		/* for getcwd */

#include <sys/types.h>	/* for open */
#include <sys/stat.h>	/* for open */
#include <fcntl.h>		/* for open */

#include <errno.h>

#define LOOP_MAX		(1500)

#define WORK_SIZE		(255)
#define SURFIX_SIZE		(10)	/* /testNNNN */
#define DIR_SIZE_MAX	(WORK_SIZE-SURFIX_SIZE)

int main( int argc, char* argv[] )
{
	char of_path[WORK_SIZE];
	char wk_name[SURFIX_SIZE];

	char* cwdpath;
	int   len_cwd;

	int loop;
	int fd[LOOP_MAX];

	/* Get current working directory path name */
	cwdpath = getcwd( NULL, DIR_SIZE_MAX );
	strncpy( of_path, cwdpath, DIR_SIZE_MAX );
	len_cwd = strnlen( cwdpath, DIR_SIZE_MAX );
	free( cwdpath );

	/* open files */
	for( loop = 0 ; loop < LOOP_MAX ; loop++ )
	{
		/* Clear surfix name block */
		memset( &of_path[len_cwd], '\0', SURFIX_SIZE );

		/* create open file path string */
		snprintf( wk_name, SURFIX_SIZE, "/test%04d",loop );
		strncat( of_path, wk_name, SURFIX_SIZE+1 );

		/* open file */
		fd[loop] = open( of_path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO );

		/* check open result */
		if( fd[loop] == -1 )/* see POSIX MAN */
		{
			printf("open error! errno = %d\n", errno );
			return -1;
		}
	}

	/* file close & remove */
	for( loop = 0 ; loop < LOOP_MAX ; loop++ )
	{
		/* close file */
		close( fd[loop] );

		/* remove files */
		system("rm test*");
	}

    return 0;
}
