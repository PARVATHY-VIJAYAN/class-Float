#include<iostream>

using namespace std;

class Float{
    float f;
public:
    Float():f(0.0f){}//default constructors
    Float(float num):f(num){}//Single parameterized constructor
    Float(Float &obj):f(obj.f){}//copy constructors

    float getFloat()
    {
        return f;
    }
    void setFloat(int fl)
    {
        f=fl;
    }
    //Overloading operators
    Float operator + (Float obj)
    {
        Float temp;
        temp.f=obj.f+f;
        return temp;
    }
    Float operator- (Float obj)
    {
        Float temp;
        temp.f=f-obj.f;
        return temp;
    }
    Float operator* (Float obj)
    {
        Float temp;
        temp.f=obj.f*f;
        return temp;
    }
    Float operator/ (Float obj)
    {
        Float temp;
        temp.f=f/obj.f;
        return temp;
    }

    Float operator++ ()//pre increment
    {
        f++;
        return *this;
    }
    bool operator < (Float obj)
    {
        if(obj.f>f)
            return true;
        else
            return false;
    }
    float& operator[] (int index)
    {
        if(index==0)
            return f;
    }
};

//extraction and insertion operator overloading
ostream &operator <<(ostream &os,Float obj)
{
    os<<obj.getFloat();
    return os;
}
istream &operator>>(istream &is,Float &obj)
{
    int num;
    is>>num;
    obj.setFloat(num);
    return is;
}
int main()
{
    Float f1; //creates a float that has  0.0f as its value
    cout<<"f1 : "<<f1<<endl;
    Float f2(1.5f);  //creates a float that has 1.5f as its value
    cout<<"f2 : "<<f2<<endl;
    Float f3(f2); //creates f3 that has same value as f2
    cout<<"f3 : "<<f3<<endl;
    Float f4;
    cout<<"enter any value : ";
    cin >> f4;  //read into float object
    f4 = ++f3  -  f2;  //subtraction of two float objects and returns a float object(increment operator is operated on f3).
    cout<<"f4 : "<<f4<<endl;
    if(f1 < f2)
    {
        cout<<"f1 < f2 : True"<<endl;
    }
    f1[0]=5.5f; //assign a float value
    cout<<"f1 : "<<f1;
}
