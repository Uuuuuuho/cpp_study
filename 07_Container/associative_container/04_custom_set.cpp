#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s)
{
  for(const auto& ele : s) std::cout << ele << " " << std::endl;
}
class Todo
{
  int priority;
  std::string job_desc;

public:
  Todo(int priority, std::string job_desc): priority(priority),job_desc(job_desc){}
  bool operator<(const Todo& t) const
  {
    if (priority == t.priority) return job_desc < t.job_desc;
    else return priority > t.priority;
  }
  friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};
std::ostream& operator<<(std::ostream& o, const Todo& td)
{
  o << "[ Priority: " << td.priority << "] " << td.job_desc;
  return o;
}

int main()
{
  std::set<Todo> todos;

  todos.insert(Todo(1, "a"));
  todos.insert(Todo(2, "b"));
  todos.insert(Todo(3, "c"));
  todos.insert(Todo(1, "d"));
  todos.insert(Todo(2, "e"));

  print_set(todos);
}