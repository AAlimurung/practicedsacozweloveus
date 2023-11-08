class List {
    public:
        virtual void add(int) = 0;
        virtual void addTail(int) = 0;
        virtual void addHead(int) = 0;
        virtual void removeHead() = 0;
        virtual void removeTail() = 0;
        virtual int getPos(int pos) = 0;
        virtual int getSize() = 0;
        virtual void print() = 0;
};