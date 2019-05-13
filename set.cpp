//
// Created by Alexander Urbanyak on 2/4/2018.
//

#include "set.h"

set::set() {
    used = 0;
}

void set::insert(const value_type &entry) {
    if(!contains(entry) && used < CAPACITY){
        data[used] = entry;
        used++;
    }
}

void set::remove(const value_type &entry) {
    for(size_type i = 0; i < used; i++) {
        if(data[i] == entry) {
            data[i] = data[used - 1];   //move the last item in the set
            used--;                     //to the position of the item that is to be removed
            break;
        }
    }
}

set::size_type set::size() const {
    return used;
}

bool set::contains(const value_type &entry) const {
    for(size_type i = 0; i < used; i++) {
        if(data[i] == entry) {
            return true;
        }
    }
    return false;
}

set set_union(const set& s1, const set& s2) {
    set s3;

    for(set::size_type i = 0; i < s1.size(); i++) {
        s3.insert(s1.data[i]);
    }
    for(set::size_type i = 0; i < s2.size(); i++) {
        s3.insert(s2.data[i]);
    }
    return s3;
}

set set_intersection(const set& s1, const set& s2) {
    set s3;

    set::size_type largest = 0;
    if(s1.size() > s2.size()) {
        largest = s1.size();
    }
    else {
        largest = s2.size();
    }

    for(set::size_type i = 0; i < largest; i++) {
        if(s1.contains(s2.data[i])) {
            s3.insert(s2.data[i]);
        }
    }
    return s3;
}

set set_difference(const set& s1, const set& s2) {
    set s3;

    for(set::size_type i = 0; i < s2.size(); i++) {
        if(!s1.contains(s2.data[i])) {
            s3.insert(s1.data[i]);
        }
    }
    return s3;
}

bool is_subset(const set& s1, const set& s2) {
    for(set::size_type i = 0; i < s1.size(); i++) {
        if(!s2.contains(s1.data[i])) {
            return false;
        }
    }
    return true;
}

bool operator == (const set& s1, const set& s2) {
    return is_subset(s1, s2) && is_subset(s2, s1);
}

std::ostream& operator << (std::ostream& output, const set& s) {
    for(set::size_type i = 0; i < s.size(); i++) {
        output << s.data[i] << " ";
    }
    return output;
}

set::size_type set::find(const value_type &entry) const {
    for(size_type i = 0; i < used; i++) {
        if(data[i] == entry) {
            return i;
        }
        break;
    }
    return used;
}