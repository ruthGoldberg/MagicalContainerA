#include "MagicalContainer.hpp"
#include <cstddef>
using namespace ariel;

MagicalContainer :: MagicalContainer(size_t initialcapacity ):
capacity(initialcapacity), ContainerSize(0), magicContainer(new int[initialcapacity]){}

MagicalContainer:: ~MagicalContainer(){
    destructor();
}

void MagicalContainer::destructor(){
    delete[] magicContainer;
}
void MagicalContainer::addElement(int element){
    bool exists = false;
    for(int i = 0; i < ContainerSize && !exists; i++){
        if(magicContainer[i] == element){
            exists = true;
        }
    }
    if(exists)
        return;
    if (ContainerSize == capacity) 
        resize();
    size_t insertIndex = 0;
    while (insertIndex < ContainerSize && magicContainer[insertIndex] <= element) {
        insertIndex++;
    }

    for (size_t i = ContainerSize ; i > insertIndex; i--) {
        magicContainer[i] = magicContainer[i - 1];
    }
    magicContainer[insertIndex] = element;
    ContainerSize++;
}
void MagicalContainer :: resize(){
    capacity *= 2;
    int* newContainer = new int[capacity];
    for (int i = 0; i < ContainerSize; i++) {
            newContainer[i] = magicContainer[i];
    }
    destructor();
    magicContainer = newContainer;
}

void MagicalContainer::removeElement(int element){
    int index = -1;

    for (int i = 0; i < ContainerSize; i++) {
        if (magicContainer[i] == element) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return;
    }

    for (int i = index; i < ContainerSize - 1; i++) {
        magicContainer[i] = magicContainer[i + 1];
    }

    ContainerSize--;
}

int MagicalContainer:: size()const{
    return ContainerSize;
    int c_size;
}

//AcendingIterator implementation
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container):
current(container.magicContainer) , container(container){}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& iterator):
current(iterator.current) , container(iterator.container)
{}

MagicalContainer::AscendingIterator& MagicalContainer ::AscendingIterator ::operator=(const AscendingIterator& other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator:: begin(){
    return AscendingIterator(*this);
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator:: end(){
    AscendingIterator iterator(*this);
    iterator.current += container.size();
    return iterator;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    ++current;
    return *this;
}
int MagicalContainer::AscendingIterator:: operator*(){
    return *current;
}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other)const{
    return current > other.current;
}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other)const{
    return current < other.current;
}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other)const{
    return current == other.current;
}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other)const{
    return current != other.current;
}

//SideCrossIterator implementation

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container):
current(container.magicContainer) , container(container){}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& iterator):
current(iterator.current), container(iterator.container)
{}

MagicalContainer::SideCrossIterator& MagicalContainer ::SideCrossIterator ::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator:: begin(){
    return SideCrossIterator(*this);
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator:: end(){
    SideCrossIterator iterator(*this);
    iterator.current += container.size();
    return iterator;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
    ++current;
    return *this;
}
int MagicalContainer::SideCrossIterator:: operator*(){
    return *current;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other)const{
    return current > other.current;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other)const{
    return current < other.current;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other)const{
    return current == other.current;
}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other)const{
    return current != other.current;
}

//PrimeIterator implementation

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container):
current(container.magicContainer) , container(container){}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& iterator):
current(iterator.current) , container(iterator.container)
{}

MagicalContainer::PrimeIterator& MagicalContainer ::PrimeIterator ::operator=(const PrimeIterator& other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: begin(){
    return PrimeIterator(*this);
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: end(){
    PrimeIterator iterator(*this);
    iterator.current += container.size();
    return iterator;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
    ++current;
    return *this;
}
int MagicalContainer::PrimeIterator:: operator*(){
    return *current;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)const{
    return current > other.current;
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other)const{
    return current < other.current;
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other)const{
    return current == other.current;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other)const{
    return current != other.current;
}