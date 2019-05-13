/************************************
This class models a mathematical set.
*/

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;

    set();
// postcondition: empty set has been created

    void insert (const value_type& entry);
    // precondition: if entry is not in the set, set is not full
    // postcondition: entry is in the set
    //Efficiency: O(n)

    void remove (const value_type& entry);
// postcondition: entry is not in the set
//Efficiency: O(n)

    size_type size() const;
// returned: number of elements in the set
//Efficiency: O(1)

    bool contains (const value_type& entry) const;
// returned: whether entry is in the set
//Efficiency: O(n)

    friend set set_union (const set& s1, const set& s2);
    //returned: union of s1 & s2
    //Efficiency: O(2*n^3)

    friend set set_intersection (const set& s1, const set& s2);
    // returned: intersection of s1 & s2
    //Efficiency: O(n^4)

    friend set set_difference (const set& s1, const set& s2);
// returned: difference of s1 - s2
//Efficiency: O(n^4)

    friend bool is_subset (const set& s1, const set& s2);
// returned: whether s1 is a subset of s2
//Efficiency: O(n^2)

    friend bool operator == (const set& s1, const set& s2);
    // returned: whether s1 & s2 are equal
    //Efficiency: O(n^2)

    friend std::ostream& operator << (std::ostream& output, const set& s);
// postcondition: s has been displayed on output
//Efficiency: O(n)

private:
    size_type find (const value_type& entry) const;
    // returned location of entry in the set if entry is in the set - used otherwise
    //Efficiency: O(n)
    value_type data[CAPACITY];
    size_type used;
};


#endif