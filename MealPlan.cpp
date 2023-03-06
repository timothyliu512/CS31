//
//  MealPlan.cpp
//  Project 5
//
//  Created by Timothy Liu on 2/27/23.
//

#ifndef ENUMS
#define ENUMS

//#include "BruinCard.h"
#include "Enums.h"
#include "MealPlan.h"
#include <iostream>
using namespace std;

MealPlan::MealPlan()
{
    
}

// mPlan is type plan

void MealPlan::pickPlan( plan p)
{
    mPlan = p;
}

plan MealPlan::getPlan()
{
    return mPlan;
}

double MealPlan::cost()
{
    switch (mPlan) { // Returns cost of each meal plan
        case REGULAR11:
            return 4646.64;
            break;
        case PREMIER11:
            return 5018.28;
            break;
        case REGULAR14:
            return 5107.20;
            break;
        case PREMIER14:
            return 5570.04;
            break;
        case REGULAR19:
            return 5278.20;
            break;
        case PREMIER19:
            return 5898.20;
            break;
        default:
            return 0;
            break;
    }
}

int MealPlan::mealsEachWeek()
{
    switch (mPlan)
    {
        case REGULAR11: //How many meals you get each week ??
        case PREMIER11:
            return 11;
            break;
        case REGULAR14:
        case PREMIER14:
            return 14;
            break;
        case REGULAR19:
        case PREMIER19:
            return 19;
            break;
        default:
            return 0;
    }
}

bool MealPlan::unusedMealsCarryOver()
{
    if (mPlan == REGULAR11 || mPlan == REGULAR14 || mPlan == REGULAR19)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif
