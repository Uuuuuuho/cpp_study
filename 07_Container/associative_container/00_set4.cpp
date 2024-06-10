#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_out(std::set<T> &s)
{
  for(const auto& ele : s) std::cout << ele << " " << std::endl;
}
class Todo
{
  int priority;
  std::string job_desc;

public:
  Todo(int priority, std::string job_desc)
    : priority(priority), job_desc(job_desc){}

  bool operator<(const Todo& t) const{
    if(priority == t.priority) return job_desc < t.job_desc;
    return priority > t.priority;
  }
  friend struct TodoCmp;
  friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};
struct TodoCmp
{
  bool operator()(const Todo& t1, const Todo& t2) const{
    if(t1.priority == t2.priority) return t1.job_desc < t2.job_desc;
    return t1.priority > t2.priority;
  }
};
std::ostream& operator<<(std::ostream& o, const Todo& td)
{
  o << "[ Importance : " << td.priority << "] " << td.job_desc;
}

int main()
{
  std::set<Todo> todos;

  todos.insert(Todo(1,"Basketball"));
  todos.insert(Todo(2,"Math"));
  todos.insert(Todo(3,"Programming"));
  todos.insert(Todo(4,"Meeting with friend"));
  todos.insert(Todo(5,"Movie"));
  print_out(todos);

  std::cout << "-------------" << std::endl;
  std::cout << "Finish homework!" << std::endl;
  todos.erase(todos.find(Todo(2, "Math")));
  print_out(todos);
}