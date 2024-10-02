//using Binary search
int searchInsert(vector<int>&arr,int target){
	int low =0,high = arr.size()-1;
	
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]>target)
			high = mid-1;
		else if(arr[mid]<target)
			low = mid+1;
		else
			return mid;
	}
	return high+1;
}