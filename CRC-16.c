#include <stdio.h>
#include "CRC-16.h"

void CRC_16_cal(struct data *frame, int *slave_address, int *function, int *CRC_result){
	int lowest_bit;
	int i=0;
	printf(".......%d", sizeof(*frame)/sizeof(int));
	printf("slave sddress: %x, function: %x\n", *slave_address, *function);
	
	*CRC_result = *CRC_result ^ *slave_address;
	
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	*CRC_result = *CRC_result ^ *function;
	printf("%x\n", *CRC_result);
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	printf("result: %x\n", *CRC_result);
	*CRC_result = *CRC_result ^ 0x04;
	printf("%x\n", *CRC_result);
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	printf("result: %x\n", *CRC_result);
	
	*CRC_result = *CRC_result ^ 0x01;
	printf("%x\n", *CRC_result);
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	printf("result: %x\n", *CRC_result);
	
	*CRC_result = *CRC_result ^ 0x00;
	printf("%x\n", *CRC_result);
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	printf("result: %x\n", *CRC_result);
	
	*CRC_result = *CRC_result ^ 0x00;
	printf("%x\n", *CRC_result);
	for(i = 0 ; i < 8 ; i++){
		lowest_bit = *CRC_result % 2;
		*CRC_result = *CRC_result >> 1;
		printf("%x %x ", lowest_bit, *CRC_result);
		if(lowest_bit == 1){
			*CRC_result = *CRC_result ^ 0xA001;
		}
		printf("%x\n", *CRC_result);
	}
	printf("result: %x\n", *CRC_result);
	
	
}



int main(){
	struct data rail;
	rail.slave_address = 0x01;
	rail.function = 0x06;
	rail.register_address[0] = 0x04;
	rail.register_address[1] = 0x01;
	rail.data[0] = 0x21;
	rail.data[1] = 0x34;
	rail.CRC_result = 0xffff;
	CRC_16_cal(&rail ,&rail.slave_address, &rail.function, &rail.CRC_result);
	
} 
