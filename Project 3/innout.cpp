#include <string>
#include <cassert>
#include <cctype>
#include <iostream>
using namespace std;

int extractNumber(string s, size_t& index);

bool isValidOrderString(string orders);
double cost(string orders);
int howManyCombos(string orders, int whichCombo);
int howManyShakes(string orders, string whichShake);

int main()
{
    size_t i = 0;
    assert(extractNumber("123abc", i) == 123);
    assert(i == 3);
    i = 0;
    assert(extractNumber("   123abc", i) == -1);
    assert(i == 0);
    i = 0;
    assert(extractNumber("000123", i ) == -1);
    assert(i == 0);
    assert(extractNumber("20",i)==20);
    assert(isValidOrderString( "20:3_20:2" ) == true);
    assert(isValidOrderString( "20:3_20:2_10:V" ) == false);
    assert(isValidOrderString( "20:32_20:2_10:V" ) == false);
    assert(isValidOrderString( "02:32_20:2_10:V" ) == false);
    assert(isValidOrderString( "200:32_20:2_10:V" ) == false);
    assert(isValidOrderString( "20::32_20:2_10:V" ) == false);
    assert(isValidOrderString( "20:32__20:2_10:V" ) == false);
    assert(isValidOrderString( ":20:32_20:2_10:V" ) == false);
    assert(isValidOrderString( "2:0:32_20:2_10:V" ) == false);
    assert(isValidOrderString( "20:32_20:2_10:V" ) == false);
    assert(cost("20:3_20:2") == 310);
    assert(howManyCombos("20:3_20:2", 3)==20);
    assert(howManyCombos("20:3_20:2_1:3", 3)==21);
    assert(howManyCombos("20:3_20:2_100:3", 3)==-1);
    assert(howManyShakes("20:V_20:V", "Vanilla")==40);
    assert(howManyCombos("1:1_5:1_4:1",1)==10);
    assert(isValidOrderString("40    :    C  ")==false);
    assert(isValidOrderString("40    :C")==false);
    assert(isValidOrderString("40:C__2:1")==false);
    assert(isValidOrderString("40:C_2:1")==true);
    assert(isValidOrderString("20")==false);
    assert(isValidOrderString("20:2")==true);
    assert(isValidOrderString("20:2_")==false);
    assert(isValidOrderString("2:1_1:C"));
    assert(howManyShakes("2:S_2:S_2:S","Strawberry")==6);

    
    // Manual testing
    cout.setf(ios::boolalpha);
    cout.setf(ios::showpoint);
    cout << "In N Out Menu:" << endl;
    cout << "       Double-Double (1):          $9.45 each" << endl;
    cout << "       Cheeseburger (2):           $7.95 each" << endl;
    cout << "       Hamburgers (3)              $7.55 each" << endl;
    cout << "       Chocolate Shakes (C):       $4.95 each" << endl;
    cout << "       Vanilla Shakes (V):         $4.95 each" << endl;
    cout << "       Strawberry Shakes (S):      $4.95 each" << endl<< endl;
    
    cout << "Order format: [#Quantity]:[Menu Item]"<< endl<< endl;
    cout << "Quantities and item numbers must be separated by a colon (:).  Additional quantities and item values will be separated by an underscore (_)"<< endl;
    
    cout << endl << "Example Orders: " << endl;
    cout << "2:2_1:S is an order of 2 Cheeseburgers and 1 Strawberry Shake"<< endl;
    cout << "2:1_3:2: is an order of 2 Double-Doubles and 3 Cheeseburgers"<< endl << endl;
    
    cout << "(Cannot order more than 50 items total)\n" << endl;
    cout << "Enter Innout Order: ";
    string orderTest;
    getline(cin, orderTest);
    bool trueOrNot = isValidOrderString(orderTest);
    double orderCost = cost(orderTest);
    cout << "Order is: " << trueOrNot << endl;
    cout << "Order cost is: " << orderCost << endl;
    cout << howManyCombos(orderTest, 1) << " Combo 1s" << endl;
    cout << howManyCombos(orderTest, 2) << " Combo 2s" << endl;
    cout << howManyCombos(orderTest, 3) << " Combo 3s" << endl;
    cout << howManyShakes(orderTest, "Strawberry")<<" Strawberry Shakes" << endl;
    cout << howManyShakes(orderTest, "Vanilla")<<" Vanilla Shakes" << endl;
    cout << howManyShakes(orderTest, "Chocolate")<<" Chocolate Shakes" << endl;
    cout << "Total Cost: " << cost(orderTest) << endl;
    
    
    return( 0 );
}

int extractNumber( string s, size_t & index ) //Will extract number from string starting from the index
{
    // track the integer value found
    int quantity( -1 );
    
    // do we have more characters to read??
    // this prevents the function from returning the default quantity value (zero)
    // when no characters are actually read from the airport string at all

    // the number should be made up of digits
    while( index < s.length()  &&
           s.at(index) >= '0' &&
           s.at(index) <= '9' )
    {
        if( quantity == -1)
        {
            quantity = 0;
        }
        // extract one digit and add it to the cumulative value held in quantity
        int digit = s.at( index ) - '0';
        quantity = quantity * 10 + digit;
        // if what we find is a beginning zero or many leading zero it is invalid
        if (quantity == 0)
        {
            quantity = -1;
            break;
        }
        index = index + 1;
    }

    return( quantity );
}

bool isValidOrderString(string orders)
{
    int totalQuantity = 0; // Total quantity of items
    size_t positionCounter = 0; // Determine whether quantity is single or double digit
    size_t i = 0; // Current reading position
    
    for (size_t p = 0; p < orders.length(); p++) // Go through entire string and first check if there are any unsupported characters
    {
        if ( !( orders.at(p) == '0' || orders.at(p) == '1' || orders.at(p) == '2' || orders.at(p) == '3' || orders.at(p) == '4' ||  orders.at(p) == '5' || orders.at(p) == '6' || orders.at(p) == '7' || orders.at(p) == '8' || orders.at(p) == '9' || orders.at(p) == 'S' || orders.at(p) == 'V' || orders.at(p) == 'C' || orders.at(p) == ':' || orders.at(p) == '_') )
        {
            return false;
        }
    }
    
    for ( i = 0; i < orders.length(); i++, positionCounter++) // Go through each character in sring order
    {
        if (i > 0 && orders.at(i-1)=='_')
        // Check if there are additional orders
        {
            positionCounter=0;
        }
        
        if (!(orders.at(0) == '1' || orders.at(0) == '2' || orders.at(0) == '3' || orders.at(0) == '4' ||  orders.at(0) == '5' || orders.at(0) == '6' || orders.at(0) == '7' || orders.at(0) == '8' || orders.at(0) == '9' ) ) // Order must begin with a number between 1-9
        {
            return false;
        }
        
        // EXTRACT ITEM QUANTITY
        if (orders.at(i)== ':') // Read up to the first ":" in order to get the quantity before
        {
            int quantity;
            size_t difference = (i - positionCounter); //Check if order is single or double digit
            quantity = extractNumber(orders, difference);
            
            if (quantity < 50 && quantity >0) // Check validity of the number representing the quantity
            {
                totalQuantity += quantity;
            }
            else
            {
                return false;
            }
        }
        
        
        if (totalQuantity < 0 || totalQuantity >=50) // Checks if total quantity stays under 50
        {
            return false;
        }
        
        
        // EXTRACT MENU ITEM
        if (i > 0 && orders.at(i-1)==':') //Will read to menu item and check if there is valid colon before it, then check if menu item is valid
        {
            if (orders.at(i) == 'S' ||
                orders.at(i) == 'V' ||
                orders.at(i) == 'C' ||
                orders.at(i) == '1' ||
                orders.at(i) == '2' ||
                orders.at(i) == '3' )
            {
                // Do nothing
            }
            else
            {
                return false;
            }
            
            i++;
            
            if (i >= orders.length()) // Check if next character is out of bounds or not to see if it's the end of the order
            {
                return true;
            }
            else if (orders.at(i) == '_') // If not out of bounds, check if it's an "_" to see if there are additonal orders
            {
                if ( orders[i+1] == '_' )
                {
                    return false;
                }
            }
            else // If not out of bounds and not an "_", then not valid
            {
                return false;
            }
        }
    }
    return false;
}

double cost(string orders)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (isValidOrderString(orders)== false) //Check first if order string is valid
    {
        return -1.00;
    }
    
    double totalPrice = 0;
    double quantity = 0;
    size_t positionCounter = 0; // Index where the extractNumber function will read (Accounts for single and double digit quantities)
    size_t i = 0; // Use this to keep track of position of where to read
    
    for ( i = 0; i < orders.length(); i++,positionCounter++) // Loop through all the characters in the string
    {
        if (i > 0 && orders.at(i-1)=='_') // If there are additional orders, reset the reading indexes
        {
            positionCounter=0;
            quantity = 0;
        }
        if (orders.at(i)== ':') // Extracts the quantity as a number
        {
            size_t difference = (i - positionCounter);
            quantity = extractNumber(orders, difference);
        }

        if (i > 0 && orders.at(i-1)==':') // Only read menu item if there is a colon before and it's not the first character in the string
        {
            // Find what menu item they ordered, and calculate the price based on how many of that menu item they ordered
            if ( orders.at(i) == 'S' || orders.at(i) == 'V' || orders.at(i) == 'C' )
            {
                totalPrice += quantity*2.85;
            }
            if (orders.at(i) == '1')
            {
                totalPrice += quantity*9.45;
            }
            if (orders.at(i) == '2' )
            {
                totalPrice += quantity*7.95;
            }
            if (orders.at(i) == '3' )
            {
                totalPrice += quantity*7.55;
            }
            
            i++;
            
            if (i >= orders.length()) // Check if next character is out of bounds or not to determine whether it's the end of the order
            {
                return totalPrice;
            }
            else if (orders.at(i) == '_') // If not out of bounds, check if it's an "_" to determine whether there are additional orders
            {
            }
        }
    }
    return -1.00; // If the menu item is invalid, quantity is invalid, if it doesn't meet any of the cases above, etc. then order is assumed to be invalid
}

int howManyCombos(string orders, int whichCombo)
{
    if (isValidOrderString(orders)== false ) //Check first whether order string is valid
    {
        return -1;
    }
    if (!(whichCombo == 1 || whichCombo == 2 || whichCombo == 3)) // If the combo you want to check the quantity of doesn't exist, then function won't work because that combo will not be an item on the menu
    {
        return -1;
    }

    int totalQuantity = 0; // Total quantity of items
    int quantity = 0; // Quantity for the individual item orders
    size_t positionCounter = 0; //Position that extractNumber will begin reading from
    size_t i = 0; // Use this to keep track of position of where to read

    for ( i = 0; i < orders.length(); i++,positionCounter++) // Read each character of the order string
    {
        if (i > 0 && orders.at(i-1)=='_') // If there are additional orders, reset the reading indexes
        {
            positionCounter=0;
            quantity = 0;
        }
        
        if (orders.at(i)== ':') // Extracts the quantity as a number
        {
            size_t difference = (i - positionCounter);
            quantity = extractNumber(orders, difference);
        }
        
        if (i > 0 && orders.at(i-1)==':')
        {
            // Find what menu item they ordered, match the combo item they're checking, then add it to the total quantity of the combo item
            if (orders.at(i) == '1' && whichCombo == 1)
            {
                totalQuantity += quantity;
            }
            if (orders.at(i) == '2' && whichCombo == 2)
            {
                totalQuantity += quantity;
            }
            if (orders.at(i) == '3' && whichCombo == 3)
            {
                totalQuantity += quantity;
            }
            
            i++;

            if ( i >= orders.length() ) // Check if next character is out of bounds or not to determine whether it's the end of the order
            {
                return totalQuantity;
            }
            else if ( orders.at(i) == '_' ) // If not out of bounds, check if it's an "_" to determine whether there are additional orders
            {
                // Do nothing, just continue the loop to read the next order
            }
        }
    }
    return -1;
}

int howManyShakes(string orders, string whichShake)
{
    if ( isValidOrderString(orders)== false ) //Check first whether order string is valid
    {
        return -1;
    }
    if ( !(whichShake == "Strawberry" || whichShake == "Vanilla" || whichShake == "Chocolate") ) // If the shake you want to check the quantity of doesn't exist, then function won't work because that shake will not be an item on the menu
    {
        return -1;
    }

    int totalQuantity = 0; // Total quantity of items
    int quantity = 0; // Quantity for the individual item orders
    size_t positionCounter = 0; //Position that extractNumber will begin reading from
    size_t i = 0; // Use this to keep track of position of where to read

    for ( i = 0; i < orders.length(); i++,positionCounter++) // Read each character of the order string
    {
        if ( i > 0 && orders.at(i-1)=='_' ) // If there are additional orders, reset the reading indexes
        {
            positionCounter=0;
            quantity = 0;
        }
        
        if (orders.at(i)== ':') // Extracts the quantity as a number
        {
            size_t difference = (i - positionCounter);
            quantity = extractNumber(orders, difference);
        }
    
        if (i > 0 && orders.at(i-1)==':')
        {
            // Find which shake they ordered, match the shake they're checking, then add it to the total quantity of the shake they're checking
            if (orders.at(i) == 'S' && whichShake == "Strawberry")
            {
                totalQuantity += quantity;
            }
            if (orders.at(i) == 'V' && whichShake == "Vanilla")
            {
                totalQuantity += quantity;
            }
            if (orders.at(i) == 'C' && whichShake == "Chocolate")
            {
                totalQuantity += quantity;
            }
            
            i++;

            if ( i >= orders.length() ) // Check if next character is out of bounds or not to determine whether it's the end of the order
            {
                return totalQuantity;
            }
            else if (orders.at(i) == '_') // If not out of bounds, check if it's an "_" to determine whether there are additional orders
            {
                // Do nothing, just continue the loop to read the next order
            }
        }
    }
    return -1;
}


// Read up to first : you encounter
// Grab number and check its validity
// If number valid, go on to check for menu items after
// Check for menu items after :
// If you encounter _ then you loop again through next order

// Running index used to go through each order of item
// Once you encounter _ then set the running index to the position of _

// Read up to first : you encounter
// Grab number and check its validity
// If number valid, go on to check for menu items after
// If you encounter _ then you loop again to read next order, if not then break
