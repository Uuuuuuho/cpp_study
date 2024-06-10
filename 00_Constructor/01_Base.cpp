#include <iostream>

class Buffer
{
  public:
    Buffer(std::size_t sz){std::cout << "init buffer" << std::endl;}
    void use()            {std::cout << "use buffer" << std::endl;}
};
class Stream
{
private:
  /* data */
public:
  Stream(Buffer& buf){buf.use();}
  ~Stream(){}
};

//===============
class StreamWithBuffer : public Stream
{
private:
  /* data */
  Buffer buf{1024};
public:
  StreamWithBuffer(/* args */): Stream(buf){}
  ~StreamWithBuffer(){}
};

int main(){
  StreamWithBuffer swb;
}
