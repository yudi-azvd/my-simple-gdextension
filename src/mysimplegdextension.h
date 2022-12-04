#ifndef MYSIMPLEGDEXTENSION_H_INCLUDED
#define MYSIMPLEGDEXTENSION_H_INCLUDED

#include <sprite2d.hpp>

namespace godot
{
    class MySimpleGdextension : public Sprite2D {
        GDCLASS(MySimpleGdextension, Sprite2D);

    private:
        float time_passed;
        float amplitude;

    protected:
        static void _bind_methods();
        static void _register_methods();

    public:
        MySimpleGdextension();
        ~MySimpleGdextension();

        void _init();

        void _process(float delta);
    };
}

#endif // MYSIMPLEGDEXTENSION_H_INCLUDED