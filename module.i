%module module

%{
    #include "watch_ptr.hpp"
    #include "Watchable.hpp"
    #include "Entity.hpp"
%}

%include <std_string.i>
%include "watch_ptr.hpp"

%template(EntityWatchPtr) watch_ptr<Entity>;

%include "Watchable.hpp"

%typemap(out) std::string Entity::value
{
    $result = PyString_FromString("Typemapped value");
}

%include "Entity.hpp"