#include <iostream>
using namespace std;


template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};


template <typename T>
class myStack : public AbstractStack<T>
{
private:
    T* arr;
    int maxsize;
    int topindex;

public:

   
    myStack(int size)
    {
        maxsize = size;
        arr = new T[maxsize];
        topindex = -1;
    }

   
    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack is Full\n";
            return;
        }

        topindex++;
        arr[topindex] = value;
    }

    
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return -1;
        }

        return arr[topindex--];
    }

    T top() const
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        return arr[topindex];
    }

  
    bool isEmpty() const
    {
        return (topindex == -1);
    }

    
    bool isFull() const
    {
        return (topindex == maxsize - 1);
    }

    
    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack elements: \n";

        for (int i = topindex; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    cout << "Enter Stack Size: ";
    cin >> size;

    myStack<int> s(size);

    int choice = 0;
    int value;
    

    while (choice != 7)
    {
        cout << "\n------ STACK MENU ------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top Element\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped Element: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top Element: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty\n";
            else
                cout << "Stack is NOT Empty\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full\n";
            else
                cout << "Stack is NOT Full\n";
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;
        }
  
    }

    return 0;
}