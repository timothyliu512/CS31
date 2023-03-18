//
//  Score.cpp
//

// Checks if the solution matches


#include "Score.h"
#include <stdexcept>
#include <iostream>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score

// Create a constructor that takes two move objects
// One of them represents your guess, the other represents the answer and you compare them
Score::Score( Move move, Move answer )
{
    // Initialize array to all wrong
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG; 
    }
    

    
    // Check whether a color has already been matched up
    bool matched[REQUIREDLENGTH] = {false, false, false, false};
    
    // Mark all the RIGHTs first
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if ( move.getPiece(i).getColor() == answer.getPiece(i).getColor() ) // Check if color matches at position
        {
            array[i] = RIGHT; //Mark it as right
            matched[i] = true; //Mark color as already matched up
        }
    }
    
    // Check for MAYBEs
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        
        if (array[i] == WRONG)
        {
            for (int j = 0; j < REQUIREDLENGTH; j++) // Compare the current position of move to each position of answer
            {
                if(move.getPiece(i).getColor() == answer.getPiece(j).getColor() && matched[j] == false) //If it hasn't been matched up and there is a color match, mark it as MAYBE and mark that it's been matched up
                {
                    matched[j] = true;
                    array[i] = MAYBE;
                    break;
                }
                //BRBR
                //RBRB
            }
        }
    }
    
    // Initialize array to all wrong
    
    // bool array to keep track of matches in answer
    // Initialize bool array to all false
    
    // Loop through and mark all exact matches as RIGHT, (or else set to wrong in one array)
    // Also mark matches to true in bool array
    
    // Nested for loop to mark MAYBEs
    // Loop through move (index i)
        // if move piece is RIGHT, continue (skips to next iteration of loop)
        // Loop through answer (index j)
            // if answer array is true at j, continue
            // if answer piece and move piece have same color
                //mark index i as MAYBE
                //set bool array to true at j
            //But doesn't check for repeats, overlaps with colors already marked
    
    // for now...
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    // Loop through array and return if something isn't RIGHT
    // for now..
    for (int i = 0; i<REQUIREDLENGTH; i++)
    {
        if(array[i] == WRONG || array[i] == MAYBE) // If there's any WRONGs or MAYBEs then not exact match
        {
            return (false);
        }
    }
    return (true);
}








}

