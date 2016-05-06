class rat{

    private:
        int x,y;
        char sign;
        rat(int,int,bool);
        int getMaxCommondDivider(int, int);
        int getMaxCommondDividerRic(int, int);
    
    public: 
        rat(int,int);
        void print();
        void unpack(int&, int&);
        rat operator +(rat r);
        rat operator -(rat r);
        rat operator /(rat r);
        rat operator *(rat r);
};
