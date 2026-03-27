#include <iostream>
using namespace std;

class myCarStack
{
private:
    string arr[8];
    int topindex;

public:

    myCarStack()
    {
        topindex = -1;
    }

    bool isempty()
    {
        return (topindex == -1);
    }

    bool isfull()
    {
        return (topindex == 7);
    }

    void push(string car)
    {
        if (isfull())
        {
            cout << "parking lot is full" << endl;
            return;
        }

        topindex++;
        arr[topindex] = car;
        cout << "car parked: " << car << endl;
    }

    string pop()
    {
        if (isempty())
        {
            cout << "parking lot empty" << endl;
            return "";
        }

        string temp = arr[topindex];
        topindex--;
        return temp;
    }

    void display()
    {
        if (isempty())
        {
            cout << "no cars parked" << endl;
            return;
        }

        cout << "cars currently parked:" << endl;

        for (int i = topindex; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    int totalcars()
    {
        return topindex + 1;
    }

    bool searchcar(string car)
    {
        for (int i = 0; i <= topindex; i++)
        {
            if (arr[i] == car)
                return true;
        }
        return false;
    }

    void removecar(string car)
    {
        if (isempty())
        {
            cout << "parking lot empty" << endl;
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isempty())
        {
            string current = pop();

            if (current == car)
            {
                cout << "car removed: " << car << endl;
                found = true;
                break;
            }
            else
            {
                temp.push(current);
            }
        }

        if (!found)
        {
            cout << "car not found in parking lot" << endl;
        }

        while (!temp.isempty())
        {
            push(temp.pop());
        }
    }
};

int main()
{
    myCarStack parking;
    int choice = 0;
    string car;

    while (choice != 6)
    {
        cout << endl;
        cout << "1. park new car" << endl;
        cout << "2. remove car by number" << endl;
        cout << "3. view parked cars" << endl;
        cout << "4. total cars parked" << endl;
        cout << "5. search car" << endl;
        cout << "6. exit" << endl;

        cout << "enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter car number: ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "enter car number to remove: ";
            cin >> car;
            parking.removecar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "total cars parked: " << parking.totalcars() << endl;
            break;

        case 5:
            cout << "enter car number to search: ";
            cin >> car;

            if (parking.searchcar(car))
                cout << "car found in parking lot" << endl;
            else
                cout << "car not found" << endl;

            break;

        case 6:
            cout << "program ended" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }
    }

    return 0;
}