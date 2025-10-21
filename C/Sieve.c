/*
Given an integer n, find all prime numbers less than n using the 
Sieve of Eratosthenes algorithm. Prime numbers are natural numbers 
greater than 1 that are divisible only by 1 and themselves.

Task:
Implement a function findPrimes(n: int) -> List[int] that 
returns a list of all prime numbers less than n.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

int main(){

    // File pointer for saving primes to a file
    FILE *primes;

    // Set a limit for the range of numbers we will check for primality
    unsigned long long limit = 10000000000;

    // Initialize count with total numbers between 2 and the limit
    unsigned long long count = limit - 2;

    // Dynamically allocate memory for an array to mark prime numbers
    bool *arr = calloc(limit, 1);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;  // Exit if memory allocation fails
    }

    // Initialize all numbers from 2 to 'limit' as potentially prime
    for(unsigned long long i = 2; i < limit; i++) arr[i] = true;

    // Use the Sieve of Eratosthenes method to find all primes up to 'limit'
    for(unsigned long long i = 2; i <= sqrt(limit); i++){ 

        if(arr[i] == false) continue;  // Skip if 'i' is already marked as not prime
        
        // Mark all multiples of 'i' as not prime
        for(unsigned long long j = i * i; j < limit; j += i){
            if(arr[j] != false){
                arr[j] = false;  // Marking multiples of 'i' as non-prime
                count--;  // Decrease the count of prime numbers
            }
        }
    }

    // Open a file "Prime.txt" to store all prime numbers found
    primes = fopen("Prime.txt", "w");

    // Write all prime numbers to the file
    for(unsigned long long i = 2; i < limit; i++){
        if(arr[i] == true){
            fprintf(primes, "%d\n", i);  // Writing each prime number to the file
        }
    }
    
    // Output the total number of prime numbers found
    printf("NUMBER = %lld", count);

    // Close the file and free the dynamically allocated memory
    fclose(primes);
    free(arr);
}
