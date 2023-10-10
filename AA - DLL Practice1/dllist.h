class DLL{
	public:
		virtual void addH(int) = 0;
		virtual void addT(int) = 0;
		virtual void addAt(int num, int pos) = 0;
		virtual void removeH() = 0;
		virtual void removeT() = 0;
		virtual int remove(int num) = 0;
		virtual int removeAt(int pos) = 0;
	//	virtual int removeAll(int pos) = 0;
	//	virtual int get(int pos) = 0;
	//	virtual int retain(int num) = 0;
		virtual int corner(int a, int b) = 0; 
//		virtual void reverse() = 0;
		virtual void print() = 0;
};
