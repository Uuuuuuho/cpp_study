#include <iostream>
#include <string>
#include <vector>

class ProductOne {
public:
    std::vector<std::string> parts_;
    void ListParts() const {
        std::cout << "Product parts: ";
        for(size_t i = 0; i < parts_.size(); i++) {
            if(parts_[i] == parts_.back()) {
                std::cout << parts_[i];
            }
            else {
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 : public Builder {
private:
    ProductOne* product;

public:
    ConcreteBuilder1() {
        this->Reset();
    }
    ~ConcreteBuilder1() {
        delete product;
    }
    void Reset() {
        this->product = new ProductOne();
    }
    void ProducePartA() const override {
        this->product->parts_.push_back("PartAOne");
    }
    void ProducePartB() const override {
        this->product->parts_.push_back("PartBOne");
    }
    void ProducePartC() const override {
        this->product->parts_.push_back("PartCOne");
    }
    ProductOne* GetProduct() {
        ProductOne* ret = this->product;
        this->Reset();
        return ret;
    }
};

class Director {
private:
    Builder* builder;

public:
    void set_builder(Builder* builder) {
        this->builder = builder;
    }
    void BuildMinimalViableProduct() {
        this->builder->ProducePartA();
    }
    void BuildFullFeaturedProduct() {
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
    }
};

void ClientCode(Director& director) {
    ConcreteBuilder1* Cbuilder = new ConcreteBuilder1();
    director.set_builder(Cbuilder);
    std::cout << "Standard basic product:\n";
    director.BuildMinimalViableProduct();

    ProductOne* pp = Cbuilder->GetProduct();
    pp->ListParts();
    delete pp;

    std::cout << "Standard full featured product:\n";
    director.BuildFullFeaturedProduct();

    pp = Cbuilder->GetProduct();
    pp->ListParts();
    delete pp;

    std::cout << "Custom product:\n";
    Cbuilder->ProducePartA();
    Cbuilder->ProducePartC();
    pp = Cbuilder->GetProduct();
    pp->ListParts();
    delete pp;

    delete Cbuilder;
}

int main() {
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}