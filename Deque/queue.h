class Queue{
    public:
        virtual void addFirst(int) = 0;
        virtual void addLast(int) = 0;
        virtual void removeFirst() = 0;
        virtual void removeLast() = 0;
        virtual int front() = 0; //first
        virtual int rear() = 0; //last element
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
};