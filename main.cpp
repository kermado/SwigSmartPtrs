#include <string>
#include <Python/Python.h>

int main()
{
    Py_Initialize();
    PySys_SetPath(".");

    std::string source =
R"(
from module import *
print('Hello World')
player1 = create_entity_pointer()
print(player1)
print(player1.value())
player2 = create_entity_watch_pointer()
print(player2)
print(player2.value())
)";

    PyRun_SimpleString(source.c_str());

    Py_Finalize();

    return 0;
}