//using bits manipulation
uint32_t reverseBits(uint32_t n){
	uint32_t x=0;
	int d =0;
	while(n>0){
		x += (n%2) <<(31-d);
		n>>=1;
		d++;
	}
	return x;
}