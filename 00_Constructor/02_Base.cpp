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
  ~Stream();
};
//===============
class StreamBuffer
{
protected:
  Buffer buf{1024};
private:
  /* data */
public:
  StreamBuffer(/* args */){}
  ~StreamBuffer(){}
};

class StreamWithBuffer : public StreamBuffer, public Stream
{
private:
  /* data */
  Buffer buf{1024};
public:
  StreamWithBuffer(/* args */) : Stream(buf){}
};

int main(){
  StreamWithBuffer swb;
}
