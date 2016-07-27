//
//  c1.5.h
//  c1.5
//
//  Created by 王宁 on 16/7/23.
//  Copyright © 2016年 王宁. All rights reserved.
//

#ifndef c1_5_h
#define c1_5_h
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    vector<Screen> screens;
};

class Screen {
     friend void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos;
    Screen () = default;
    Screen ( pos ht, pos wd, char c ) : height(ht), width(wd),contents(ht*wd,c) { };
    char get() const {
        return contents[cursor];
    }
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    inline char get( pos ht, pos wd ) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos,pos,char);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};
inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width+c] = ch;
    return *this;
}
inline Screen &Screen::move(pos r,pos c) {
    pos row = r * width;
    cursor = row +c;
    return *this;
}
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
inline void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height*s.width,' ');
}
#endif /* c1_5_h */
