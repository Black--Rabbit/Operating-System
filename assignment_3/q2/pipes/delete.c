/* delete.c */
/*
 * Author : Siddharth Mohan Misra
 */

/*
 * Has functions to move and delete file.
 */
#include "header.h"

	void delete(char *cwd)
	{
		if(!fork())
			execl("/bin/rm", "rm", "-f", cwd, 0);
		wait(NULL);
	}
	
	void move_file(char *source, char *destination)
	{
		if(!fork())
			execl("/bin/mv", "mv", "-f", source, destination, 0);
		wait(NULL);
	}
