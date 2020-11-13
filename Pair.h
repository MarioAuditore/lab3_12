#pragma once
#include <iostream>
using namespace std;
class Pair
{
private:

  int a;
  double b;

public:

  explicit Pair(int int1, double double2){
    cout << "Creating a pair "<< int1 << ":"<< double2 << endl; 
    SetData(int1,double2);
  }//����������� � �����������

  Pair() { SetData(0, 0); }//����������� �� ���������
  ~Pair() { cout << "Deleting pair"<<endl; }
  void print()//����� ���� � ����������
  {
    cout << a << ":" << b << endl;
  }

  void SetData(int a_in, double b_in)
  {
    a = a_in;
    b = b_in;
  }

  const Pair& operator=(const Pair& object)//�������� ������������
  {
    if (this == &object)
    {
      return *this;
    }
    a = object.a;
    b = object.b;
    return *this;
  }

  friend istream& operator>> (istream& is, Pair& object)
  {
    is >> object.a >> object.b;
    return is;
  }
  friend ostream& operator<< (ostream& os, Pair& object)
  {
    os << "Pair of int and double - " << object.a << ":" << object.b << endl;
    return os;
  }
};
