#include "rat.hpp"
#include <iostream>
#include <cmath> 

using namespace std;
rat::rat(int x, int y){
    *this = rat(x,y,false);
}

rat::rat(int x, int y, bool doUnpacking){
    if(doUnpacking){
        // do unpacking
        int mcd = getMaxCommondDivider(x, y);
        while(mcd != 1){
            x = x/mcd;
            y = y/mcd;
            mcd = getMaxCommondDivider(x, y);
        }
    }
    this->x=abs(x);
    this->y=abs(y);
    
    if (x<0 && y<0 
        || x>0 && y>0)
        sign = ' ';
    else
        sign = '-';
}

void rat::print(){
    cout << sign << x << "/" << y << endl;
}

void rat::unpack(int& n, int& d){
    int mcd = getMaxCommondDivider(this->x, this->y);
    n = this->x/mcd;
    d = this->y/mcd;
}


int rat::getMaxCommondDivider(int x, int y){
    if(x > y)
        return getMaxCommondDividerRic(x,y);
    else
        return getMaxCommondDividerRic(y,x);
}

int rat::getMaxCommondDividerRic(int x, int y){
    if (y == 0)
        return x;
    return getMaxCommondDividerRic(y, x%y);
}

rat rat::operator +(rat r){
    int n=0, d=0;
    d = this->y*r.y;
    n = this->x*r.y + this->y*r.x;
   
    return rat(n, d, true);
}
rat rat::operator -(rat r){
    int n=0, d=0;
    d = this->y*r.y;
    n = this->x*r.y - this->y*r.x;
    return rat(n, d, true);
}
rat rat::operator *(rat r){
    int n=0, d=0;
    d = this->y * r.y;
    n = this->x * r.x;
    return rat(n, d, true);
}
rat rat::operator /(rat r){
    int n=0, d=0;
    n = this->x * r.y;
    d = this->y * r.x;
    return rat(n, d, true);
}

