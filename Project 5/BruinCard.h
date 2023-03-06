//
//  BruinCard.h
//  Project 5
//
//  Created by Timothy Liu on 2/27/23.
//

#ifndef BruinCard_h
#define BruinCard_h

#include "Enums.h"
#include "MealPlan.h"

class BruinCard {
    
public:
    
    BruinCard();
    
    void purchaseMealPlan(MealPlan plan);
    bool hasPurchasedMealPlan();
    plan getPlan();
    
    // Operations
    bool eat(meal m);
    
    void startQuarter();
    void newWeek();
    void newDay();
    int mealsLeftThisWeek();
    
private:
    // Data
    
    MealPlan mPlan;
    int mMealsLeftThisWeek; //Tracks how many meals left in current week for regular plan
    
    bool mBoughtAMealPlan;
    
    bool hasEatenBreakfast;
    bool hasEatenLunch;
    bool hasEatenDinner;
    bool hasEatenBrunch;
    
    int howManyMealsLeft;
    
    
    
    
    
};

#endif /* BruinCard_h */
