//
//  Move.cpp
//

#include "Move.h"
#include "Random.h"
#include <stdexcept>

namespace cs31 // To group everything together in that folder
{

// by default, a move is invalid
Move::Move()
{
    // this code is really not needed since the default constructor
    // will do all this work but I am explicitly showing it for CS 31
    // students
    Piece p;  // invalid piece
    // for (int i=0; i<REQUIREDLENGTH; i++)
    //      { array[i]=p; }
    array[ 0 ] = p;
    array[ 1 ] = p;
    array[ 2 ] = p;
    array[ 3 ] = p;
}

// trivial getter
// but throw logic_error if the index is out of range
// Checks if is valid length
Piece Move::getPiece( int i )
{
    
    if ( i >= 0 && i < REQUIREDLENGTH )
        return( array[ i ] );
    else
        throw std::logic_error("invalid i value");
}

// construct a Piece for the Move from the character parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, char c )
{
    if (i >= 0 && i < REQUIREDLENGTH) // Checks the bounds
    {
        Piece p( c );
        array[ i ] = p;
    }
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the Piece parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, Piece p )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        array[ i ] = p;
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the first letter of the string parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, std::string s )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece( i, s.at( 0 ) );
    else
        throw std::logic_error( "invalid i value" );
}

// TODO create the Pieces for this Move from the supplied word
// 1: TODO throw logic_error if the supplied word is too short or too long


    //s: "RYBR"
    //array: [RED, YELLOW, NOTVALID, NOTVALID]
    //Will set each element of the array with Move::setPieces
void  Move::setPieces( std::string s )
{
    if ( s.length() != REQUIREDLENGTH )
    {
        throw std::logic_error( "invalid length" );
    }
    
    for ( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        setPiece( i, s.at(i) );
    }
    // Loop through s:
      // Call setPiece(i, s[i]) where c is the corresponding character at i
       // Don't set output of setPiece to anything
      // Can also use s.at
    // for now...
}

// stringify this Move
std::string Move::to_string() const
{
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        s += array[ i ].getColorAsString();
    }
    return( s );
}

bool  Move::isValid( ) const
{
    bool result( true );
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if (array[i].getColor() == NOTVALID)
        {
            result = false;
        }
    }
    return( result );
}

void  Move::random()
{
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        Random r( VALIDCOLORCOUNT - 1 );
        r.random();
        COLOR c = static_cast< COLOR > ( r.getValue() );
        Piece p( c );
        array[ i ] = p;
    }
}

}

