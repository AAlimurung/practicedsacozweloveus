//LIST2.H
class LL{
	public:
		virtual void plus(int) = 0;
//		virtual void addLast(int) = 0; //sir's method
//		virtual void remove(int num) = 0; //sir's method
		virtual void removeAt(int pos) = 0;
		virtual void addAt(int data, int pos) = 0;
//		virtual int get(int pos) = 0; //sir's method
		virtual void display() = 0;
		virtual int getSum() = 0;
};

