template <typename T>
T square(T a) {
    return a * a;
}

// int와 double 타입에 대한 explicit instantiation
template int squre(int);
template double square(double);