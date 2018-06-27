//
//  arrays.cpp
//  EECS280
//
//  Created by Cole Hudson on 6/13/18.
//
#include <iostream>
#include "arrays.h"
#include <cstring>
using namespace std;

//testing
int main()
{
    char array[] = "a#~ *";
    
    /*
    for(int i = 0; i < 100; i++)
    {
        cout<<i;
        cout<<":  ";
        add(array, 5, i);
        cout<<"\n";
    }
     */
    
    add(array, 5, 3);
     
    printArray(array, 5);
    
    //printArray(array, 5);
    
    return 0;
}

//done testing
void printRight(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << "*\n";
    }
}

//done testing
void printRight_upsideDown_rightJustified(int n)
{
    for(int i = 0; i < n; i++)
    {
        //spaces
        for(int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        
        //stars
        for(int k = 0; k < n - i; k++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}

//done testing
void printArray(const char arr[], int size)
{
    for(int i = 0; i < size && size > 0 && size <= SIZE; i++)
    {
        cout<<arr[i];
    }
    cout<<"\n";
}

//done testing
void printArray(const char arr[][SIZE], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

//FIX IT
void add(char arr[], int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        char character = arr[i];
        int asciiCode = character;
        asciiCode += val;
        
        if(asciiCode < MIN_PRINTABLE_ASCII)
        {
            asciiCode += ASCII_PRINTABLE_RANGE;
        }
        else if(asciiCode > MAX_PRINTABLE_ASCII)
        {
            asciiCode -= ASCII_PRINTABLE_RANGE;
        }
        
        character = asciiCode;
        arr[i] = character;
    }
}

//FIX IT
void add(char arr[][SIZE], int rows, int cols, int val)
{
    for(int i = 0; i < rows; i++)
    {
        add(arr[i], strlen(arr[i]), val);
    }
}

//FIX IT
void rotateLeft(char arr[], int size)
{
    char characterToRotate = arr[0];
    for(int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[size - 1] = characterToRotate;
}

//FIX IT
void rotateLeft(char arr[][SIZE], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        rotateLeft(arr[i], strlen(arr[i]));
    }
}

//done testing
void rotateRight(char arr[], int size)
{
    char characterToRotate = arr[size - 1];
    for(int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = characterToRotate;
}

//no testing necessary XD
void rotateRight(char arr[][SIZE], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        rotateRight(arr[i], strlen(arr[i]));
    }
}

//done testing
void reverse(char arr[], int size)
{
    //copy the array
    char copy[size];
    for(int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }
    
    //reverse the original
    for(int i = 0; i < size; i++)
    {
        arr[i] = copy[size - 1 - i];
    }
}

//done testing
void swapRange(char arr1[], int size1, int index1, char arr2[], int size2, int index2, int len)
{
    char swap1[len];
    char swap2[len];
    
    //copy elements from arr1 and arr2
    int swapIndex = 0;
    for(int i = index1; i < index1 + len; i++)
    {
        swap1[swapIndex] = arr1[i];
        swapIndex++;
    }
    swapIndex = 0;
    
    for(int i = index2; i < index2 + len; i++)
    {
        swap2[swapIndex] = arr2[i];
        swapIndex++;
    }
    
    //place in the swapped elements from arr1 to arr2
    swapIndex = 0;
    for(int i = index2; i < index2 + len; i++)
    {
        arr2[i] = swap1[swapIndex];
        swapIndex++;
    }
    
    //place in the swapped elements from arr2 to arr1
    swapIndex = 0;
    for(int i = index1; i < index1 + len; i++)
    {
        arr1[i] = swap2[swapIndex];
        swapIndex++;
    }
}

//done testing
void swapWithinOneRow(char arr[], int size, int len)
{
    for(int i = 0; i < size; i+= (2*len))
    {
        if(i+(2*len) < size + 1)
        {
            swapRange(arr, size, i, arr, size, i+len, len);
        }
    }
}

//done testing
void swapRows(char arr[][SIZE], int rows, int cols)
{
    if(rows > 1)
    {
        //set up the swap row
        char swapRow[cols];
        
        for(int i = 0; i < rows; i+= 2)
        {
            if(i+1 < rows)
            {
                //copy the first of the pair to swapRow
                for(int j = 0; j < cols; j++)
                {
                    swapRow[j] = arr[i][j];
                }
                
                //set the first of the pair to be the second of the pair
                for(int j = 0; j < cols; j++)
                {
                    arr[i][j] = arr[i + 1][j];
                }
                
                //set the second of the pair to be the first of the pair from the swapRow
                for(int j = 0; j < cols; j++)
                {
                    arr[i + 1][j] = swapRow[j];
                }
            }
        }
    }
}
