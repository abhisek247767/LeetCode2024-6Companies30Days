public class SelectionSort {  

    // Method to perform selection sort
    public static void selectionSort(int[] arr){  
        for (int i = 0; i < arr.length - 1; i++) {  
            int minIndex = i;  
            // Find the index of the minimum element in the remaining unsorted part
            for (int j = i + 1; j < arr.length; j++){  
                if (arr[j] < arr[minIndex]) {  
                    minIndex = j;  
                }  
            }  
            // Swap the found minimum element with the first element of the unsorted part
            int temp = arr[minIndex];   
            arr[minIndex] = arr[i];  
            arr[i] = temp;  
        }  
    }  
       
    public static void main(String[] args){  
        int[] arr = {9, 14, 3, 2, 43, 11, 58, 22};  
        
        System.out.println("Before Selection Sort");  
        for(int num : arr){  
            System.out.print(num + " ");  
        }  
        System.out.println();  
          
        selectionSort(arr); // Sorting array using selection sort  
         
        System.out.println("After Selection Sort");  
        for(int num : arr){  
            System.out.print(num + " ");  
        }  
    }  
}  
