class Human{};
class HandsomeHuman : public virtual Human{};
class SmartHuman : public virtual Human{};
class Me : public HandsomeHuman, public SmartHuman{};
/*  
    diamond shape inheritance를 가지더라도
    virtual parent class에 대해서 하나의 parent memeber variable만 mapping 할
    수 있도록 컴파일러가 지정함.
*/