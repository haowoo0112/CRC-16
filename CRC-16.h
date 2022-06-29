struct data{
	int slave_address;
	int function;
	int register_address[2];
	int data[2];
	int CRC_result ;
	int whole[7];
};


void CRC_16_cal(struct data*, int*);



