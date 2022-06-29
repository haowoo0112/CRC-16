#include <stdio.h>
#include "CRC-16.h"


void CRC_16_cal(struct data *frame, int *CRC_result){
	int lowest_bit;
	int i=0, j=0;
	for(j = 0 ; j < 6 ; j++){
		*CRC_result = *CRC_result ^ frame->whole[j];
	
		for(i = 0 ; i < 8 ; i++){
			lowest_bit = *CRC_result % 2;
			*CRC_result = *CRC_result >> 1;
//			printf("%x %x ", lowest_bit, *CRC_result);
			if(lowest_bit == 1){
				*CRC_result = *CRC_result ^ 0xA001;
			}
//			printf("%x\n", *CRC_result);
		}
	}

	printf("result: %x\n", *CRC_result);
	
	
}

int main(){
	struct data rail;
	printf("請輸入六個數字，中間使用空白區隔）：");
    scanf("%x %x %x %x %x %x", &rail.slave_address, &rail.function, &rail.register_address[0], &rail.register_address[1], &rail.data[0], &rail.data[1]);
	
//	rail.slave_address = 0x01;
//	rail.function = 0x06;
//	rail.register_address[0] = 0x02;
//	rail.register_address[1] = 0xCB;
//	rail.data[0] = 0x00;
//	rail.data[1] = 0x00;
	rail.CRC_result = 0xffff;
	
	rail.whole[0] = rail.slave_address;
	rail.whole[1] = rail.function;
	rail.whole[2] = rail.register_address[0];
	rail.whole[3] = rail.register_address[1];
	rail.whole[4] = rail.data[0];
	rail.whole[5] = rail.data[1];
	rail.whole[6] = rail.CRC_result;

	
	CRC_16_cal(&rail, &rail.CRC_result);
	
} 
