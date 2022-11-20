/**
 * focaccia.cpp
 *
 * Khanh G Nguyen
 * kgnguyen
 *
 * EECS 183: Project 1
 * Fall 2022
 * 
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    // Calculate the number of loaf needed
    const double PEOPLE_PER_LOAF = 4;
    int numLoaf = ceil(people / PEOPLE_PER_LOAF);
    
    // Values for conversions
    const double FLOUR_CUPS_PER_LOAF = 5;
    const double FLOUR_CUPS_PER_BAG = 20;
    const double YEAST_TSP_PER_LOAF = 1.75;
    const double YEAST_TSP_PER_PACKAGE = 2.25;
    const double SALT_TSP_PER_LOAF = 1.875;
    const double SALT_TSP_PER_CANISTER = 6;
    const double OLIVE_OIL_TBSP_PER_LOAF = 2;
    const double OLIVE_OIL_TBSP_PER_BOTTLE = 500/14.8;
    
    const double FLOUR_BAG_COST = 2.69;
    const double YEAST_PACKAGE_COST = 0.4;
    const double SALT_CANISTER_COST = 0.49;
    const double OLIVE_OIL_BOTTLE_COST = 6.39;
    
    // Calculate and round up the units of each ingredient
    int flourBags = ceil(numLoaf * FLOUR_CUPS_PER_LOAF / FLOUR_CUPS_PER_BAG);
    int yeastPackages = ceil(numLoaf * YEAST_TSP_PER_LOAF / YEAST_TSP_PER_PACKAGE);
    int saltCanisters = ceil(numLoaf * SALT_TSP_PER_LOAF / SALT_TSP_PER_CANISTER);
    int oilBottles = ceil(numLoaf * OLIVE_OIL_TBSP_PER_LOAF / OLIVE_OIL_TBSP_PER_BOTTLE);
    
    double totalCost = (flourBags * FLOUR_BAG_COST) +
                        (yeastPackages * YEAST_PACKAGE_COST) +
                        (saltCanisters * SALT_CANISTER_COST) +
                        (oilBottles * OLIVE_OIL_BOTTLE_COST);
    
    
    cout << "You need to make: " << numLoaf << " ";
    cout << pluralize("loaf", "loaves", numLoaf) << " of focaccia";
    cout << endl << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    cout << flourBags << " " << pluralize("bag", "bags", flourBags) << " of flour";
    cout << endl;
    cout << yeastPackages << " " << pluralize("package", "packages", yeastPackages) << " of yeast";
    cout << endl;
    cout << saltCanisters << " " << pluralize("canister", "canisters", saltCanisters) << " of salt";
    cout << endl;
    cout << oilBottles << " " << pluralize("bottle", "bottles", oilBottles) << " of olive oil";
    cout << endl << endl;
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    cout << "Have a great party!" << endl;
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
