#include <iostream>

using namespace std;

class Time {
    private:
        int hour, minute, second;
        
    public:
        // int am_pm -> 0 = 24 hr format by default
        //              1 = 12 hr format
        Time(int hour, int minute, int second) {
            this->hour=hour;
            this->minute=minute;
            this->second=second;
        }
        
        // a = am, p=pm
        Time(int hour, int minute, int second, char am_pm) {
            this->hour=hour;
            this->minute=minute;
            this->second=second;

            if (am_pm=='p') {
                if (hour!=12)
                    this->hour=this->hour+12;
            } else if (am_pm=='a') {
                if (hour==12)
                    this->hour=0;
            }
        }

        // format = 0 -> 24hr frmt
        // format = 1 -> 12hr frmt
        void display(int format=0) {
            if (format==0) {
                cout << (this->hour<10?"0":"") << this->hour << ":" << (this->minute<10?"0":"") << this->minute << ":" << (this->second<10?"0":"") << this->second << "\n";
            } else if(format==1) {
                int hr12=this->hour%12;

                if (hr12==0)
                    hr12=12;

                cout << (hr12<10?"0":"") << hr12 << ":" << (this->minute<10?"0":"") << this->minute << ":" << (this->second<10?"0":"") << this->second;

                if (hour>=12)
                    cout << "pm\n";
                else
                    cout << "am\n";

            } else {
                cout << "Invalid format\n";
                return ;
            }
        }

        void addMinutes(int min) {
            int newMin=this->minute+min;
            this->minute=(newMin)%60;
            
            int newHr=(this->hour+newMin/60);
            this->hour=newHr%24;
        }
};

int main () {
    Time t(23,  23, 21);
    t.display();
    t.display(1);
    t.addMinutes(120);
    t.display();
    t.display(1);
}