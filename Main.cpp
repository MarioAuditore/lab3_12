#include "Stack.h"
#include "Pair.h"

int main()
{
  using namespace std;
  int choice;
  cout << "Choose the action:\n 1 - Stack test for int,float and double\n 2 - Stack test for custom class (Pair)\n 0 - quit" << endl;
  cin >> choice;
  switch (choice)
  {
  case 0:
  {
    cout << "Quiting" << endl;
    break;
  }
  case 1:
  {
    int n_stack,del_stack;
    cout << "Enter amount of mumbers you want your int stack to store" << endl;
    cin >> n_stack;
    Stack<int> st_int(n_stack);

    for (int i = 0; i < n_stack; i++)//ввод
    {
      cout << "arr[" << i << "] = ";
      cin >> st_int;
    }

    cout << st_int << endl;//вывод

    if (st_int.isempty())//проверка на пустоту
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout<<"Stack is not empty"<<endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_int.del(del_stack)))//удаление элемента
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_int;//вывод измененного стека

    cout << "Current size of the stack is " << st_int.size() << ". Previous was " << n_stack << endl;//вывод размера

    cout << "Top of the stack is " << st_int.top_of() << endl;

    if (st_int.pop())
    {
      cout << "Current top of the stack is " << st_int.top_of() << endl;
    }

    cout << st_int;

//    st_int = st_int;

    Stack<int> st_type2_int(n_stack);//демонстрация присваивания
    st_type2_int = st_int;
    cout << st_type2_int;//вывод

     //______________________________________________________________________________________________________
    cout << "_________________________________________________________________________________________________________" << endl;
    //теперь double

    cout << "Enter amount of mumbers you want your double stack to store" << endl;
    cin >> n_stack;
    Stack<double> st_double(n_stack);

    for (int i = 0; i < n_stack; i++)//ввод
    {
      cout << "arr[" << i << "] = ";
      cin >> st_double;
    }

    cout << st_double << endl;//вывод

    if (st_double.isempty())//проверка на пустоту
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_double.del(del_stack)))//удаление элемента
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_double;//вывод измененного стека

    cout << "Current size of the stack is " << st_double.size() << ". Previous was " << n_stack << endl;//вывод размера

    cout << "Top of the stack is " << st_double.top_of() << endl;

    st_double.pop();
    cout << "Current top of the stack is " << st_double.top_of() << endl;

    Stack<double> st_type2_double(n_stack);//демонстрация присваивания
    st_type2_double = st_double;
    cout << st_type2_double;//вывод
    //______________________________________________________________________________________________________
    cout << "_________________________________________________________________________________________________________" << endl;
    //теперь float

    cout << "Enter amount of mumbers you want your float stack to store" << endl;
    cin >> n_stack;
    Stack<float> st_float(n_stack);

    for (int i = 0; i < n_stack; i++)//ввод
    {
      cout << "arr[" << i << "] = ";
      cin >> st_float;
    }

    cout << st_float << endl;//вывод

    if (st_float.isempty())//проверка на пустоту
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_float.del(del_stack)))//удаление элемента
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_float;//вывод измененного стека

    cout << "Current size of the stack is " << st_float.size() << ". Previous was " << n_stack << endl;//вывод размера

    cout << "Top of the stack is " << st_float.top_of() << endl;

    st_float.pop();
    cout << "Current top of the stack is " << st_float.top_of() << endl;

    Stack<float> st_type2_float(n_stack);//демонстрация присваивания
    st_type2_float = st_float;
    cout << st_type2_float;//вывод

    break;
  }
  case 2:
  {
    int n_stack, del_stack;
    cout << "Enter amount of mumbers you want your int stack to store" << endl;
    cin >> n_stack;
    Stack<Pair> st_pair(n_stack);

    for (int i = 0; i < n_stack; i++)//ввод
    {
      cout << "arr[" << i << "] = ";
      cin >> st_pair;
    }

    cout << st_pair << endl;//вывод

    if (st_pair.isempty())//проверка на пустоту
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_pair.del(del_stack)) and (st_pair.getMax()!=1))//удаление элемента
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_pair;//вывод измененного стека

    cout << "Current size of the stack is " << st_pair.size() << ". Previous was " << n_stack << endl;//вывод размера

    cout << "Top of the stack is " << st_pair.top_of() << endl;

    if (st_pair.pop())
    {
      cout << "Current top of the stack is " << st_pair.top_of() << endl;
    }

    cout << st_pair;

     
    Stack<Pair> st_type2_pair(n_stack);//демонстрация присваивания
    st_type2_pair = st_pair;
    cout << st_type2_pair;//вывод
  }
  }
  
  return 0;
}