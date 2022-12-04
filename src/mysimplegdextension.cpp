#include "mysimplegdextension.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void MySimpleGdextension::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_process"), &MySimpleGdextension::_process);
    // ERROR: Method 'MySimpleGdextension::_process()' already registered as non-virtual.
    //     at: bind_virtual_method (src/core/class_db.cpp:323)
}

void MySimpleGdextension::_register_methods()
{
    // register_method("_process", &MySimpleGdextension::_process);
    // register_property<MySimpleGdextension, float>("amplitude", &MySimpleGdextension::amplitude, 10.0);
}

MySimpleGdextension::MySimpleGdextension()
{
    time_passed = 0.0;
    amplitude = 10.0;
}

MySimpleGdextension::~MySimpleGdextension()
{
    // std::cout << "clean up" << std::endl;
}

void MySimpleGdextension::_init()
{
    time_passed = 0;
    amplitude = 10;
}

void MySimpleGdextension::_process(float delta)
{
    time_passed += delta;

    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5)));

    set_position(new_position);
}
