# C++ Learning Resources

## Standard Template Library (STL) in C++

**Article:**  
https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/

The Standard Template Library (STL) is a fundamental part of C++ that provides a collection of generic classes and functions to efficiently manage data and implement common algorithms. It includes:

- Containers (`vector`, `list`, `map`, `set`, etc.)
- Iterators
- Standard algorithms (such as `sort`, `find`, `count`)
- Function objects

A solid understanding of the STL is essential for writing efficient, maintainable, and modern C++ code.

---

# Important Sorting Techniques

Sorting algorithms are fundamental in computer science because they improve data organization and optimize search and processing operations. Below are some of the most important sorting algorithms.

## 2.1 Selection Sort

Reference:  
https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/

Selection Sort is a comparison-based algorithm that divides the array into a sorted and an unsorted region. On each iteration, it selects the smallest element from the unsorted portion and places it at the beginning of that region.

- Time Complexity: O(n²)
- Space Complexity: O(1)
- Not stable by default

It is simple to implement but inefficient for large datasets.

---

## 2.2 Bubble Sort

Reference:  
https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/

Bubble Sort repeatedly traverses the array, comparing adjacent elements and swapping them if they are in the wrong order. Each pass places the next largest element in its correct position.

- Time Complexity: O(n²)
- Space Complexity: O(1)
- Stable

Although easy to understand, it is not suitable for large datasets due to its quadratic time complexity.

---

## 2.3 Insertion Sort

Reference:  
https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/

Insertion Sort builds the final sorted array one element at a time. It takes each element and inserts it into its correct position within the already sorted portion of the array.

- Time Complexity: O(n²)
- Space Complexity: O(1)
- Stable

It performs well on small datasets or nearly sorted data.

---

## 2.4 Merge Sort

Reference:  
https://www.geeksforgeeks.org/dsa/merge-sort/

Merge Sort is a divide-and-conquer algorithm that recursively divides the array into halves, sorts each half, and then merges them back together in sorted order.

- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Stable

It guarantees good performance even for large datasets.

---

## 2.5 Quick Sort

Reference:  
https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/

Quick Sort is a divide-and-conquer algorithm that selects a pivot element and partitions the array into two subarrays: elements less than the pivot and elements greater than the pivot. The process is then repeated recursively.

- Average Time Complexity: O(n log n)
- Worst Case: O(n²)
- Space Complexity: O(log n) (recursive stack)
- Not stable by default

Quick Sort is widely used in practice due to its strong average-case performance and efficiency.
