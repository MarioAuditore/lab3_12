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

    for (int i = 0; i < n_stack; i++)//����
    {
      cout << "arr[" << i << "] = ";
      cin >> st_int;
    }

    cout << st_int << endl;//�����

    if (st_int.isempty())//�������� �� �������
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout<<"Stack is not empty"<<endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_int.del(del_stack)))//�������� ��������
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_int;//����� ����������� �����

    cout << "Current size of the stack is " << st_int.size() << ". Previous was " << n_stack << endl;//����� �������

    cout << "Top of the stack is " << st_int.top_of() << endl;

    if (st_int.pop())
    {
      cout << "Current top of the stack is " << st_int.top_of() << endl;
    }

    cout << st_int;

//    st_int = st_int;

    Stack<int> st_type2_int(n_stack);//������������ ������������
    st_type2_int = st_int;
    cout << st_type2_int;//�����

     //______________________________________________________________________________________________________
    cout << "_________________________________________________________________________________________________________" << endl;
    //������ double

    cout << "Enter amount of mumbers you want your double stack to store" << endl;
    cin >> n_stack;
    Stack<double> st_double(n_stack);

    for (int i = 0; i < n_stack; i++)//����
    {
      cout << "arr[" << i << "] = ";
      cin >> st_double;
    }

    cout << st_double << endl;//�����

    if (st_double.isempty())//�������� �� �������
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_double.del(del_stack)))//�������� ��������
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_double;//����� ����������� �����

    cout << "Current size of the stack is " << st_double.size() << ". Previous was " << n_stack << endl;//����� �������

    cout << "Top of the stack is " << st_double.top_of() << endl;

    st_double.pop();
    cout << "Current top of the stack is " << st_double.top_of() << endl;

    Stack<double> st_type2_double(n_stack);//������������ ������������
    st_type2_double = st_double;
    cout << st_type2_double;//�����
    //______________________________________________________________________________________________________
    cout << "_________________________________________________________________________________________________________" << endl;
    //������ float

    cout << "Enter amount of mumbers you want your float stack to store" << endl;
    cin >> n_stack;
    Stack<float> st_float(n_stack);

    for (int i = 0; i < n_stack; i++)//����
    {
      cout << "arr[" << i << "] = ";
      cin >> st_float;
    }

    cout << st_float << endl;//�����

    if (st_float.isempty())//�������� �� �������
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_float.del(del_stack)))//�������� ��������
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_float;//����� ����������� �����

    cout << "Current size of the stack is " << st_float.size() << ". Previous was " << n_stack << endl;//����� �������

    cout << "Top of the stack is " << st_float.top_of() << endl;

    st_float.pop();
    cout << "Current top of the stack is " << st_float.top_of() << endl;

    Stack<float> st_type2_float(n_stack);//������������ ������������
    st_type2_float = st_float;
    cout << st_type2_float;//�����

    break;
  }
  case 2:
  {
    int n_stack, del_stack;
    cout << "Enter amount of mumbers you want your int stack to store" << endl;
    cin >> n_stack;
    Stack<Pair> st_pair(n_stack);

    for (int i = 0; i < n_stack; i++)//����
    {
      cout << "arr[" << i << "] = ";
      cin >> st_pair;
    }

    cout << st_pair << endl;//�����

    if (st_pair.isempty())//�������� �� �������
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      cout << "Stack is not empty" << endl;
    }

    cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
    cin >> del_stack;
    while (!(st_pair.del(del_stack)) and (st_pair.getMax()!=1))//�������� ��������
    {
      cout << "Enter number of element you want to delete n <= " << n_stack - 1 << endl;
      cin >> del_stack;
    };
    cout << st_pair;//����� ����������� �����

    cout << "Current size of the stack is " << st_pair.size() << ". Previous was " << n_stack << endl;//����� �������

    cout << "Top of the stack is " << st_pair.top_of() << endl;

    if (st_pair.pop())
    {
      cout << "Current top of the stack is " << st_pair.top_of() << endl;
    }

    cout << st_pair;

     
    Stack<Pair> st_type2_pair(n_stack);//������������ ������������
    st_type2_pair = st_pair;
    cout << st_type2_pair;//�����
  }
  }
  
  return 0;
}