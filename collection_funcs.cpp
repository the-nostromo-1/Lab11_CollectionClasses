//
// Class functions
// David Tinley
// 11/16/22
//

#include <iostream>
#include "collection.hpp"

using std::cout;
using std::endl;

Collection::Collection() { // Constructor
    size_ = 0;
    col_ = new double[0];
}

Collection::Collection(const Collection &obj_1) { // Copy constructor
    size_ = obj_1.size();
    col_ = new double[size_];
    for (int i = 0; i < size_; ++i) {
        col_ [i] = obj_1.col_[i];
    }
}

Collection& Collection::operator=(const Collection &obj_2) { // Overload assignment
    if (this != &obj_2) {
    size_ = obj_2.size();
    delete [] col_;
    col_ = new double[size_];
    for (int i = 0; i < size_; ++i) {
        col_ [i] = obj_2.col_[i];
    }
    }
   return *this;
}

Collection::~Collection() { // destructor
    delete [] col_;
}

// tests pass-by-value for object of class Collection
void testfunc(Collection c){ // copy constructor is invoked on "c"
    cout << "parameter c: "; 
    c.output(); 
} // destructor is invoked when "c" goes out of scope


////////////////////////////////////////////////////////////////
// Class member functions
////////////////////////////////////////////////////////////////

int Collection::check(double number) { 
    for (int i = 0; i < size_; i++) {
    if (col_[i] == number) {
        return i;
    }
    }
    return -1;
} // returns index of element containg "number" or -1 if none

void Collection::addNumber(double numb_added) { // adds number to the collection
    int index_checked = check(numb_added);
    if (index_checked == -1) {
    ++size_;
      double *tmp = new double[size_];
    for (int i = 0; i < size_; ++i) {
        tmp[i] = col_[i];
    }
    tmp[size_ - 1] = numb_added;
    delete [] col_;
    col_ = tmp;
    } else {
    cout << "Duplicate!" << endl;
    }
}

void Collection::removeNumber(double numb_removed) { // deletes the number from the collection
    int index_checked = check(numb_removed);
    if (index_checked != -1) {
        bool found = false;
        --size_;
        double *tmp = new double[size_];
        for (int i = 0; i < size_ + 1; ++i) {
			if (col_[i] == numb_removed) {
				found = true;
			}
			else {
				if (found == false) {
					tmp[i] = col_[i];
				}
				else {
					tmp[i - 1] = col_[i];
				}
			}
		}
		delete[] col_;
		col_ = tmp;
	} else {
		cout << "That number is not on the array!" << endl;
	}
}



void Collection::output() const { // prints the values of the collection
    for (int i = 0; i < size_; ++i) {
        cout << col_[i] << " " << endl;
    }
}

double Collection::value() const { // returns the sum of the elements in the collection
    double new_value = 0.0;
    for (int i = 0; i < size_; ++i) {
        new_value += col_[i];
    }
    return new_value;
}