#include <exception>
#include <iostream>

int main(int ac, char *av[])
{
    try {
        if (ac != 2)
            throw "Yo";
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (char const *str) {
        std::cerr << str << std::endl;
    }
}