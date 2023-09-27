class SLL{
	public:
		virtual void add(int) = 0;
//		virtual void remove(int num) = 0;
		virtual void removeAt(int pos) = 0;
		virtual void addAt(int data, int pos) = 0;
		virtual int get(int pos) = 0;
		virtual void display() = 0;
		virtual int getSum() = 0;
};
