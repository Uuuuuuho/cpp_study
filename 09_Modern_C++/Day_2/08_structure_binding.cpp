#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

    /* In C++17, it's able to do this. */
    auto [a1, a2, a3] = p3d;    /*  auto a1 = p3d.x
                                    auto a2 = p3d.y
                                    auto a3 = p3d.z
                                */
	/* =========================================== */
	std::map<std::string, std::string> m;
    /* 'map' store pairs. */

	m["mon"] = "Monday";

	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "Tuesday";
	m.insert(p);

    /* ============================ */
    /* Access every element of map  */ 
    /* 1. C++11 style               */
    for(auto &p:m){
        /* p is pair */
        auto key = p.first;
        auto value = p.second;
    }
    /* 2. C++17 style */
    for(auto[key,value]:m){
        /* writing code... */
    }
}

