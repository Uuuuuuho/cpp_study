#include <iostream>
#include <vector>
#include <string>

template<typename T> class Object
{
    int id;
    std::string name;
    T data;
public:
    Object() = default;
    Object(const Object&) {std::cout << "copy" << std::endl;}
    Object(Object&& other)
        noexcept (std::is_nothrow_move_constructible<T>::value)
        :id(other.id), name(std::move(other.name)),
            data(std::move(other.data))
    {
        std::cout << "move" << std::endl;
    }
};

int main(){
    Object o1;
    Object o2 = o1;
    Object o3 = std::move(o1);
    Object o4 = std::move_if_noexcept(o2);
}