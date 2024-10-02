//using math + recursion
double myPow(double x,int n){
	if(n==0 || x==1)
	return 1;
	
	double val = myPow(x,n/2);
	val*=val;
	
	if(n%2==0)
	return val;
	
	else{
		if(n<0)
		return val*(1/x);
		
		return val*x;
	}
}