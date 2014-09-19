#pragma once

#include <stdlib.h>
#include <map>
#include <vector>
#include "object.h"

#define _t(quote)           quote
#define t_strlen            strlen
#define t_strcmp            strcmp
#define t_strncmp           strncmp
#define t_strcasecmp        strcasecmp
#define t_strncasecmp       strncasecmp
#define t_snprintf          snprintf
#define t_strtol            strtol
#define t_atoi              atoi
#define t_strtod            strtod
#define t_strstr            strstr
#define t_tolower           tolower
#define t_isdigit           isdigit
typedef std::string         tstring;
typedef void               *uintPtr;
typedef unsigned char       byte;
typedef wchar_t wchar;

namespace litehtml
{
class Node;
class ElementNode;
class Document;

typedef std::map<tstring, tstring>                         StringMap;
typedef std::vector<litehtml::ObjectPtr<litehtml::Node>>   ElementsVector;
typedef std::vector<int>                                   IntVector;
typedef std::vector<tstring>                               StringVector;

struct Size
{
    int     width;
    int     height;

    Size()
    {
        width   = 0;
        height  = 0;
    }
};

struct Margin
{
    int left;
    int right;
    int top;
    int bottom;

    Margin()
    {
        left = right = top = bottom = 0;
    }

    int width()     const
    {
        return left + right;
    }
    int height()    const
    {
        return top + bottom;
    }
};

struct Padding
{
    int left;
    int right;
    int top;
    int bottom;

    Padding()
    {
        left = right = top = bottom = 0;
    }

    int width()     const
    {
        return left + right;
    }
    int height()    const
    {
        return top + bottom;
    }
};

struct Position
{
    int x;
    int y;
    int width;
    int height;

    Position()
    {
        x = y = width = height = 0;
    }

    Position(int x, int y, int width, int height)
    {
        this->x         = x;
        this->y         = y;
        this->width     = width;
        this->height    = height;
    }

    int right()     const
    {
        return x + width;
    }
    int bottom()    const
    {
        return y + height;
    }
    int left()      const
    {
        return x;
    }
    int top()       const
    {
        return y;
    }

    void operator+=(const Margin &mg)
    {
        x       -= mg.left;
        y       -= mg.top;
        width   += mg.left + mg.right;
        height  += mg.top + mg.bottom;
    }
    void operator-=(const Margin &mg)
    {
        x       += mg.left;
        y       += mg.top;
        width   -= mg.left + mg.right;
        height  -= mg.top + mg.bottom;
    }

    void clear()
    {
        x = y = width = height = 0;
    }

    void operator=(const Size &sz)
    {
        width   = sz.width;
        height  = sz.height;
    }

    void move_to(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool does_intersect(const Position *val) const
    {
        if (!val) return true;

        return (
                   left()          <= val->right()     &&
                   right()         >= val->left()      &&
                   bottom()        >= val->top()       &&
                   top()           <= val->bottom()    )
               || (
                   val->left()     <= right()          &&
                   val->right()    >= left()           &&
                   val->bottom()   >= top()            &&
                   val->top()      <= bottom()         );
    }

    bool empty() const
    {
        if (!width && !height)
        {
            return true;
        }
        return false;
    }

    bool is_point_inside(int x, int y) const
    {
        if (x >= left() && x <= right() && y >= top() && y <= bottom())
        {
            return true;
        }
        return false;
    }
};

enum DRAW_FLAG
{
    root,
    block,
    floats,
    inlines,
    positioned
};
}
