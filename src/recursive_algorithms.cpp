#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n < 0) 
    {
        throw std::invalid_argument("Negative input not allowed for factorial");
    }
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    return n * factorial(n-1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n < 0) 
    {
        throw std::invalid_argument("Negative input not allowed for factorial");
    }
    int result = 1;
    for (int i = 2; i <= n; ++i) 
    {
        result *= i;
    }
    return result;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0) 
    {
        throw std::invalid_argument("Negative input not allowed for fibonacci");
    }
    if (n == 0) 
    {
        return 0;
    }
    if (n == 1) 
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if (n < 0) 
    {
        throw std::invalid_argument("Negative input not allowed for fibonacci");
    }
    if (n == 0) 
    {
        return 0;
    }
    if (n == 1) 
    {
        return 1;
    }
    int prev2 = 0;
    int prev1 = 1;
    int current;
    for (int i = 2; i <= n; ++i) 
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
   if (array.empty()) 
   {
       return -1; 
   }

   int mid = array.size() / 2;
   if (array[mid] == target)
   {
        return mid;
   }
   if (array[mid] < target) 
   {
        std::vector<int> rightHalf(array.begin() + mid + 1, array.end());
        int result = binarySearch(rightHalf, target);
        return (result == -1) ? -1 : mid + 1 + result;
   } 
   else 
   {
        std::vector<int> leftHalf(array.begin(), array.begin() + mid);
        return binarySearch(leftHalf, target);
   }

}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) 
        {
            return mid; 
        }
        else if (array[mid] < target) 
        {
            left = mid + 1; 
        } 
        else 
        {
            right = mid - 1; 
        }
    }

    return -1; 
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    if (array.empty()) 
    {
        return 0; 
    }
    std::vector<int> restOfArray(array.begin() + 1, array.end());
    return array[0] + arraySum(restOfArray);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (const int& element : array) 
    {
        sum += element;
    }
    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    if (array.size() <= 1) 
    {
        return;
    }
    std::swap(array[0], array[array.size() - 1]);
    reverseArray(std::vector<int>(array.begin() + 1, array.end() - 1));
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int left = 0;
    int right = array.size() - 1;
    while (left < right) 
    {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}

