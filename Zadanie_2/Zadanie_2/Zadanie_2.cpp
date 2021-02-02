#include <iostream>

using namespace std;

class Task
{
    unsigned int r, s;

public:

    void SetValues()
    {
        try
        {
            cin >> r >> s;

            if (r < 1 || s < 0 || r > 8 || s >(4 * r))
                throw 1;
        }
        catch (int x) {
            cout << "Incorrect input data!";
            exit(0);
        }
    }

    int GetValues()
    {
        if (r > s)
        {
            int x = r - s;
            int sum = 1;

            for (int i = 0; i < x; i++)
                sum *= 2;

            x = sum; sum = 1;

            for (int i = 0; i < s; i++)
                sum *= 4;

            return (x * sum);
        }
        else if (r < s)
        {
            int x = s / r;
            int m = s % r;
            int sum = 1;

            for (int i = 0; i < r; i++, m--)
            {
                if (m != 0) sum *= (((x + 1) * 2) + 2);
                else    sum *= ((x * 2) + 2);
            }

            return sum;
        }
        else if (r == s)
        {
            int sum = 1;

            for (int i = 0; i < r; i++)
                sum *= 4;

            return sum;
        }
    }
};


int main()
{
    Task* task = new Task;
    task->SetValues();

    cout << task->GetValues();

    delete task;

};

