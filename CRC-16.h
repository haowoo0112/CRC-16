struct data{
	int slave_address;
	int function;
	int register_address[2];
	int data[2];
	int CRC_result ;
};

void CRC_16_cal(struct data*, int*, int*, int* );



