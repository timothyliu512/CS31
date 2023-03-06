//
//  BruinCard.cpp
//  Project 5
//
//  Created by Timothy Liu on 2/27/23.
//

#include "MealPlan.h"
#include "BruinCard.h"
#include "Enums.h"
#include <iostream>

using namespace std;

BruinCard::BruinCard()
{
    mMealsLeftThisWeek = 0;
    mBoughtAMealPlan = false;
}

// mPlan is type MealPlan

void BruinCard::purchaseMealPlan(MealPlan plan)
{
    mPlan = plan;
    mBoughtAMealPlan = true;
}

bool BruinCard::hasPurchasedMealPlan()
{
    return mBoughtAMealPlan;
}

plan BruinCard::getPlan()
{
    return mPlan.getPlan();
}

// Operations
bool BruinCard::eat(meal m)
{
    // If they don't have a meal plan, they have no more meals left this week or there's no more meals left in the quarter, they can't eat
    if (mBoughtAMealPlan == false || mealsLeftThisWeek() <= 0 || howManyMealsLeft <= 0)
    {
        return false;
    }
    switch (m)
    {
        case BREAKFAST:
            if (hasEatenBreakfast == false ) // Check if already ate during the meal period
            {
                if (getPlan() == PREMIER11 || // Check if on premier
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--; // Decrement # meals left in quarter
                    hasEatenBreakfast = true; // User can eat during meal period
                    return true;
                    break;
                }
                else{
                    howManyMealsLeft--; // Decrement # meals left in quarter
                    mMealsLeftThisWeek--; // Decrement #meals left this week for regular
                    hasEatenBreakfast = true; // User can eat during meal period
                    return true;
                    break;
                }
            }
            else // If already ate during meal period, check if they're on premier
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--; // Decrement # meals left in quarter
                    return true; // Allow user to eat during meal period
                    break;
                }
            }
            return false;
            break;
        case LUNCH:
            if (hasEatenLunch == false)
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    hasEatenLunch = true;
                    return true;
                    break;
                }
                else{
                    howManyMealsLeft--;
                    mMealsLeftThisWeek--;
                    hasEatenLunch = true;
                    return true;
                    break;
                }
            }
            else
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    return true;
                    break;
                }
            }
            return false;
            break;
        case DINNER:
            if (hasEatenDinner == false)
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    hasEatenDinner = true;
                    return true;
                    break;
                }
                else
                {
                    howManyMealsLeft--;
                    mMealsLeftThisWeek--;
                    hasEatenDinner = true;
                    return true;
                    break;
                }
            }
            else
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    return true;
                    break;
                }
            }
            return false;
            break;
        case WEEKENDBRUNCH:
            if (hasEatenBrunch == false)
            {
                if (getPlan() == PREMIER11 ||
                    getPlan() == PREMIER14 ||
                    getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    hasEatenBrunch = true;
                    return true;
                    break;
                }
                else
                {
                    howManyMealsLeft--;
                    mMealsLeftThisWeek--;
                    hasEatenBrunch = true;
                    return true;
                    break;
                }
            }
            else
            {
                if (getPlan() == PREMIER11 || getPlan() == PREMIER14 || getPlan() == PREMIER19)
                {
                    howManyMealsLeft--;
                    return true;
                    break;
                }
            }
            return false;
            break;
        default:
            return false;
            break;
    }
}

void BruinCard::startQuarter()
{
    if (mBoughtAMealPlan == false) // If no meal plan, then you have 0 meals left
    {
        mMealsLeftThisWeek = 0;
        howManyMealsLeft = 0;
    }
    
    switch ( getPlan() ) { // Checks which meal plan you have and gives you the amount of meals you get depending on your meal plan
        case REGULAR11:     // If on regular, reset the # of meals left throughout the quarter and the # meals left this week
            howManyMealsLeft = (11*11);
            mMealsLeftThisWeek = 11;
            break;
        case PREMIER11: // If on premier, reset the # meals left throughout the quarter and set # meals left this week to # meals left throughout the quarter
            howManyMealsLeft = (11*11);
            mMealsLeftThisWeek = howManyMealsLeft;
            break;
        case REGULAR14:
            howManyMealsLeft = (11*14);
            mMealsLeftThisWeek = 14;
            break;
        case PREMIER14:
            howManyMealsLeft = (11*14);
            mMealsLeftThisWeek = howManyMealsLeft;
            break;
        case REGULAR19:
            howManyMealsLeft = (11*19);
            mMealsLeftThisWeek = 19;
            break;
        case PREMIER19:
            howManyMealsLeft = (11*19);
            mMealsLeftThisWeek = howManyMealsLeft;
            break;
        default:
            howManyMealsLeft = 0;
            mMealsLeftThisWeek = 0;
            break;
    }
}
void BruinCard::newWeek()
{
    switch ( getPlan() )
    {
        case REGULAR11: // If on regular, set the number of meals per week accordingly to your meal plan
            howManyMealsLeft = howManyMealsLeft - mMealsLeftThisWeek;
            if( howManyMealsLeft >= 11 ) // If they have at least 11 meals remaining, reset the amount of meals they have for the start of the new week to 11
            {
                mMealsLeftThisWeek = 11;
            }
            else // If they have less than 11 meals, don't reset the amount of meals left for the week to 11
            {
                mMealsLeftThisWeek = howManyMealsLeft;
            }
            break;
        case REGULAR14:
            howManyMealsLeft = howManyMealsLeft - mMealsLeftThisWeek;
            if ( howManyMealsLeft >= 14)
            {
                mMealsLeftThisWeek = 14;
            }
            else
            {
                mMealsLeftThisWeek = howManyMealsLeft;
            }
            break;
        case REGULAR19:
            howManyMealsLeft = howManyMealsLeft - mMealsLeftThisWeek;
            if ( howManyMealsLeft >= 19)
            {
                mMealsLeftThisWeek = 19;
            }
            else
            {
                mMealsLeftThisWeek = howManyMealsLeft;
            }
            break;
        case PREMIER11: // If on premier, this doesn't affect the number of meals you have left this week
        case PREMIER14:
        case PREMIER19:
            mMealsLeftThisWeek = howManyMealsLeft;
            break;
        default:
            break;
    }
    hasEatenBreakfast = false; // Designates that you haven't eaten during any meal period at start of week
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}
void BruinCard::newDay()
{
    hasEatenBreakfast = false; // Designates that you haven't eaten during any meal period at start of day
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}


int BruinCard::mealsLeftThisWeek()
{
    if ( hasPurchasedMealPlan() == false) // Checks if you have a meal plan
    {
        return 0;
    }
    
    switch ( getPlan() ) {  // Checks your plan and returns how many meals you have left
        case REGULAR11: // If on regular, it returns # meals left for this week
        case REGULAR14:
        case REGULAR19:
            return mMealsLeftThisWeek;
            break;
        case PREMIER11: // If on premier, it returns # meals left for the entire quarter
        case PREMIER14:
        case PREMIER19:
            return howManyMealsLeft;
            break;
        default:
            return 0;
            break;
    }
}

    
