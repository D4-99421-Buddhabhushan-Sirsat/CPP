#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int seconds;

public:
    Time() : hour(0), minute(0), seconds(0) {}

    Time(int h, int m, int s) : hour(h), minute(m), seconds(s) {}

    int getHour() const
    {
        return hour;
    }

    int getMinute() const
    {
        return minute;
    }

    int getSeconds() const
    {
        return seconds;
    }

    void setHour(int h)
    {
        this->hour = h;
    }

    void setMinute(int m)
    {
        this->minute = m;
    }

    void setSeconds(int s)
    {
        this->seconds = s;
    }

    void printTime() const
    {
        cout << setfill('0') << setw(2) << this->hour << ":"
             << setw(2) << this->minute << ":"
             << setw(2) << this->seconds << setfill(' ') << endl;
    }
};

int main()
{
    int size;
    cout << "Enter maximum number of Time objects: ";
    cin >> size;

    Time* times = new Time[size];
    int count = 0;
    int choice;

    do
    {
        cout << "\n1. Add Time\n";
        cout << "2. Display All Time\n";
        cout << "3. Display only hours\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count == size)
            {
                cout << "Array is full.\n";
                break;
            }

            int h, m, s;
            cout << "Enter hour, minute and seconds: ";
            cin >> h >> m >> s;

            times[count].setHour(h);
            times[count].setMinute(m);
            times[count].setSeconds(s);
            ++count;
            cout << "Time added successfully.\n";
            break;

        case 2:
            if (count == 0)
            {
                cout << "No time objects available.\n";
                break;
            }

            for (int i = 0; i < count; ++i)
            {
                cout << "Time " << i + 1 << ": ";
                times[i].printTime();
            }
            break;

        case 3:
            if (count == 0)
            {
                cout << "No time objects available.\n";
                break;
            }

            cout << "Hours: ";
            for (int i = 0; i < count; ++i)
            {
                cout << times[i].getHour() << " ";
            }
            cout << endl;
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    delete[] times;
    return 0;
}