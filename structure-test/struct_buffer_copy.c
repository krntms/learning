#include <stdio.h>
#include <string.h>
#include <stdint.h>


#define DATA_SIZ 100

typedef struct pac {
	uint8_t start;
	uint8_t pfm_id;
	uint8_t prot_id1;
	uint8_t prot_id2;
	uint16_t len;
	uint8_t comm;
#if 0
} pac_t;
#else
} __attribute((packed)) pac_t;
#endif

int main(int argc, char **argv)
{
	int i;
	pac_t pack;
	char *buf;

	buf = (uint8_t *) &pack;
	printf("buf: %p\n", buf);
	memset(&pack, 0, sizeof(pac_t));
	printf("size of pack: %lu\n", sizeof(pac_t));
	printf("start: %2x\n", pack.start);
	printf("pfm_id: %2x\n", pack.pfm_id);
	printf("id1: %2x\n", pack.prot_id1);
	printf("id2: %2x\n", pack.prot_id2);
	printf("len: %d\n", pack.len);
	printf("comm: %2x\n", pack.comm);

	printf("buf: ");
	for (i = 0; i < sizeof(pac_t); i++){
		printf("0x%x ", *(buf + i));
	}
	printf("\n");
	
	for (i = 0; i < sizeof(pac_t); i++){
		*(buf + i) = i + 1;
	}
	printf("new buf: ");
	for (i = 0; i < sizeof(pac_t); i++){
		printf("%p: 0x%x\n", (buf + i), *(buf + i));
	}
	printf("\n");
	printf("start: %2x\n", pack.start);
	printf("pfm_id: %2x\n", pack.pfm_id);
	printf("id1: %2x\n", pack.prot_id1);
	printf("id2: %2x\n", pack.prot_id2);
	printf("len: %.4x\n", pack.len);
	printf("comm: %2x\n", pack.comm);

	return 0;
}
