//
//  MealPlan.h
//  Project 5
//
//  Created by Timothy Liu on 2/27/23.
//

#ifndef MealPlan_h
#define MealPlan_h

#include "Enums.h"

//define class MealPlan

class MealPlan {
public:
    
    MealPlan();
    
    void pickPlan( plan p);
    plan getPlan(); //Getter
    double cost();
    int mealsEachWeek();
    bool unusedMealsCarryOver();
    
private:
    plan mPlan;
    
};


#endif /* MealPlan_h */
