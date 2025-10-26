public class LinearSearchExample {    

    // Method to perform linear search
    public static int linearSearch(int[] arr, int key) {    
        for (int i = 0; i < arr.length; i++) {    
            if (arr[i] == key) {    
                return i; // Return the index if key is found
            }    
        }    
        return -1; // Return -1 if key is not found
    }    

    public static void main(String[] args) {    
        int[] arr = {10, 20, 30, 50, 70, 90};    
        int key = 50;    

        int result = linearSearch(arr, key);
        if (result != -1) {
            System.out.println(key + " is found at index: " + result);
        } else {
            System.out.println(key + " is not found in the array.");
        }
    }    
}
