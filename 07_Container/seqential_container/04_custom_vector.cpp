#include <string>
class Vector 
{
private:
    /* data */
    std::string* data;
    int capacity;
    int length;

public:
    Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0){}

    void push_back(std::string s) {
        if (capacity <= length) {
            std::string* tmp = new std::string[capacity * 2];
            for (int i = 0; i < length; i++) {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    std::string operator[](int i) { return data[i]; }
    // remove 'x'th element
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i-1] = data[i];
        }
        length--;
    }

    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

