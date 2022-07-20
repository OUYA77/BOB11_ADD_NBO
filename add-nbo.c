#define _CRT_SECURE_NO_WARNINGS

#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <string.h>
#include <arpa/inet.h>

uint32_t buf[4];

uint32_t FRead(char * fileName)
{
	int buf_size=4;
	FILE * temp_file=fopen(fileName,"rb");
	for(int i=0;i<buf_size;i++)
		fread(&buf[i],sizeof(uint32_t),1,temp_file);
		
	uint32_t result = (buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3];
	fclose(temp_file);
	return buf[0];
}

uint32_t my_ntohl(uint32_t n){
	uint32_t n1 = (n & 0xff000000)>>24;
	uint32_t n2 = (n & 0x00ff0000)>>8;
	uint32_t n3 = (n & 0x0000ff00)<<8;
	uint32_t n4 = (n & 0x000000ff)<<24;
	
	return n1 | n2 | n3 | n4;
}	

int main(int argc, char* argv[]) {
    if(argc!=3){
            printf("plz, input 2 arguments\n");
            return -1;
    }
    
    uint32_t a, b,_a,_b;
    a=FRead(argv[1]);
    b=FRead(argv[2]);
    
    _a = my_ntohl(a);
    _b = my_ntohl(b);

    uint32_t result = _a+_b;//n1+n2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",_a,_a,_b,_b,result,result); 
    return 0;
}

