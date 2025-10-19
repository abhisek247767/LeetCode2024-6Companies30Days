"""
Program: Kth Largest and Kth Smallest Element Finder
Author: <your_name>
Description:
  This program finds the Kth smallest and Kth largest elements in an array
  using the heapq (min-heap / max-heap) data structure.
"""

import heapq

def kth_smallest(arr, k):
    """Returns the Kth smallest element using a min-heap."""
    heapq.heapify(arr)
    for _ in range(k - 1):
        heapq.heappop(arr)
    return heapq.heappop(arr)

def kth_largest(arr, k):
    """Returns the Kth largest element using a max-heap."""
    max_heap = [-x for x in arr]
    heapq.heapify(max_heap)
    for _ in range(k - 1):
        heapq.heappop(max_heap)
    return -heapq.heappop(max_heap)

if __name__ == "__main__":
    # Take user input for array
    arr_input = input("Enter elements of the array separated by spaces: ")
    arr = list(map(int, arr_input.split()))

    # Take input for k
    k = int(input("Enter the value of k: "))

    # Validate input
    if k <= 0 or k > len(arr):
        print("Invalid input! k should be between 1 and the length of the array.")
    else:
        # Calculate results
        smallest = kth_smallest(arr.copy(), k)
        largest = kth_largest(arr.copy(), k)

        # Display formatted output
        print(f"\nInput: arr = {arr}, k = {k}")
        print("Output:")
        print(f"Kth smallest: {smallest}")
        print(f"Kth largest: {largest}")
