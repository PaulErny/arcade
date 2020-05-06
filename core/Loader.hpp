#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include <memory>

template <class T>
class Loader
{
private:
    std::string openString;
    std::string lib;
    std::shared_ptr<T> openedLib;
    void *m_handler;

public:
    Loader(std::string lib);
    ~Loader();
    void open();
    void create();
    void checkError();
    const std::shared_ptr<T> &getOpenedLib() const;
};

template <class T>
Loader<T>::Loader(std::string lib) : lib(lib)
{
}

template <class T>
Loader<T>::~Loader()
{
}

template <class T>
void Loader<T>::checkError()
{
    if (dlerror() != NULL)
        throw dlerror();
}

template <class T>
void Loader<T>::open()
{
    m_handler = dlopen(lib.c_str(), RTLD_LAZY);
    checkError();
}

template <class T>
const std::shared_ptr<T> &Loader<T>::getOpenedLib() const
{
    return (openedLib);
}

template <class T>
void Loader<T>::create()
{
    std::shared_ptr<T> (*create)();
    create = (std::shared_ptr<T>(*)())dlsym(m_handler, "create_object");
    checkError();
    openedLib = (std::shared_ptr<T>)create();
}

#endif