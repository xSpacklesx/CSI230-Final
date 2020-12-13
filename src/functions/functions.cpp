/*
author: Hunter Spack
Class: CSI-280-01
Assignment: PA3 - Part 4
Date Assigned: 9/28/2020
Date Due: 10/12/2020
Description: generates one million ints and outputs them to files for random, sorted, and reverse sorted
Certification of Authenticity:	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include "functions.h"

//pre:an array to copy and the size of the copied array 
//post: the array is a copy of another array
//purpose: to copy an array 
int* copyData(int dataSet[], const long long size)
{

	int * copySet = NULL;
	copySet = new int[size];
	std::copy(dataSet, dataSet + size, copySet);

	return copySet;
}

//pre:a data file name, an array, the size of the array
//post: the array is filled with data from the file
//purpose: to fill an array with data from a file
void loadData(std::string dataFile, int array[], long long size)
{
	std::fstream iFile;
	iFile.open(dataFile, std::fstream::in);
	std::string data = "";
	for (long long i = 0; i < size; i++)
	{
		std::getline(iFile, data);
		//std::cout << array[i] <<std::endl;
		array[i] = std::stoi(data);
	}
	iFile.close();
}

//pre:an int to determine which sort function, the array to sort, the size of the array that is being sorted, the run through the data. the name of the output file for data, and the number that correspondes to the dataset
//post: the array is sorted and the time it took is output to a file
//purpose: to time different sorting algorithms and out put their times to a file along with the data of which algorithm, run, and dataset were timed
void callFunction(int sortFunction, int array[], long long size, int runNum, std::string fileName, int setNum)
{
	std::fstream oFile;
	oFile.open(fileName, std::ios_base::out);
	
	switch (sortFunction)
	{
	case 0:
		oFile << "Bubble sort: \t Array in size : " << size << "\t\t";
		bubbleSort(array, size);	
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	case 1:
		oFile << "Insertion sort: \t Array in size : " << size << "\t\t";
		insertionSort(array, size);
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	case 2:
		oFile << "Selection sort: \t Array in size : " << size << "\t\t";
		selectionSort(array, size);
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	case 3:
		oFile << "Shell sort: \t Array in size : " << size << "\t\t";
		shellSort(array, size);
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	case 4:
		oFile << "Quick sort: \t Array in size : " << size << "\t\t";
		quickSort(array, 0, size - 1);
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	case 5:
		oFile << "Merge sort: \t Array in size : " << size << "\t\t";
		mergeSort(array, 0, size - 1);
		oFile << std::endl << "Your sorted data:" <<std::endl;
		for (int i = 0; i < size; i++)
		{
			oFile << array[i] <<std::endl;
		}
		break;


	default:
		std::cout << "Bound error in callFunction" << std::endl;
		break;
	}
	oFile.close();
}

//
//
//

template <typename T>
void bubbleSort(T list[], int size)
{
	bool swapped = true;
	int i;
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (list[i + 1] < list[i])
			{
				swap(list[i + 1], list[i]);
				swapped = true;
			}
		}
	}
}



template <typename T>
void insertionSort(T list[], int size)
{
	T value;
	int i, j;
	for (i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > value)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = value;
	}
}




template <typename T>
void merge(T list[], int lowerBound, int mid, int upperBound)
{
	int size1 = mid - lowerBound + 1;
	int size2 = upperBound - mid;

	T* tmp1 = NULL;
	tmp1 = new T[size1];

	T* tmp2 = NULL;
	tmp2 = new T[size2];

	for (int i = 0; i < size1; i++)
	{
		tmp1[i] = list[lowerBound + i];
	}

	for (int j = 0; j < size2; j++)
	{
		tmp2[j] = list[mid + j + 1];
	}

	int i = 0;
	int j = i;
	int k;

	for (k = lowerBound; k <= upperBound && i < size1 && j < size2; k++)
	{
		if (tmp1[i] <= tmp2[j])
		{
			list[k] = tmp1[i];
			i++;
		}
		else
		{
			list[k] = tmp2[j];
			j++;
		}
	}

	while (i < size1)
	{
		list[k] = tmp1[i];
		++i;
		k++;
	}

	while (j < size2)
	{
		list[k] = tmp2[j];
		++j;
		k++;
	}
	delete[] tmp1;
	delete[] tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
}



template <typename T>
void mergeSort(T list[], int lowerBound, int upperBound)
{
	if (lowerBound < upperBound)
	{
		int mid = (upperBound + lowerBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}
}



template <typename T>
void quickSort(T list[], int lowerBound, int upperBound)
{
	int i = lowerBound;
	int j = upperBound;

	T pivot = list[(upperBound + lowerBound) / 2];

	while (i <= j)
	{
		while (list[i] < pivot)
		{
			i++;
		}

		while (list[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			swap(list[i], list[j]);
			i++;
			j--;
		}
	}

	if (lowerBound < j)
	{
		quickSort(list, lowerBound, j);
	}

	if (upperBound > i)
	{
		quickSort(list, i, upperBound);
	}

}



template <typename T>
void selectionSort(T list[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (list[j] < list[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(list[i], list[minIndex]);
		}
	}
}



template <typename T>
void shellSort(T list[], int size)
{
	int gap = size / 2;
	int i;
	while (gap > 0)
	{
		for (i = 0; i < size - gap; i++)
		{
			if (list[i] > list[i + gap])
			{
				swap(list[i], list[i + gap]);
			}
		}
		gap /= 2;
	}
	bubbleSort(list, size);
}



template <typename T>
void swap(T& item1, T& item2)
{
	T temp = item1;
	item1 = item2;
	item2 = temp;
}
