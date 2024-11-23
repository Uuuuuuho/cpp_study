class Vector {
    char* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new char[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(char s) {
        if (capacity <= length) {
            char* tmp = new char[capacity * 2];
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

    // 임의의 위치의 원소를 접근한다.
    char operator[](int idx) { return data[idx]; }

    // x 번째 원소를 제거한다.
    void remove(int idx) {
        for(int i = idx; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if(data) {
            delete[] data;
        }
    }
};