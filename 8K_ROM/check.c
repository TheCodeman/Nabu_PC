//    -*- tab-width:	4; -*-
#include <stdio.h>
#include <stdint.h>

int main(void) {
	FILE *fp = fopen("nabu-8k.bin"," rb+");
	if (fp != NULL) {
		uint16_t check = 0;
		uint8_t c;
		printf("starting\n\r");
		for (uint16_t index = 0; index < 8190; index++) {
			fread(&c, 1, 1, fp);
			check += c;
		}
		printf("value %04X\n\r", check);
		c = check & 0x00ff;
		fwrite(&c, 1, 1, fp);
		c= check >> 8;
		fwrite(&c, 1, 1, fp);
		fclose(fp);
	}
}
