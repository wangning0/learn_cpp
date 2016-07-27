#include "screen"

int main()
{
    Screen scr1(5,5,'X');
    scr1.move(4,0).set('#').display(cout);
    return 0;
}