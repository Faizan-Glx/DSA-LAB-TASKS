#include <iostream>
using namespace std;

class stack
{
private:
    string arr[100];
    int topindex;

public:

    stack()
    {
        topindex = -1;
    }

    bool isempty()
    {
        return (topindex == -1);
    }

    bool isfull()
    {
        return (topindex == 99);
    }

    void push(string val)
    {
        if (isfull())
            return;

        topindex++;
        arr[topindex] = val;
    }

    string pop()
    {
        if (isempty())
            return "";

        string temp = arr[topindex];
        topindex--;
        return temp;
    }

    void clear()
    {
        topindex = -1;
    }
};

int main()
{
    stack undostack;
    stack redostack;

    string text = "";
    int choice;
    char ch;

    while (true)
    {
        cout << endl;
        cout << "1. type character" << endl;
        cout << "2. delete character" << endl;
        cout << "3. undo" << endl;
        cout << "4. redo" << endl;
        cout << "5. show text" << endl;
        cout << "6. exit" << endl;

        cout << "enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "enter character: ";
            cin >> ch;

            text += ch;

            undostack.push(string(1, ch));
            redostack.clear();

            break;

        case 2:

            if (text.length() == 0)
            {
                cout << "nothing to delete" << endl;
                break;
            }

            ch = text[text.length() - 1];
            text.pop_back();

            undostack.push("D" + string(1, ch));
            redostack.clear();

            break;

        case 3:

            if (undostack.isempty())
            {
                cout << "nothing to undo" << endl;
                break;
            }

            {
                string action = undostack.pop();

                if (action[0] == 'D')
                {
                    text += action[1];
                    redostack.push(action);
                }
                else
                {
                    text.pop_back();
                    redostack.push(action);
                }
            }

            break;

        case 4:

            if (redostack.isempty())
            {
                cout << "nothing to redo" << endl;
                break;
            }

            {
                string action = redostack.pop();

                if (action[0] == 'D')
                {
                    text.pop_back();
                    undostack.push(action);
                }
                else
                {
                    text += action[0];
                    undostack.push(action);
                }
            }

            break;

        case 5:

            cout << "current text: " << text << endl;

            break;

        case 6:

            return 0;
        }
    }
}