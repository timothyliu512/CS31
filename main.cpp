//
//  main.cpp
//  Mastermind
//
//  Created by Howard Stahl on 9/21/22.
//

#include <iostream>
#include "Random.h"
#include "Piece.h"
#include "Board.h"
#include "Score.h"
#include "Settings.h"
#include "Enums.h"
#include "Mastermind.h"


int main( ) {
    using namespace cs31;
    using namespace std;
    
      //Choose a random answer...

    Mastermind game;
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;

    cout << game.answer() << '\n';
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    getline( cin, turn );
                    Move m = game.play( turn );

                    if (m.isValid())
                    {
                        Score s = game.endRound(m);
                        s.isExactMatch();  // just to avoid warning...
                    }
                    else
                    {
                        // turn was not a valid word
                        cout << turn << " was not a Mastermind game entry!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            cout << game.display( message ) << endl;
        }
        else
        {
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning Mastermind game entry was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );

 //test code
    
    Piece p;
    assert( p.getColor() == NOTVALID );
    p = Piece( "G" );
    assert( p.getColor() == GREEN );
    assert( p.getColorAsString() == "G" );

    Move m;
    p = m.getPiece( 0 );
    assert( p.getColor() == NOTVALID );
    m.setPieces( "GBBB" );
    p = m.getPiece( 2 );
    assert( p.getColor() == BLUE );
    m.setPiece( 2, 'y' );
    p = m.getPiece( 2 );
    assert( p.getColor() == YELLOW );

    Score s;
    assert( s.isExactMatch()  == false );
    assert( s.getAnswer( 2 ) == WRONG );
    m.setPieces( "RBRB" );
    Move theAnswer;
    theAnswer.setPieces( "YOYO" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == false );
    assert( s.to_string() == "____" );
    theAnswer.setPieces( "rbrb" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == true );
    assert( s.to_string() == "RRRR" );

    Board b;
    assert( b.getCurrentRound() == 0 );
    m.setPieces( "RRRR" );
    theAnswer.setPieces( "OYPP" );
    s = Score( m, theAnswer );
    b.endRound( m, s );
    assert( b.getCurrentRound() == 1 );
    assert( b.getMoveForRound( 0 ).to_string() == "RRRR" );
    assert( b.getScoreForRound( 0 ).to_string() == "____" );


    Mastermind game2( "rbyo" );
    assert( game2.answer() == "RBYO" );
    assert( game2.gameIsOver() == false );
    m = game2.play( "BBBB" );
    s = game2.endRound( m );
    assert( s.to_string() == "_R__" );


    cout << "all tests passed!" << endl;
    
    return( 0 );
}
