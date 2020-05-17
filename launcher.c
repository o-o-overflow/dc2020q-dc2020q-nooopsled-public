#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define str(x) #x
 
int main()
{
	puts("Mapping memory...\n");
  	void *mem = mmap(0, 0x4000, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANON, 0, 0);
	printf("Reading file into %p...\n", mem);
  	int read_bytes = read(0, mem, 1024);
  	printf("Loaded %d bytes of shellcode at %p...\n", read_bytes, mem);
	printf("Executing!\n");

  	((void(*)())mem)();
}
