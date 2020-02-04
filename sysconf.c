#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*sysconf - get configuration information at run time*/

/* OPEN_MAX - _SC_OPEN_MAX (The maximum number of files that a process can have open at any time.)*/

/* clock ticks - _SC_CLK_TCK (The  number  of  clock ticks per second. )*/

/*PAGESIZE - _SC_PAGESIZE( Size of a page in bytes.)*/
int main(void)
{
long l=sysconf(_SC_CLK_TCK);
printf("page_size=%ld\n",l);
return 0;
}
