#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_out(std::set<T> &s)
{
  std::cout << "[ ";
  for(const auto& ele : s) std::cout << ele << " " << std::endl;
  std::cout << "]" << std::endl;
}
class Todo
{
  int priority;
  std::string job_desc;

public:
  Todo(int priority, std::string job_desc)
    : priority(priority), job_desc(job_desc){}
};

int main()
{
  std::set<Todo> todos;

  todos.insert(Todo(1,"Basketball"));
  // compiler error. there is no '<' operator in class "Todo"
  todos.insert(Todo(2,"Math"));
  todos.insert(Todo(3,"Programming"));
  todos.insert(Todo(4,"Meeting with friend"));
  todos.insert(Todo(5,"Movie"));
}