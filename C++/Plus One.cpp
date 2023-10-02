//using array + math
vector<int>plusOne(vector<int>&digits){
	int n = digits.size();
	bool carry = true;
	for(int i=n-1;i>=0;i--){
		if(digits[i]!=9){
			digits[i]++;
			
			carry = false;
			break;
		}
		else
			digits[i] =0;
		}
		
		if(carry){
			digits.push_back(0);
			
			for(int i = n;i>=0;i--){
				digits[i] = digits[i-1]; //shifting all digits to right
			}
			digits[0] =1;
		}
		return digits;
}