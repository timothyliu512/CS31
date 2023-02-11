//
//  movie.cpp
//  movie
//
//  Created by Timothy Liu on 1/17/23.
//  Dis 2A
//  UID: 005994409

//Remember to remove all the movie rating outputs throughout, was only used for testing

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout.setf(ios::fixed);          //Initialize movieRating
    cout.setf(ios::showpoint);
    cout.precision(1);
    double movieRating = 0;
    
    //Question 1
    cout << "What movie is to be rated? ";      //Movie Name
    string movieName;
    getline(cin, movieName);
    
    //Question 2
    cout << "On a scale of 1-10, how much do you like movies with a similar theme? ";
    int themeRating;
    cin >> themeRating;
    if (cin.fail()) {                               //If input not an integer, then stop
        cout << "Invalid theme value!" << endl;
        return 1;
    }
    else if (themeRating < 1 || themeRating > 10){  //If input not an integer between 1 and 10 inclusive, then stop
        cout << "Invalid theme value!" << endl;
        return 1;
    }
    else {                                          //If input is valid, then include the theme rating into the movie rating
        movieRating += 0.3*themeRating;
    }
    
    //Question 3
    
    cout << "Do you like movies starring the actor or actress that stars in this movie? ";
    string actorInput;
    cin.ignore(10000,'\n');
    getline(cin, actorInput);
    
    if (actorInput == "Yes"){ // If input is "Yes" then adjust the rating accordingly
        movieRating += 2.0;
    }
    else if (actorInput == "No") { // If input is "No" then adjust the rating accordingly
        movieRating += 0.0;
    }
    else {
        cout << "Invalid actor value!" << endl; //If input is neither "Yes" nor "No" then stop
        return 1;
    }
    
    //Question 4
    
    cout << "On a scale of 1-10, how much do users with tastes similar to yours like this movie? ";
    int tasteRating;
    cin >> tasteRating;
    
    if (cin.fail()) {                               //Check if input is integer
        cout << "Invalid taste value!" << endl;
        return 1;
    }
    else if (tasteRating < 1 || tasteRating > 10){  //Check if input is between 1 and 10 inclusive
        cout << "Invalid taste value!" << endl;
        return 1;
    }
    else {                                          //If input is valid, then include the theme rating into the movie rating
        movieRating += 0.3*tasteRating;
    }
    
    //Question 5
    
    cout << "Have you thumbed up this movie already? ";
    string thumbedUpInput;
    cin.ignore(10000, '\n');
    getline(cin, thumbedUpInput);
    
    if (thumbedUpInput == "Yes") {  //Check if input is "Yes"
        movieRating += 2.0;
    }
    else if (thumbedUpInput == "No") { //Check if input is "No"
        movieRating += 0.0;
    }
    else {                                                          //If input neither Yes or No, then invalid thumbed up value
        cout << "Invalid thumbed up value!" << endl;
        return 1;
    }
    
    //Question 6
    
    cout << "Have you thumbed down this movie already? ";
    string thumbedDownInput;                                    //Value given for whether user thumbs up or down
    getline(cin, thumbedDownInput);
    
    if (thumbedDownInput == "Yes") {  //If thumbed down (Yes) then movie rating decreases by 2
        movieRating -= 2.0;
    }
    
    else if (thumbedDownInput == "No") {
        movieRating += 0.0;                                         //If not thumbed down (No) then movie rating doesn't change
    }
    
    else {                                                          //If input neither Yes or No, then invalid thumbed down value
        cout << "Invalid thumbed down value!" << endl;
        return 1;
    }
    
    cout << "Our recommendation for you for the movie: " << movieName << " is " << movieRating << endl;
    
    return 0;
}
