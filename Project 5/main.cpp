//
//  main.cpp
//  Project 5
//
//  Created by Timothy Liu on 2/27/23.
//

#include <iostream>
#include <string>
#include <cassert>

#include "Enums.h"
#include "MealPlan.h"
#include "BruinCard.h"

using namespace std;

int main() {

    MealPlan Meal_Plan_Test;
    BruinCard Bcard_Plan_Test;
    Meal_Plan_Test.pickPlan(PREMIER11);
    Meal_Plan_Test.getPlan();
    

    Bcard_Plan_Test.purchaseMealPlan(Meal_Plan_Test);
    Bcard_Plan_Test.hasPurchasedMealPlan();
    
     /*
    // sample test code working with BruinCard
    BruinCard noMealPlan;
    assert( noMealPlan.hasPurchasedMealPlan( ) == false );
    assert( noMealPlan.mealsLeftThisWeek() == 0 );
    assert( noMealPlan.eat( BREAKFAST ) == false );

    */
    
    // sample test code working with MealPlan and BruinCard
    BruinCard c;
    MealPlan m;
    m.pickPlan( PREMIER11 );
    c.purchaseMealPlan( m );
    c.startQuarter();                     // Premier plans get all their meals at the start of each quarter
    assert( c.mealsLeftThisWeek() == 11*11 );
    c.newWeek();
    assert( c.eat( BREAKFAST ) );                 // using one meal on the plan
    assert( c.eat( BREAKFAST ) );                 // Premier plans can use multiple meals at the same sitting
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newDay();
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newWeek();
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    assert( std::to_string( m.cost() ) == "5018.280000" );
    assert(m.unusedMealsCarryOver()==true);
    //assert(c.getHowManyMealsLeft() == 11*11 - 2);

    BruinCard d;
    MealPlan n;
    n.pickPlan( REGULAR11 );
    d.purchaseMealPlan( n );
    d.startQuarter();
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans get their meals at the start of each week
    assert( d.eat( BREAKFAST ) );
    assert( d.eat( BREAKFAST ) == false );          // Regular plans cannot dine twice at the same meal
    assert( d.mealsLeftThisWeek() == 10 );
    d.newDay();
    assert( d.eat( BREAKFAST ) );
    assert( d.mealsLeftThisWeek() == 9 );
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans lose any meals leftover at the start of the new week
    assert( std::to_string( n.cost() ) == "4646.640000" );
    assert(n.unusedMealsCarryOver()==false);

    BruinCard e;
    e.startQuarter();
    e.newWeek();
    // without a meal plan, BruinCards cannot be used for meals
    assert( e.eat( BREAKFAST ) == false );
    assert( e.mealsLeftThisWeek() == 0 );
    e.newDay();
    assert( e.eat( LUNCH ) == false );
    assert( e.eat( DINNER ) == false );
    assert( e.eat( WEEKENDBRUNCH ) == false );
    
    
    BruinCard fBruinCard;
    MealPlan fMealPlan;
    fMealPlan.pickPlan( REGULAR19 );
    fBruinCard.purchaseMealPlan( n );
    fBruinCard.startQuarter();
    fBruinCard.newWeek();
    fBruinCard.newDay();
    fBruinCard.eat(BREAKFAST);
    assert( fBruinCard.eat(BREAKFAST) == false);
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    fBruinCard.newWeek();
    assert( fBruinCard.eat(BREAKFAST) == false);
    
    BruinCard noMealPlanBruinCard;
    MealPlan noMealPlan;
    
    noMealPlanBruinCard.startQuarter();
    assert( noMealPlanBruinCard.eat( BREAKFAST)== false);
    assert( noMealPlanBruinCard.eat( LUNCH )== false);
    assert( noMealPlanBruinCard.eat( DINNER )== false);
    assert( noMealPlanBruinCard.eat( WEEKENDBRUNCH )== false);
    noMealPlanBruinCard.startQuarter();
    assert( noMealPlanBruinCard.eat( BREAKFAST)== false);
    noMealPlanBruinCard.newWeek();
    noMealPlanBruinCard.newDay();
    assert( noMealPlanBruinCard.eat( BREAKFAST)== false);
    assert( noMealPlanBruinCard.eat( BREAKFAST)== false);
    noMealPlanBruinCard.newDay();
    assert( noMealPlanBruinCard.eat( BREAKFAST)== false);
    
    BruinCard premierPlanUser;
    MealPlan premierPlanUserMealPlan;
    premierPlanUserMealPlan.pickPlan(PREMIER19);
    premierPlanUser.purchaseMealPlan(premierPlanUserMealPlan);
    premierPlanUser.startQuarter();
    premierPlanUser.newWeek();
    premierPlanUser.newDay();
    assert(premierPlanUser.mealsLeftThisWeek() == 11*19);
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    premierPlanUser.newWeek();
    
    assert( premierPlanUser.mealsLeftThisWeek() == 11*19);
    assert( premierPlanUser.eat( BREAKFAST ) == true);
    assert( premierPlanUser.eat( LUNCH ) == true);
    assert( premierPlanUser.eat( BREAKFAST ) == true);
    assert( premierPlanUser.mealsLeftThisWeek() == 11*19-3);
    
    BruinCard regularPlanUser;
    MealPlan regularPlanUserMealPlan;
    regularPlanUserMealPlan.pickPlan(REGULAR19);
    regularPlanUser.purchaseMealPlan(regularPlanUserMealPlan);
    
    regularPlanUser.startQuarter();
    regularPlanUser.newWeek();
    regularPlanUser.newDay();
    
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    regularPlanUser.newWeek();
    
    assert( regularPlanUser.mealsLeftThisWeek() == 0);
    
    BruinCard regular11B;
    MealPlan regular11M;
    regular11M.pickPlan(REGULAR11);
    regular11B.purchaseMealPlan( regular11M );
    regular11B.startQuarter();
    assert ( regular11M.cost()== 4646.64 );
    
    BruinCard x;
    MealPlan xM;
    xM.pickPlan(REGULAR14);
    x.purchaseMealPlan(xM);
    x.startQuarter();
    x.newWeek();
    x.newDay();
    x.eat( BREAKFAST );
    x.eat( BREAKFAST );
    assert(x.mealsLeftThisWeek() == 13);
    x.eat (LUNCH);
    assert(x.mealsLeftThisWeek() == 12);
    x.newWeek();
    assert(x.mealsLeftThisWeek()==14);
    x.eat( BREAKFAST);
    x.eat(LUNCH);
    x.eat(DINNER);
    x.newDay();
    x.eat(BREAKFAST);
    assert(x.mealsLeftThisWeek() == 10);
    
    BruinCard xyz;
    MealPlan xyz1;
    xyz1.pickPlan(REGULAR19);
    xyz.purchaseMealPlan(xyz1);
    
    xyz.startQuarter();
    xyz.newWeek();
    xyz.eat(BREAKFAST);
    assert(xyz.eat(LUNCH)==true);
    xyz.newDay();
    xyz.eat(BREAKFAST);
    xyz.eat(WEEKENDBRUNCH);
    xyz.eat(LUNCH);
    xyz.eat(LUNCH);
    assert(xyz.eat(LUNCH)==false);
    xyz.newDay();
    assert(xyz.eat(BREAKFAST)==true);
    
    xyz.eat(LUNCH);
    
    
    BruinCard test3;
    MealPlan meal3;
    
    meal3.pickPlan(PREMIER11);
    test3.purchaseMealPlan(meal3);
    
    assert(meal3.cost() == 5018.28);
    test3.startQuarter();
    assert(test3.mealsLeftThisWeek() == 11*11);
    
    BruinCard costB;
    MealPlan costM;
    
    costM.pickPlan(PREMIER19);
    costB.purchaseMealPlan(costM);
    
    costB.startQuarter();
    costB.newWeek();
    assert(costM.cost()== 5898.20  );
    
    
    cout << "All Tests passed"<< endl;
    
    return( 0 ); 
}
