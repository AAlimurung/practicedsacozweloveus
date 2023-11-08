class Queue{
    public:
        virtual void enQ(int) = 0;
        virtual int deQ() = 0;
        virtual int front() = 0; //first
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
};