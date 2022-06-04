// eg. of exception handling
#include <iostream>
using namespace std;

int main()
{
    int x = -1;

    cout << "Before try \n";
    try
    {
        cout << "Inside try \n";
        if (x < 0)
        {
            throw x;
            cout << "After throw (Never executed) \n";
        }
    }
    catch (int x)
    {
        cout << "Exception Caught \n";
    }

    cout << "After catch (Will be executed) \n";
    return 0;
}

// function
#include <iostream>
using namespace std;
void sum(int x, int y)
{
    int total;
    total = x + y;
    cout << total;
}
int main()
{
    int x, y;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    sum(x, y);
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter a number: ";
    cin >> y;
    cout << "Enter a number: ";
    cin >> z;
    if (x > y && x > z)
    {
        cout << "The largest is: " << x;
    }
    else if (y > x && y > z)
    {
        cout << "The largest is: " << y;
    }
    else
    {
        cout << "The largest is: " << z;
    }
    return 0;
}

// public access
#include <iostream>
using namespace std;
class Circle
{
public:
    float radius;
    float area_circle()
    {
        return 3.14 * radius * radius;
    }
};
int main()
{
    Circle obj;
    cout << "Enter radius: ";
    cin >> obj.radius;
    cout << "Area is: " << obj.area_circle();
    return 0;
}

// private
#include <iostream>
using namespace std;
class Circle
{
private:
    float radius;

public:
    void area_circle(float r)
    {
        radius = r;
        float area = 3.14 * r * r;
        cout << "Area is: " << area;
    }
};
int main()
{
    Circle obj;
    obj.area_circle(10.10);
    return 0;
}

// protected
#include <iostream>
using namespace std;
class Circle
{
protected:
    float radius;
};
class circle : public Circle
{
public:
    void Radius(float r)
    {
        radius = r;
    }
    void area_circle()
    {
        cout << "Area is: " << (3.14 * radius * radius);
    }
};
int main()
{
    circle obj;
    obj.Radius(10.10);
    obj.area_circle();
    return 0;
}

// copy constructor
#include <iostream>
using namespace std;
class A
{
    int x, y;

public:
    int sum;
    A(int a, int b) // parameterized constructor.
    {
        x = a;
        y = b;
    }
    A(A &i) // copy constructor
    {
        x = (i.x) * 2;
        y = (i.y) * 2;
        sum = i.x + i.y;
    }
};
int main()
{
    A a1(10, 20); // Calling the parameterized constructor.
    A a2(a1);     //  Calling the copy constructor.
    cout << a2.sum;
    return 0;
}

// multiple inheritance
#include <iostream>
using namespace std;
class A
{
    //  members of A
public:
    A(int x) { cout << "A::A(int " << x * 2 << ") called" << endl; }
};
class B
{
    //  members of B
public:
    B(int x)
    {
        cout << "B::B(int " << x * 3 << ") called" << endl;
    }
};
class C
{
    //  members of C
public:
    C(int x)
    {
        cout << "C::C(int " << x * 4 << ") called" << endl;
    }
};
class D : public A, public B, public C
{
public:
    D(int x) : C(x), B(x), A(x)
    {
        cout << "D::D(int " << x << ") called" << endl;
    }
};
int main()
{
    D D1(10);
}

#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "A's constructor called" << endl; }
};
class B
{
public:
    B() { cout << "B's constructor called" << endl; }
};
class C : public B, public A // Note the order
{
public:
    C() { cout << "C's constructor called" << endl; }
};
int main()
{
    C c;
    return 0;
}

// single level inheritance
#include <iostream>
using namespace std;
class parent
{
public:
    int x;
};
class child : public parent
{
public:
    int y;
};
int main()
{
    child obj;
    cin >> obj.x;
    cin >> obj.y;
    cout << obj.y << " " << obj.x;
}

#include <iostream>
using namespace std;
class animal
{
public:
    void eat()
    {
        cout << "I can eat." << endl;
    }
    void sleep()
    {
        cout << "I can sleep." << endl;
    }
};
class dog : public animal
{
public:
    void bark()
    {
        cout << "I can bark." << endl;
    }
};
int main()
{
    dog d1;
    d1.eat();
    d1.sleep();
    d1.bark();
    return 0;
}

// inherit protected members by SLI
#include <iostream>
#include <string>
using namespace std;
class animal
{
private:
    string colour;

protected:
    string typ;

public:
    void eat()
    {
        cout << "I can eat." << endl;
    }
    void sleep()
    {
        cout << "I can sleep." << endl;
    }
    string setClr(string clr)
    {
        colour = clr;
        return colour;
    }
};
class dog : public animal
{
public:
    void settyp(string tp)
    {
        typ = tp;
    }
    void display(string d)
    {
        cout << "i am a " << typ << endl;
        cout << "my colour is " << d << endl;
    }
    void bark()
    {
        cout << "I can bark." << endl;
    }
};
int main()
{
    dog d1;
    d1.settyp("mammal");
    d1.display(d1.setClr("black"));
    d1.eat();
    d1.bark();
    d1.sleep();
    return 0;
}

// multilevel inheritance
#include <iostream>
using namespace std;
class animal
{
public:
    void eat()
    {
        cout << "eating...." << endl;
    }
};
class dog : public animal
{
public:
    void bark()
    {
        cout << "barking...." << endl;
    }
};
class BabyDog : public dog
{
public:
    void weep()
    {
        cout << "weeping...." << endl;
    }
};
int main()
{
    BabyDog d1;
    d1.eat();
    d1.weep();
    d1.bark();
    return 0;
}

// hybrid inheritance: single + multi level
#include <iostream>
using namespace std;
class Sport
{
public:
    Sport()
    {
        cout << "This plays a Sport called Football" << endl;
    }
};
class Team : public Sport
{
public:
    Team()
    {
        cout << "This plays for a Team called Man United" << endl;
    }
};
class Player
{
public:
    Player()
    {
        cout << "This is a Player" << endl;
    }
};
class Ronaldo : public Team, public Player
{
public:
    Ronaldo()
    {
        cout << "Ronaldo is the player" << endl;
    }
};
int main()
{
    Ronaldo r;
    return 0;
}

// Hierarchical inheritance
#include <iostream>
using namespace std;
class A // Base class
{
public:
    int x, y;      // data members
    void getdata() // to input x and y
    {
        cout << "Enter value of x and y: " << endl;
        cin >> x >> y;
    }
};
class B : public A // B is derived from class base
{
public:
    void product()
    {
        cout << "Product= " << x * y << endl; // Perform product
    }
};
class C : public A // C is also derived from class base
{
public:
    void sum()
    {
        cout << "Sum= " << x + y << endl; // Perform sum
    }
};
int main()
{
    B obj1;         // object of derived class B
    C obj2;         // object of derived class C
    obj1.getdata(); // input x and y
    obj1.product();
    obj2.getdata();
    obj2.sum();
    return 0;
}

// print complex nos
#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void setdata(complex ob1, complex ob2)
    {
        a = ob1.a + ob2.a;
        b = ob1.b + ob2.b;
    }
    void print()
    {
        cout << "Complex no. is: " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    complex c1, c2;
    c1.setdata(1, 2);
    c2.setdata(3, 4);
    c1.print();
    c2.print();
    return 0;
}

// friend func
#include <iostream>
using namespace std;
class dist
{
private:
    int m;                // itna use nahi hua friend func ka coz class ke
    friend int add(dist); // andar hi likha hai..vaise aur bhi methods hai
public:
    dist() : m(10) {}
};
int add(dist d)
{
    d.m += 10;
    return d.m;
}
int main()
{
    dist D;
    cout << "Distance is: " << add(D);
    return 0;
}

#include <iostream>
using namespace std;
class B;
class A
{
private:
    int aa;
    friend int add(A, B);

public:
    A() : aa(45) {}
};
class B
{
private:
    int bb;
    friend int add(A, B);

public:
    B() : bb(55) {}
};
int add(A obja, B objb)
{
    return (obja.aa + objb.bb);
}
int main()
{
    A objA;
    B objB;
    cout << add(objA, objB);
    return 0;
}

// operator overloading
#include <iostream>
using namespace std;
class count
{
private:
    int value;

public:
    count() : value(10) {}
    void operator++()
    {
        ++value;
    }
    void operator++(int)
    {
        value++;
    }
    void display()
    {
        cout << value << endl;
    }
};
int main()
{
    count c1;
    c1.display(); // 10
    c1++;
    c1.display(); // 11
    ++c1;
    c1.display(); // 12
    return 0;
}

// simple func overriding
#include <iostream>
using namespace std;
class base
{
public:
    void print()
    {
        cout << "Base" << endl;
    }
};
class derived : public base
{
public:
    void print()
    {
        cout << "Derived";
    }
};
int main()
{
    // base b1;
    derived d1, d2;
    // b1.print();
    d1.print();
    d2.base::print(); // for calling func in base class
    return 0;
}

// simple virtual func eg
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void print()
    {
        cout << "Base";
    }
};
class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived";
    }
};
int main()
{
    Derived d1;
    Base *b1 = &d1;
    b1->print();
    return 0;
}

// simple func template
#include <iostream>
using namespace std;
template <class T>
T add(T &a, T &b)
{
    T result = a + b;
    return result;
}
int main()
{
    int i = 2, j = 3;
    float m = 2.3, n = 1.2;
    cout << "Addition of i & j: " << add(i, j);
    cout << endl;
    cout << "Addition of m & n: " << add(m, n);
    return 0;
}

#include <iostream>
using namespace std;
template <class X>
void func(X a, X b)
{
    cout << "Sum: " << a + b << endl;
}
int main()
{
    func(20, 10);
    return 0;
}

// multiple parameter func template
#include <iostream>
using namespace std;
template <class X, class Y>
void func(X a, Y b)
{
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
}
int main()
{
    func(15, 12.5);
    return 0;
}

// overloading a func template
#include <iostream>
using namespace std;
template <class X>
void func(X a)
{
    cout << "Value of a: " << a << endl;
}
template <class X, class Y>
void func(X b, Y c)
{
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Sum: " << b + c << endl;
}
int main()
{
    func(10);
    func(20, 10.5);
    return 0;
}

// simple class template
#include <iostream>
using namespace std;
template <class T>
class Num
{
private:
    T num;

public:
    Num(T n) : num(n) {} // constructor
    T getnum()
    {
        return (num + 1);
    }
};
int main()
{
    Num<int> numberInt(7);
    Num<double> numberDouble(7.7);
    cout << "int num: " << numberInt.getnum() << endl;
    cout << "double num: " << numberDouble.getnum() << endl;
    return 0;
}

// multiple parameter class template
#include <iostream>
using namespace std;
template <class T1, class T2>
class A
{
    T1 a; // private data members
    T2 b;

public:
    A(T1 x, T2 y) // constructor
    {
        a = x;
        b = y;
    }
    void add() // member function
    {
        cout << "Values of a + b is : " << a + b << endl;
    }
};
int main()
{
    A<int, float> d(5, 6.5);
    d.add();
    return 0;
}

// calculator using class template
#include <iostream>
using namespace std;
template <class T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }
    void displayResult()
    {
        cout << "Numbers are: " << num1 << " and " << num2 << "." << endl;
        cout << "Addition is: " << add() << endl;
        cout << "Subtraction is: " << subtract() << endl;
        cout << "Product is: " << multiply() << endl;
        cout << "Division is: " << divide() << endl;
    }
    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
};
int main()
{
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);
    cout << "Int results:" << endl;
    intCalc.displayResult();
    cout << endl;
    cout << "Float results:" << endl;
    floatCalc.displayResult();
    return 0;
}

// STL vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers = {1, 100, 10, 70, 100};
    cout << "Numbers are: ";
    for (auto &num : numbers)
    {
        cout << num << ", ";
    }
    return 0;
}

// STL set
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> numbers = {1, 100, 10, 70, 100};
    cout << "Numbers are: ";
    for (auto &num : numbers)
    {
        cout << num << ", ";
    }
    return 0;
}

// STL stack
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> numbers;
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);
    cout << "Numbers are: ";
    while (!numbers.empty())
    {
        cout << numbers.top() << ", ";
        numbers.pop();
    }
    return 0;
}

// vectors
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> vector2{6, 7, 8, 9, 10};
    vector<int> vector3(5, 11);
    cout << "vector1: ";
    for (const int &i : vector1)
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "vector2: ";
    for (int i : vector2)
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "vector3: ";
    for (int i : vector3)
    {
        cout << i << ", ";
    }
    return 0;
}

// user made vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> V3(5, 0);
    int ValueToInsert;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value: ";
        cin >> ValueToInsert;
    }
    int Arr[5] = {0};
    cout << "Original Values: " << endl;
    for (int i = 0; i < 5; i++) // before
    {
        cout << Arr[i] << ", ";
    }
    for (int i = 0; i < 5; i++) // changing values
    {
        Arr[i] = i;
    }
    cout << endl;
    cout << "After: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << Arr[i] << ", ";
    }
    cout << endl;
    return 0;
}

// adding, accessing, changing & deleting elements in vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> num{1, 2, 3, 4, 5};
    cout << "Initial Vector: ";
    for (const int &i : num)
    {
        cout << i << " ";
    }
    num.push_back(6);
    num.push_back(7);
    num.at(1) = 3;
    num.pop_back();
    cout << endl;
    cout << "Updated Vector: ";
    for (const int &i : num)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "1st element: " << num.at(0);
    return 0;
}

// C++ program to illustrate the Modifiers in vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // Assign vector
  vector<int> v;

  // fill the array with 10 five times
  v.assign(5, 10);

  cout << "The vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // inserts 15 to the last position
  v.push_back(15);
  int n = v.size();
  cout << "\nThe last element is: " << v[n - 1];

  // check vector again
  cout << "\nThe vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // removes last element
  v.pop_back();

  // prints the vector
  cout << "\nThe vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // inserts 5 at the beginning
  v.insert(v.begin(), 5);

  cout << "\nThe first element is: " << v[0];

  // check vector again
  cout << "\nThe vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // removes the first element
  v.erase(v.begin());

  cout << "\nThe first element is: " << v[0];

  // inserts at the beginning
  v.emplace(v.begin(), 25);
  cout << "\nThe first element is: " << v[0];

  // Inserts 20 at the end
  v.emplace_back(20);
  n = v.size();
  cout << "\nThe last element is: " << v[n - 1];

  // check vector again
  cout << "\nThe vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // erases the vector
  v.clear();
  cout << "\nVector size after erase(): " << v.size();

  // check vector again
  cout << "\nThe vector elements are: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // two vector to perform swap
  vector<int> v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);

  cout << "\n\nVector 1: ";
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";

  cout << "\nVector 2: ";
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";

  // Swaps v1 and v2
  v1.swap(v2);

  cout << "\nAfter Swap \nVector 1: ";
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";

  cout << "\nVector 2: ";
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";
  return 0;
}

// C++ program to show the implementation of List
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
// function for printing the elements in a list
void showlist(list<int> g)
{
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); ++it)
    cout << '\t' << *it;
  cout << endl;
}
// Driver Code
int main()
{
  list<int> list1, list2;
  for (int i = 0; i < 5; ++i)
  {
    list1.push_back(i * 2);
    list2.push_front(i * 3);
  }
  cout << "\nList 1 (List1) is : ";
  showlist(list1);

  cout << "\nList 2 (List2) is : ";
  showlist(list2);

  cout << "\nList1.front() : " << list1.front() << endl;
  cout << "\nList1.back() : " << list1.back() << endl;

  cout << "\nList1.pop_front() : ";
  list1.pop_front();
  showlist(list1);

  cout << "\nList2.pop_back() : ";
  list2.pop_back();
  showlist(list2);

  cout << "\nList1.reverse() : ";
  list1.reverse();
  showlist(list1);

  cout << "\nList2.sort(): ";
  list2.sort();
  showlist(list2);

  cout << "\nBefore Swapping";
  cout << "\nList1 ::";
  showlist(list1);
  cout << "\nList2 ::";
  showlist(list2);

  list1.swap(list2);

  cout << "\nAfter Swapping";
  cout << "\nList1 ::";
  showlist(list1);
  cout << "\nList2 ::";
  showlist(list2);

  return 0;
}

// arr.at(i) - used to randomly access element, could also be used for displaing
// arr.front() - 1st element
// arr.last()
// arr.size()
// arr.max_size()
// ar.swap(ar1) - to swap 2 arrays

// CPP Program to demonstrate the implementation in Map
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
int main()
{
  // empty map container
  map<int, int> gquiz1;

  // insert elements in random order
  gquiz1.insert(pair<int, int>(1, 10));
  gquiz1.insert(pair<int, int>(2, 20));
  gquiz1.insert(pair<int, int>(3, 30));
  gquiz1.insert(pair<int, int>(4, 40));
  gquiz1.insert(pair<int, int>(5, 50));
  gquiz1.insert(pair<int, int>(6, 60));
  gquiz1.insert(pair<int, int>(7, 70));

  // printing map gquiz1
  map<int, int>::iterator itr;
  cout << "The map quiz1 is : " << endl;
  cout << "\tKEY\tELEMENT" << endl;
  for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;

  // assigning the elements from gquiz1 to gquiz2
  map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

  // print all elements of the map gquiz2
  cout << "The map quiz2 after assigning from quiz1 is : " << endl;
  cout << "\tKEY\tELEMENT\n";
  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;

  // remove all elements up to element with key=3 in quiz2
  cout << "quiz2 after removal of elements less than key=3 : " << endl;
  cout << "\tKEY\tELEMENT\n";
  gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); // erase function

  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;
  // remove all elements with key = 4
  int num;
  num = gquiz2.erase(4);
  cout << "quiz2.erase(4) : ";
  cout << num << " removed " << endl;
  cout << "\tKEY\tELEMENT\n";
  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << itr->second
         << '\n';
  }

  cout << endl;

  // lower bound and upper bound for map gquiz1 key = 5
  cout << "gquiz1.lower_bound(5) : "
       << "\tKEY = ";
  cout << gquiz1.lower_bound(5)->first << '\t';
  cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second << endl;

  cout << "gquiz1.upper_bound(5) : "
       << "\tKEY = ";
  cout << gquiz1.upper_bound(5)->first << '\t';
  cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second << endl;

  return 0;
}


// iomanip
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << setw(7) << "A" << setw(44) << "B" << endl;
    cout << setw(7) << "a" << setw(44) << "b" << endl;
    cout << setw(7) << "c" << setw(44) << "d" << endl;
    cout << setw(52) << setfill('*') << 1 << endl;
    float x = 0.7;
    cout << fixed << setprecision(5) << x << endl;
    cout << scientific << x << endl;
    return 0;
}

// string
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    istringstream str("Hello");
    string line;
    getline(str >> ws, line);
    cout << line << endl;
    cout << "World" << flush << endl; // by flush we
    cout << "abc";                    // clear out the previous string
    return 0;
}

// setbase
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n = 100;
    cout << "Hexadecimal: " << hex << n << endl;
    cout << "Octal: " << oct << n << endl;
    // cout << "Setbase (user): " << setbase(3) << n << endl;
    cout << "Setbase (user): " << setbase(16) << n << endl;
    return 0;
}

// bitwise op overloading
#include <iostream>
using namespace std;
class Dist
{
private:
    int ft, inch;

public:
    Dist()
    {
        ft = 0;
        inch = 0;
    }
    Dist(int f, int i)
    {
        ft = f;
        inch = i;
    }
    friend ostream &operator<<(ostream &output, const Dist &D)
    {
        output << "F: " << D.ft << " - "
               << "I: " << D.inch;
        return output;
    }
    friend istream &operator>>(istream &input, Dist &D)
    {
        input >> D.ft >> D.inch;
        return input;
    }
};
int main()
{
    Dist D1(11, 10), D2(5, 15), D3;
    cout << "Enter value of object: " << endl;
    cin >> D3;
    cout << "D1" << D1 << endl;
    cout << "D2" << D2 << endl;
    cout << "D3" << D3 << endl;
    return 0;
}

// simple file handling code
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char text[200];
    fstream f;
    f.open("XYZ.txt", ios::out | ios::in);
    cout << "Write text to be written: ";
    cin.getline(text, sizeof(text));
    f << text << endl;
    f >> text;
    cout << text << endl;
    f.close();
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream m;
    char name[30];
    int age;
    cout << "Name: ";
    cin.get(name, 30);
    cout << "Age: ";
    cin >> age;
    m.open("XYZ.txt", ios::out);
    if (m)
    {
        m << name << endl;
        m << age << endl;
        cout << "Data stored." << endl;
        cout << "You are " << name << " age " << age << endl;
    }
    else
    {
        cout << "Error";
    }
    m.close();
    return 0;
}

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "Time is a great teacher,"
                 "but unfortunately it kills all its pupils.Berlioz";
    ofstream outfile("student.txt");     // create file for output
    for (int j = 0; j < str.size(); j++) // for each character,
        outfile.put(str[j]);             // write it to file
    cout << "File written";
    return 0;
}

// emp data binary
#include <iostream>
#include <fstream>
#define FILE_NAME "emp.dat"
using namespace std;
class Employee
{
private:
    int empID;
    char empName[100];
    char designation[100];
    int ddj, mmj, yyj;
    int ddb, mmb, yyb;

public:
    void readEmployee()
    {
        cout << "EMPLOYEE DETAILS" << endl;
        cout << "ENTER EMPLOYEE ID : ";
        cin >> empID;
        cin.ignore(1);
        cout << "ENTER  NAME OF THE EMPLOYEE : ";
        cin.getline(empName, 100);

        cout << "ENTER DESIGNATION : ";
        cin.getline(designation, 100);

        cout << "ENTER DATE OF JOIN:" << endl;
        cout << "DATE : ";
        cin >> ddj;
        cout << "MONTH: ";
        cin >> mmj;
        cout << "YEAR : ";
        cin >> yyj;

        cout << "ENTER DATE OF BIRTH:" << endl;
        cout << "DATE : ";
        cin >> ddb;
        cout << "MONTH: ";
        cin >> mmb;
        cout << "YEAR : ";
        cin >> yyb;
    }
    void displayEmployee()
    {
        cout << "EMPLOYEE ID: " << empID << endl
             << "EMPLOYEE NAME: " << empName << endl
             << "DESIGNATION: " << designation << endl
             << "DATE OF JOIN: " << ddj << "/" << mmj << "/" << yyj << endl
             << "DATE OF BIRTH: " << ddb << "/" << mmb << "/" << yyb << endl;
    }
};
int main()
{

    Employee emp;

    emp.readEmployee();

    fstream file;
    file.open(FILE_NAME, ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in creating file...\n";
        return -1;
    }

    file.write((char *)&emp, sizeof(emp));
    file.close();
    cout << "Date saved into file the file.\n";

    file.open(FILE_NAME, ios::in | ios::binary);
    if (!file)
    {
        cout << "Error in opening file...\n";
        return -1;
    }

    if (file.read((char *)&emp, sizeof(emp)))
    {
        cout << endl
             << endl;
        cout << "Data extracted from file..\n";

        emp.displayEmployee();
    }
    else
    {
        cout << "Error in reading data from file...\n";
        return -1;
    }

    file.close();
    return 0;
}