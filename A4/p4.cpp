/*
Design a STRING class, which will have the initialization facility similar to array
class. Provide support for
1. Assigning one object for another,
2. Two string can be concatenated using + operator,
3. Two strings can be compared using the relational operators.

*/
#include <cstring>

class String {
    private:
        int length;
        char* str;
    
        public:
        
        String(char* str) {
            this->str=str;
            // arr=(int *)malloc(size*default_value);
            str=new int[size];

            for (int i=0; i<size; i++) {
                arr[i]=default_value;
            }
        }

        String(const String& other) {
            size=other.size;
            arr=new int[size];
            
            for (int i=0; i<size; i++) {
                arr[i]=other.arr[i];
            }
        }

        String(int other[]) {
            size=sizeof(other)/sizeof(int);
            arr=new int[size];

            for (int i=0; i<size; i++) {
                arr[i]=other[i];
            }
        }

        String operator+(const String& other) const {
            if (size!=other.size) {
                cout << "Error: Array size dont match!\n";
                return *this;
            }
            String temp(size);

            for (int i=0; i<size; i++) {
                temp.arr[i]=arr[i]+other.arr[i];
            }
            return temp;
        }
};