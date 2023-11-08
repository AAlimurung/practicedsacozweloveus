class List {
    public:
        virtual void add(int) = 0;
        virtual void addLast(int) = 0;
        virtual void addFirst(int) = 0;
        virtual int removeFirst() = 0;
        virtual int getPos(int pos) = 0;
        virtual int getSize() = 0;
        virtual void print() = 0;
};