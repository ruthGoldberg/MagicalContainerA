
#pragma once
#include <cstddef>

namespace ariel{
    class MagicalContainer
    {
    private:
        int* magicContainer;
        int** primePointers;
        int** crossPointers;
        size_t ContainerSize;
        size_t capacity;
        void destructor();
        void resize();
    public:
        MagicalContainer(size_t initialcapacity = 5);
        ~MagicalContainer();
        void addElement(int);
        void removeElement(int);
        int size()const;
    

        class AscendingIterator{
            private:
                int* current;
                const MagicalContainer& container;
            public:
                AscendingIterator(const MagicalContainer& container);
                AscendingIterator(const AscendingIterator& iterator);
                ~AscendingIterator(){}
                AscendingIterator& operator=(const AscendingIterator& other);
                AscendingIterator begin();
                AscendingIterator end();
                AscendingIterator &operator++();
                int operator*();
                bool operator!=(const AscendingIterator &other)const;
                bool operator==(const AscendingIterator &other)const;
                bool operator>(const AscendingIterator &other)const;
                bool operator<(const AscendingIterator &other)const;
        
        };

        class SideCrossIterator
        {
        private:
            int* current;
            const MagicalContainer& container;        
        public:
            SideCrossIterator(const MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& iterator);
            ~SideCrossIterator(){}
            SideCrossIterator& operator=(const SideCrossIterator& other);
            SideCrossIterator begin();
            SideCrossIterator end();
            SideCrossIterator &operator++();
            int operator*();
            bool operator!=(const SideCrossIterator &other)const;
            bool operator==(const SideCrossIterator &other)const;
            bool operator>(const SideCrossIterator &other)const;
            bool operator<(const SideCrossIterator &other)const;
        };

        class PrimeIterator
        {
        private:
            int* current;
            const MagicalContainer& container;
        public:
            PrimeIterator(const MagicalContainer& container);
            PrimeIterator(const PrimeIterator& iterator);
            ~PrimeIterator(){}
            PrimeIterator& operator=(const PrimeIterator& other);
            PrimeIterator begin();
            PrimeIterator end();
            PrimeIterator &operator++();
            int operator*();
            bool operator!=(const PrimeIterator &other)const;
            bool operator==(const PrimeIterator &other)const;
            bool operator>(const PrimeIterator &other)const;
            bool operator<(const PrimeIterator &other)const;
        };
        
    };
    
}