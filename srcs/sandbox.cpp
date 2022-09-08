//
// Created by Atom Collin on 8/20/22.
//

#include <Vector>
#include "Vector.hpp"
#include "Random_access_iterator.hpp"
#include "Iterator_traits.hpp"
#include <iostream>

int main(void) {
	std::vector<std::string> vector;
	vector.capacity();
    vector.push_back("Yo");
    vector.begin();

    ft::Vector<std::string> myVec;
    myVec.push_back("yoMan");
    std::iterator<>

    std::cout << myVec.at(0) << std::endl;
}