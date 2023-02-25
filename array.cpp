//
//  array.cpp
//  array
//
//  Created by Timothy Liu on 2/16/23.
//

#include <iostream>
#include <string>
#include <cassert>
#include <assert.h>
using namespace std;

int locateMaximum( const string array[], int n);
bool hasNoDuplicates( const string array[ ], int n );
int countXPairs( const string array[ ], int n, int x );
int findSecondToLastOccurrence( const string array[ ], int n, string target );
int countPunctuation( const string array[ ], int n );
int flipAround(string array[ ], int n );
int moveToEnd( string array[ ], int  n, int pos );

int main()
{
    return 0;
}

int locateMaximum ( const string array[], int n) {
    
    if (n <= 0) // Bounds check
    {
        return -1;
    }
    
    int biggest = 0; // Track index of biggest item found
    
    for ( int i = 0; i < n; i++ ) //Go through each item in the array
    {
        {
            if (array[i] == array[biggest])
            {
                // If size is the same, keep the smaller index
            }
            else if (array[i] > array[biggest])
            {
                biggest = i; // If size is larger, set index to new biggest item found
            }
        }
    }
    
    return biggest; // Return index of largest item found
}

bool hasNoDuplicates( const string array[ ], int  n ) {
    
    if (n < 0) // Bounds check
    {
        return false;
    }
    
    bool noDuplicates = true; // Tracks whether a no duplicate is found
    
    for ( size_t i = 0; i < n; i++ ) // Check each element in array
    {
        for ( size_t j = 0; j < n; j++ ) // Compare element in array to other elements in array
        {
            if (i != j && array[i] == array[j]) //Check if they are duplicate items
            {
                noDuplicates = false;
            }
        }
    }
        return noDuplicates;
}


int countXPairs(const string array[], int n, int x)
{
    if (n <= 0) // Bounds check
    {
     return -1;
    }
    
    int XPairs = 0; // Track number of times two different elements in array sum up to parameter x
    
    for ( size_t i = 0; i < n ; i++ ) // Goes through elements of array
    {
        for ( size_t j = i+1; j < n; j++ ) // Compare element to other elements of array
        {
            if ( (stoi(array[i]) + stoi(array[j]) ) == x && i != j ) // Check if they sum up to parameter x
            {
                XPairs++;
            }
        }
    }
    return XPairs;
}

int findSecondToLastOccurrence( const string array[], int n, string target){
    if (n < 1) // Bounds check
    {
        return -1;
    }
    
    int secondToLastOccurenceIndex = -1; // Tracks index of second to last occurence of target
    bool seenBefore = false; // Checks whether target string has been found once already
    
    for (int i = n-1; i >= 0; i--) // Go through the string backwards
    {
        if (array[i] == target && seenBefore == false) // Check for last occurence of the target string
        {
            seenBefore = true;
        }
        else if (array[i] == target && seenBefore == true) // Check for second to last occurence of target string
        {
            secondToLastOccurenceIndex = i;
            break;
        }
    }
    return secondToLastOccurenceIndex;
}


int countPunctuation( const string array[], int n ){
    if (n <= 0)
    {
        return -1;
    }
    int counter = 0; // Count how many times punctuation values were found
    for ( size_t i = 0; i < n; i++ ) //Loops through elements of array
    {
        for( size_t j = 0; j < array[i].length(); j++ ) //Loops through characters in element of the array
        {
            char c = array[i].at(j); //Check for any punctuations in the character
            switch(c)
            {
                case '.':
                    counter++;
                    break;
                case ',':
                    counter++;
                    break;
                case '!':
                    counter++;
                    break;
                case ';':
                    counter++;
                    break;
                case '\'':
                    counter++;
                    break;
                case '-':
                    counter++;
                    break;
                case '/':
                    counter++;
                    break;
                case ':':
                    counter++;
                    break;
                case '?':
                    counter++;
                    break;
                case '"':
                    counter++;
                    break;
                default:
                    break;
            }
        }
    }

        return counter;
}


int flipAround(string array[], int n ){
    if (n <= 1)
    {
        return 0;
    }
    
    size_t i = 0; // Goes through elements left to right
    size_t j = n-1; // Goes through elements right to left
    int counter = 0; // Tracks how many flips occur
    
    string placeHolder; // Variable that holds element temporarily
    
    for (i = 0, j = n-1; i < j ; i++, j--) // or n/2
    {
        placeHolder = array[i]; // Store left element
        array[i] = array[j]; // Replace left element with right element
        array[j] = placeHolder; // Put stored left element into right element
        counter++;
    }
     
    return counter;
}

int moveToEnd(string array[ ], int  n, int pos ) {
    if (n <= 0 || pos >= n || pos < 0) // Bounds check
    {
        return -1;
    }
    
    string placeholder = array[pos];

    size_t i = pos;
    while(i<n)
    {
        array[i] = array[i+1];
        i++;
    }
    /*
    for (size_t i = pos; i < n; i++) // Goes through all elements after pos
    {
        array[i] = array[i+1]; // Copies all the elements and moves them down one index
    }
    */
    
    array[n-1] = placeholder; // Place original item into the last index position

    return pos;
}

