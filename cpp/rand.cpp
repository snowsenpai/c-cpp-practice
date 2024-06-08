#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
// #include <ranges>
#include <numeric>
#include <type_traits>

template<typename T>
T get_random_number(T lower, T upper)
{
    static_assert(std::is_arithmetic<T>::value, "Template parameter must be an arithmetic type");

    std::random_device dev;
    std::mt19937 rng(dev());

    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(lower, upper);
        return dist(rng);
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::uniform_real_distribution<T> dist(lower, upper);
        return dist(rng);
    }
}

int main()
{
    std::random_device rd; // non-deterministic generator, source of randomness
    std::mt19937 gen(rd()); // seed, mersenne twister engine
    std::uniform_int_distribution<int> dist(1, 9); // uniform distribution to control range [min, max] (inclusive)

    std::cout << "randInt ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << get_random_number(1,10) << " ";
    }
    std::cout << "\n";

    std::cout << "randFloat ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << get_random_number(0.0f, 1.0f) << " ";
    }
    std::cout << "\n";

    std::cout << "gen() ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << gen() << " "; // raw output of seeded generator
    }
    std::cout << "\n";

    std::cout << "rd() ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << rd() << " "; // raw output of non-deterministic generator
    }
    std::cout << "\n";
    
    std::cout << "dist(rd) ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << dist(rd) << " "; //pass rand generator to distribution
    }
    std::cout << "\n";

    std::cout << "dist(gen) ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << dist(gen) << " "; //pass seeded generator to distribution
    }
    std::cout << "\n";

    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);

    std::cout << "iota to populate vec ";
    for(auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::shuffle(vec.begin(), vec.end(), rd);
    // std::ranges::shuffle(vec, rd); // -std=c++20 
    
    std::cout << "vec after shuffle ";
    for(auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";
}