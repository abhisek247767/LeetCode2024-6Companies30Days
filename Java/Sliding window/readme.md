
# Sliding Window Algorithm in Java

## 🧠 Problem Statement

Given an array of integers and an integer `k`, the task is to find the **maximum sum** of any contiguous subarray of size `k`.

This problem demonstrates the use of the **Sliding Window Algorithm**, a powerful technique for solving problems involving linear data structures like arrays or strings.

---

## 🧪 Example

**Input:**
```java
arr = [1, 4, 2, 10, 23, 3, 1, 0, 20]
k = 4
````

**Output:**

```
Maximum sum of a subarray of size 4 is: 39
```

**Explanation:**
The subarray `[10, 23, 3, 1]` gives the maximum sum of `39`.

---

## 🧮 Time & Space Complexity

* **Time Complexity:** `O(n)` – Each element is visited only once.
* **Space Complexity:** `O(1)` – No extra space is used apart from a few variables.

---

## 📋 Approach

1. Calculate the sum of the first window of size `k`.
2. Slide the window one element at a time:

   * Subtract the element going out of the window.
   * Add the new element coming into the window.
3. Update the maximum sum after each slide.

This avoids recalculating the sum from scratch for each subarray, making the solution efficient.

---

## 📂 Files

* `SlidingWindowMaxSum.java` — Java implementation of the algorithm with comments and a main method for demonstration.

---

## 🧑‍💻 How to Run

 Compile and run the Java file:

   ```bash
   javac SlidingWindowMaxSum.java
   java SlidingWindowMaxSum
   ```

---

