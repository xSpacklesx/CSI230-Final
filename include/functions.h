/*
author: Hunter Spack
Class: CSI-280-01
Assignment: PA3 - Part 4
Date Assigned: 9/28/2020
Date Due: 10/12/2020
Description: holds all the functions used in the program
Certification of Authenticity:	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>


int* copyData(int dataSet[], const long long size);

void loadData(std::string dataFile, int array[], long long size);

void callFunction(int sortFunction, int array[], long long size, int runNum, std::string fileName, int setNum);


//pre: takes in an array and a size
//post: doesn't output but you end up with a sorted array
//purpose: to use the bubblesortting algorithm
template <typename T>
void bubbleSort(T list[], int size);


//pre:an array and the size of the array
//post: the array is sorted
//purpose: to use the insertion sort algorithm
template <typename T>
void insertionSort(T list[], int size);


//pre array, index, pivot point, upperbound
//post partially sorted array
//purpose to sort the array
template <typename T>
void merge(T list[], int lowerBound, int mid, int upperBound);

//pre array, index, upperbound
//post sorted array
//purpose to sort the array
template <typename T>
void mergeSort(T list[], int lowerBound, int upperBound);


//pre unsorted list, lower index, last index
//post sorted array
//purpose to sort an array of items
template <typename T>
void quickSort(T list[], int lowerBound, int upperBound);


//pre: an array of anything (more or less) and the size of the array
//post: The array will be sorted
//purpose: To sort an array using the selection sort method
template <typename T>
void selectionSort(T list[], int size);



//pre: an array that needs to be sorted and the size of the array
//post: a sorted array
//purpose: to use the shell sort method
template <typename T>
void shellSort(T list[], int size);



//pre: two items to be swapped
//post: the items will be swapped
//purpose: to swap two of the same thing
template <typename T> 
void swap(T& item1, T& item2);

#endif // !FUNCTIONS_H
