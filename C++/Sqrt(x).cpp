//using math + binary search
int mysqrt(int x){
	int low =0,high = x;
	while(low<high){
		long long mid = low +((long long)high -low+1)/2;
		if(mid*mid<=(long long)x)
		low = mid;
		else
		high = mid-1;
	}
	return low;
}