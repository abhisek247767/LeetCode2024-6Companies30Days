class BinarySearch {  

    // Binary search method
    public static void binarySearch(int arr[], int first, int last, int key) {  
        int mid = (first + last) / 2;  

        while (first <= last) {  
            if (arr[mid] < key) {  
                first = mid + 1;  // Search in the right half
            } else if (arr[mid] == key) {  
                System.out.println("Element is found at index: " + mid);  
                return;  // Element found, exit
            } else {  
                last = mid - 1;  // Search in the left half
            }  
            mid = (first + last) / 2;  
        }  

        System.out.println("Element is not found!");  // Element not present
    }  

    public static void main(String args[]) {  
        int arr[] = {10, 20, 30, 40, 50};  
        int key = 30;  
        int last = arr.length - 1;  
        binarySearch(arr, 0, last, key);     
    }  
}
