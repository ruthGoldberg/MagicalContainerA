#include "sources/MagicalContainer.hpp"
#include "doctest.h"
using namespace ariel;

TEST_SUITE("MagicalContainer"){

    TEST_CASE("create magicalContainer"){
        MagicalContainer container;
        CHECK(container.size() == 0);
    }

    TEST_CASE("Assert new elemnts"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        CHECK(container.size() == 3);
    }

    TEST_CASE("Remove an element"){
        MagicalContainer container;
        container.addElement(8);
        container.addElement(11);
        container.removeElement(8);
        CHECK(container.size() == 1);
        CHECK_THROWS(container.removeElement(3));
    }
}


TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    container.addElement(19);
    container.addElement(21);
    container.addElement(8);
    container.addElement(103);
    container.addElement(1);

    SUBCASE("++ , < , > , == , !="){
        MagicalContainer::AscendingIterator Aiterator1(container);
        MagicalContainer::AscendingIterator Aiterator2(container);
        CHECK(Aiterator1 == Aiterator2);
        ++Aiterator1;
        CHECK(Aiterator1 > Aiterator2);
        ++Aiterator2;
        ++Aiterator2;
        CHECK(Aiterator1 < Aiterator2);
        CHECK(Aiterator1 != Aiterator2);

    }

    SUBCASE("begin , end"){
        MagicalContainer::AscendingIterator Aiterator(container);
        CHECK(Aiterator == Aiterator.begin());
        CHECK(*(Aiterator.begin()) == 1);
        ++Aiterator;
        CHECK(*Aiterator == 8);
        ++Aiterator;
        CHECK(*Aiterator == 19);
        ++Aiterator;
        CHECK(*Aiterator == 21);
        ++Aiterator;
        CHECK(*Aiterator == 103);
        ++Aiterator;
        CHECK(Aiterator == Aiterator.end());
        CHECK_THROWS(++Aiterator);
    }

}

TEST_CASE("SideCrossIterator"){
    MagicalContainer container;
    container.addElement(50);
    container.addElement(31);
    container.addElement(9);
    container.addElement(45);
    container.addElement(29);

    SUBCASE("++ , < , > , == , !="){
        MagicalContainer::SideCrossIterator SCiterator1(container);
        MagicalContainer::SideCrossIterator SCiterator2(container);
        CHECK(SCiterator1 == SCiterator2);
        ++SCiterator1;
        CHECK(SCiterator1 > SCiterator2);
        ++SCiterator2;
        ++SCiterator2;
        CHECK(SCiterator1 < SCiterator2);
        CHECK(SCiterator1 != SCiterator2);

    }

    SUBCASE("begin , end"){
        MagicalContainer::SideCrossIterator SCiterator(container);
        CHECK(SCiterator == SCiterator.begin());
        CHECK(*(SCiterator.begin()) == 9);
        ++SCiterator;
        CHECK(*SCiterator == 50);
        ++SCiterator;
        CHECK(*SCiterator == 29);
        ++SCiterator;
        CHECK(*SCiterator == 45);
        ++SCiterator;
        CHECK(*SCiterator == 31);
        ++SCiterator;
        CHECK(SCiterator == SCiterator.end());
        CHECK_THROWS(++SCiterator);
    }
}

TEST_CASE("PrimeIterator"){
    MagicalContainer container;
    container.addElement(82);
    container.addElement(17);
    container.addElement(2);
    container.addElement(100);
    container.addElement(41);

    SUBCASE("++ , < , > , == , !="){
        MagicalContainer::PrimeIterator Piterator1(container);
        MagicalContainer::PrimeIterator Piterator2(container);
        CHECK(Piterator1 == Piterator2);
        ++Piterator1;
        CHECK(Piterator1 > Piterator2);
        ++Piterator2;
        ++Piterator2;
        CHECK(Piterator1 < Piterator2);
        CHECK(Piterator1 != Piterator2);

    }

    SUBCASE("begin , end"){
        MagicalContainer::PrimeIterator Piterator(container);
        CHECK(Piterator == Piterator.begin());
        CHECK(*(Piterator.begin()) == 2);
        ++Piterator;
        CHECK(*Piterator == 17);
        ++Piterator;
        CHECK(*Piterator == 41);
        ++Piterator;
        CHECK(Piterator == Piterator.end());
        CHECK_THROWS(++Piterator);
    }
}