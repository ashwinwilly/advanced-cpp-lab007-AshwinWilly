#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>
int binarySearchHelper(const std::vector<int>& array,
                       int target,
                       int left,
                       int right);

int arraySumHelper(const std::vector<int>& array,
                   int index);

void reverseArrayHelper(std::vector<int>& array,
                        int i,
                        int j);
// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if(n<0){
        throw std::logic_error("No negative numbers");
    }
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if(n<0){
        throw std::logic_error("No negative numbers");
    }
    int sum=1;
    for(int i=2;i<=n;i++){
        sum*=i;
    }
    return sum;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if(n<0){
        throw std::logic_error("No negative numbers");
    }
    if(n==0 or n==1){return n;}
    return fibonacci(n-1)+fibonacci(n-2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if(n<0){
        throw std::logic_error("No negative numbers");
    }
    int sum=0;
    int first_back=1;
    
    for(int i=1;i<=n;i++){
        sum+=first_back;
        first_back=sum-first_back;
    }
    return sum;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    return binarySearchHelper(
        array,
        target,
        0,
        static_cast<int>(array.size()) - 1
    );
}
int binarySearchHelper(const std::vector<int>& array, int target,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=left+ (right-left)/2;
    if(array[mid]==target){
        return mid;
    };
    if(array[mid]<target){
        return binarySearchHelper(array,target,mid+1,right);
    }
    return binarySearchHelper(array, target, left, mid - 1);
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
   return arraySumHelper(array, 0);
}
int arraySumHelper(const std::vector<int>& array, int index) {
    if (index == static_cast<int>(array.size())) {
        return 0;
    }

    return array[index] + arraySumHelper(array, index + 1);
}
// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
   int sum=0;
   for(int num:array){
        sum+=num;
   }
   return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
 reverseArrayHelper(array,0,array.size()-1);
}
void reverseArrayHelper(std::vector<int>& array,int i,int j) {
   if(i>=j){
    return;
   }
   std::swap(array[i],array[j]);
   i++;
   j--;
   return reverseArrayHelper(array,i,j);
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int i=0;
    int j=array.size()-1;
    while(i<j){
        std::swap(array[i],array[j]);
        i++;
        j--;
    }
}
