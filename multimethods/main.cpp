#include "ordered_type_info.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

struct Shape
{
    virtual void fn() = 0;
};

struct Rectangle : Shape
{
    void fn() override
    {
        std::cout << "Rectangle\n";
    }
};

struct RoundedCornersRectangle : Rectangle
{
    void fn() override
    {
        std::cout << "RoundedCornersRectangle\n";
    }
};

struct Circle : Shape
{
    void fn() override
    {
        std::cout << "Circle\n";
    }
};

int main()
{
    OrderedTypeInfo c = typeid(RoundedCornersRectangle);
    OrderedTypeInfo a = typeid(Shape);
    OrderedTypeInfo b = typeid(Rectangle);
    OrderedTypeInfo d = typeid(Circle);

	std::vector<OrderedTypeInfo> ov{a, c, d, b};
	for (auto i : ov)
	{
		std::cout << i.name() << "\n";
	}

	std::cout << " **** \n";

	std::sort(ov.begin(), ov.end());
	for (auto i : ov)
	{
		std::cout << i.name() << "\n";
	}

	return 0;
}
