#include "mysimplegdextension.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void MySimpleGdextension::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_process"), &MySimpleGdextension::_process);
    // ERROR: Method 'MySimpleGdextension::_process()' already registered as non-virtual.
    //     at: bind_virtual_method (src/core/class_db.cpp:323)

    ClassDB::bind_method(D_METHOD("get_amplitude"), &MySimpleGdextension::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &MySimpleGdextension::set_amplitude);
    ClassDB::add_property("MySimpleGdextension", PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &MySimpleGdextension::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &MySimpleGdextension::set_speed);
    ClassDB::add_property("MySimpleGdextension", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
    
    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
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
    time_emit = 0;
    time_passed = 0;
    amplitude = 10;
    speed = 1.0;
}

void MySimpleGdextension::_process(float delta)
{
    time_passed += speed * delta;

    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5)));

    set_position(new_position);

    time_emit += delta;
    if (time_emit > 1.0) {
        emit_signal("position_changed", this, new_position);
        time_emit = 0.0;
    }
}

void MySimpleGdextension::set_amplitude(const float p_amplitude) {
    amplitude = p_amplitude;
}

float MySimpleGdextension::get_amplitude() const {
    return amplitude;
}

void MySimpleGdextension::set_speed(const float p_speed) {
    speed = p_speed;
}

float MySimpleGdextension::get_speed() const {
    return speed;
}
