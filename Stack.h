#pragma once
#include <iostream>
#include <typeinfo>//определяем тип переменной

template <class Type>
class Stack
{
private:
  Type* arr;    // ссылка на первый элемент массива
  int top; // индекс верхнего эелемента стека
  int max; //максимальный размер стека, задающийся пользователем
public:

  Stack()
  {
    std::cout << "Creating Stack of " << typeid(arr).name() << " with default settings" << std::endl;
    top = -1;
    max = 10;
    arr = new Type[10];// по умолчанию будет десять
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
    if (arr!=nullptr)//если не ноль
    {
      delete[]arr;
      arr = nullptr;
      std::cout << "Done deleting stack\n____________________________" << std::endl;
    }
  };

  bool isempty()
  {
    std::cout << "Checking if Stack is empty" << std::endl;
    return top == -1;//если индекс верхнего элемента ноль, то стек пуст
  };//проверка на пустоту

  int push(const Type& item)
  {
    if (top < max)
    {
      ++top;//теперь сверху другой элемент
      arr[top] = item;
      return 0;
    }
    else
      std::cout << "Stack is full - message from int Stack push " << std::endl;
    return 0;
  }; // добавление в стек

  bool del(int n)
  {
    if (n > max)
    {
      std::cout << "Stack is smaller than " << n << std::endl;
      return false;//удаления не произошло
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
        arr[i] = arr[i + 1];//делаем сдвиг
      }
    }
      --max; --top;//уменшаем массив
      Type* temp = new Type[max];//создаем массив на 1 элемент меньше
      for (int i = 0; i < max; i++)
      {
        temp[i] = arr[i];//запоминаем в новом массиве элементы
      }
      delete[] arr; //удаляем старый массив
      arr = temp;//переобозначаем
      temp = nullptr;//избавляемся от временного указателя
      return true;
  };  // удаление элемента из стека

  Type& top_of()
  {
    Type& temp = arr[top];
    return temp;
  };   //определение верхнего элемента

  int size() {//размер стека - это индекс верхнего элемента + 1
    return top + 1;
  };

  bool pop()
  {
    if (top > 0)
    {
      std::cout << "Now deleting top element of stack:" << arr[top] << std::endl;
      --max; --top;
      Type* temp = new Type[max];//создаем массив длины меньшей на один элемент, как бы realloc
      for (int i = 0; i < max; i++)
      {
        temp[i] = arr[i];
      }
      delete[] arr;//освобождаем старый массив
      arr = temp;//присваиваем укороченный массив
      temp = nullptr;//освобождаем указатель
      return true;
    }
    else
      std::cout << "Top is the only element left, quiting pop operation" << std::endl;
      return false;
  };//классическое удаление верхнего элемента

  const Stack<Type>& operator=(const Stack<Type>& object)
  {
    if (this == &object)
    {
      return *this;
    }
    delete[] arr;//удаляем старый массив
    max = object.max;
    arr = new Type[max];//выделяем память отдельно для нового массива, чтобы не зависеть от массива object
    for (int i = 0; i < max; i++)
    {
      ++top;
      arr[i] = object.arr[i];
    }
    top = object.top;
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& os, const Stack<Type>& object) //вывод
  {
    os << "Content of Stack:" << std::endl;
    for (int i = 0; i <= object.top; i++)
    {
      os << object.arr[i] << std::endl;
    }
    return os;
  };

  friend std::istream& operator >> (std::istream& is, Stack<Type>& object) {//ввод
    Type x;
    is >> x;
    object.push(x);
    return is;
  }
};//made by E.Sabitov
