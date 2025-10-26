public class BubbleSort {  

    // Method to perform Bubble Sort
    static void bubbleSort(int[] arr) {  
        int n = arr.length;  
        int temp;  

        // Outer loop for passes
        for (int i = 0; i < n; i++) {  
            // Inner loop for comparisons in each pass
            for (int j = 1; j < (n - i); j++) {  
                if (arr[j - 1] > arr[j]) {  
                    // Swap elements
                    temp = arr[j - 1];  
                    arr[j - 1] = arr[j];  
                    arr[j] = temp;  
                }  
            }  
        }  
    }  

    public static void main(String[] args) {  
        int arr[] = {3, 60, 35, 2, 45, 320, 5};  

        System.out.println("Array Before Bubble Sort:");  
        for (int num : arr) {  
            System.out.print(num + " ");  
        }  
        System.out.println();  

        bubbleSort(arr); // Sorting array elements using Bubble Sort  

        System.out.println("Array After Bubble Sort:");  
        for (int num : arr) {  
            System.out.print(num + " ");  
        }  
    }  
}
