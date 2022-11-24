//
// Class version of number collection game from Lab 10
// David J Tinley
// 11/17/2022
//

#include <iostream>
#include "collection.hpp"
#include "collection_funcs.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

   Collection c1;

   c1.addNumber(1.); // adding starting numbers
   c1.addNumber(2.);
   c1.addNumber(3.);
   c1.addNumber(4.);

   cout << "Collection size is: " << c1.size() << endl;
   cout << "Collection value is: " << c1.value() << endl;

   char user_operation_selection; // 'q' = quit, 'a' = add, or 'r' = remove

   do { // program loop
      cout << "Enter a operation to perform" << endl;
      cout << "'q' to quit, 'a' to add a number to the collection, or 'r' to remove a number from the collection" << endl;
      cin >> user_operation_selection;

      switch (user_operation_selection) {
      case 'q': // quit
         break;

      case 'a': // add a number to the collection
         cout << "Enter a number to add" << endl;
         int number_added;
         cin >> number_added;
         c1.addNumber(number_added);
         cout << endl;
         cout << "Your collection now:" << endl;
         c1.output();
         break;

      case 'r': // remove a number from the collection
         cout << "Enter a number to remove" << endl;
         int number_removed;
         cin >> number_removed;
         c1.removeNumber(number_removed);
         cout << endl;
         cout << "Your collecttion now:" << endl;
         c1.output();
         break;

      default:
         cout << "Please enter a valid selection" << endl;
         break;
      }

   } while (user_operation_selection != 'q');
   return 0;
}