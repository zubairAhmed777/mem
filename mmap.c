#include<unistd.h>
#include<stdio.h>
#include <sys/mman.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<strings.h>


int main(void)
{
int ret=-1;
int *s=NULL;
void *p=mmap(NULL,4096*3,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
if(p<=0)
{
	printf("Mmap error\n");
	return -1;
}
bzero(p,1024);
printf("pid=%d,Addrs is %p\n",getpid(),p);
s=p;
*s=4;
printf("%d\n",*s);
ret=mprotect(p,4096,PROT_EXEC);
if(ret<0)
{
printf("mprotect exc Error\n");return -1;
}
ret=mprotect(p+4096,4096,PROT_WRITE);
if(ret<0)
{
printf("mprotect write Error\n");return -1;
}
ret=mprotect(p+(4096*2),4096,PROT_READ);
if(ret<0)
{
printf("mprotect Error\n");return -1;
}

getchar();
ret=munmap(p,4096*3);
if(ret<0)
{
	printf("munmap failed..\n");
	return -1;
}
return 0;
}
