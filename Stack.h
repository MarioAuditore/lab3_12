#pragma once
#include <iostream>
#include <typeinfo>//���������� ��� ����������

template <class Type>
class Stack
{
private:
  Type* arr;    // ������ �� ������ ������� �������
  int top; // ������ �������� ��������� �����
  int max; //������������ ������ �����, ���������� �������������
public:

  Stack()
  {
    std::cout << "Creating Stack of " << typeid(arr).name() << " with default settings" << std::endl;
    top = -1;
    max = 10;
    arr = new Type[10];// �� ��������� ����� ������
  };

  Stack(int n)
  {
    std::cout << "Creating Stack of " << typeid(arr).name() << " with " << n << " items" << std::endl;
    top = -1;
    arr = new Type[n];
    max = n;
  };

  int getMax()
  {
    return max;
  }

  ~Stack()
  { 
    std::cout << "Destructor of stack of " << typeid(arr).name() << " type began" << std::endl;
    std::cout << *this << std::endl;
    if (arr!=nullptr)//���� �� ����
    {
      delete[]arr;
      arr = nullptr;
      std::cout << "Done deleting stack\n____________________________" << std::endl;
    }
  };

  bool isempty()
  {
    std::cout << "Checking if Stack is empty" << std::endl;
    return top == -1;//���� ������ �������� �������� ����, �� ���� ����
  };//�������� �� �������

  int push(const Type& item)
  {
    if (top < max)
    {
      ++top;//������ ������ ������ �������
      arr[top] = item;
      return 0;
    }
    else
      std::cout << "Stack is full - message from int Stack push " << std::endl;
    return 0;
  }; // ���������� � ����

  bool del(int n)
  {
    if (n > max)
    {
      std::cout << "Stack is smaller than " << n << std::endl;
      return false;//�������� �� ���������
    }
    else {
      if ((max == 1) && (n == 0))
      {
        std::cout<<"It is the only element left, so it will be deleted by destructor" << std::endl;
        return false;
      }
    }
    std::cout << "Now deleting " << arr[n] << std::endl;
    for (int i = n; i <= max - 1; i++)
    {
      if (i != max - 1)
      {
        arr[i] = arr[i + 1];//������ �����
      }
    }
      --max; --top;//�������� ������
      Type* temp = new Type[max];//������� ������ �� 1 ������� ������
      for (int i = 0; i < max; i++)
      {
        temp[i] = arr[i];//���������� � ����� ������� ��������
      }
      delete[] arr; //������� ������ ������
      arr = temp;//��������������
      temp = nullptr;//����������� �� ���������� ���������
      return true;
  };  // �������� �������� �� �����

  Type& top_of()
  {
    Type& temp = arr[top];
    return temp;
  };   //����������� �������� ��������

  int size() {//������ ����� - ��� ������ �������� �������� + 1
    return top + 1;
  };

  bool pop()
  {
    if (top > 0)
    {
      std::cout << "Now deleting top element of stack:" << arr[top] << std::endl;
      --max; --top;
      Type* temp = new Type[max];//������� ������ ����� ������� �� ���� �������, ��� �� realloc
      for (int i = 0; i < max; i++)
      {
        temp[i] = arr[i];
      }
      delete[] arr;//����������� ������ ������
      arr = temp;//����������� ����������� ������
      temp = nullptr;//����������� ���������
      return true;
    }
    else
      std::cout << "Top is the only element left, quiting pop operation" << std::endl;
      return false;
  };//������������ �������� �������� ��������

  const Stack<Type>& operator=(const Stack<Type>& object)
  {
    if (this == &object)
    {
      return *this;
    }
    delete[] arr;//������� ������ ������
    max = object.max;
    arr = new Type[max];//�������� ������ �������� ��� ������ �������, ����� �� �������� �� ������� object
    for (int i = 0; i < max; i++)
    {
      ++top;
      arr[i] = object.arr[i];
    }
    top = object.top;
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& os, const Stack<Type>& object) //�����
  {
    os << "Content of Stack:" << std::endl;
    for (int i = 0; i <= object.top; i++)
    {
      os << object.arr[i] << std::endl;
    }
    return os;
  };

  friend std::istream& operator >> (std::istream& is, Stack<Type>& object) {//����
    Type x;
    is >> x;
    object.push(x);
    return is;
  }
};