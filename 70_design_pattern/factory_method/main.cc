/* 
 * The product interface declares the operations that all concrete products must
 * implement.
 */
#include <string>
#include <iostream>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    }
};


class Creator {
public:
    virtual ~Creator() {}
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        // Call the factory method to create a Product object.
        Product* product = this->FactoryMethod();
        std::string ret = "Creator: the same creator's code has just worked with "  + product->Operation();
        delete product;
        return ret;
    }
};

class ConcreteCreator1 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct2();
    }
};

void ClientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
                << creator.SomeOperation() << std::endl;
}

int main() {
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator_one = new ConcreteCreator1();
    ClientCode(*creator_one);

    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator_two = new ConcreteCreator2();
    ClientCode(*creator_two);

    delete creator_one;
    delete creator_two;
    return 0;
}
