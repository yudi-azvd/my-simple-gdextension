#ifndef MYSIMPLEGDEXTENSION_H_INCLUDED
#define MYSIMPLEGDEXTENSION_H_INCLUDED

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot
{
    class MySimpleGdextension : public Sprite2D {
        GDCLASS(MySimpleGdextension, Sprite2D);

    private:
        float time_passed;
        float time_emit;
        float amplitude;
        float speed;

    protected:
        static void _bind_methods();

    public:
        MySimpleGdextension();
        ~MySimpleGdextension();

        void _init();

        void _process(float delta);
        void set_amplitude(const float p_amplitude);
        float get_amplitude() const;
        void set_speed(const float p_speed);
        float get_speed() const;
    };
}

#endif // MYSIMPLEGDEXTENSION_H_INCLUDED