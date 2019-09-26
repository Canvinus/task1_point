////////////////////////////////////////////////////////////////////////////////
// Module Name:  xipoint.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.1
// Date:         08.09.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "xipoint.h"

#include <algorithm>        // min
#include <cmath>

namespace xi {



// TODO: put the method implementations here

    Point::Point(int x, int y)
    {
        _x = x;
        _y = y;
    }
    void Point::shift(int shf)
    {
        _x += shf;
        _y += shf;
    }

    void Point::shift(int xSh, int ySh)
    {
        _x += xSh;
        _y += ySh;
    }

    void Point::shift(const xi::Point &pt)
    {
        _x += pt.getX();
        _y += pt.getY();
    }

    double Point::dist(const xi::Point &other) const
    {
        return sqrt((other.getX() - _x) * (other.getX() - _x) + (other.getY() - _y) * (other.getY() - _y));
    }

    int Point::getY() const
    {
        return _y;
    }

    int Point::getX() const
    {
        return _x;
    }

    void Point::setX(int x)
    {
        _x = x;
    }

    void Point::setY(int y)
    {
        _y = y;
    }

    PointArray::PointArray()
    {
        _arr = nullptr;
        _size = 0;
    }

    PointArray::PointArray(const xi::Point *points, xi::PointArray::Uint n)
    {
        _arr = new Point[n];
        _size = n;
        for(int i = 0;i<n;i++)
        {
            _arr[i] = points[i];
        }
    }

    PointArray::PointArray(const xi::PointArray &pv)
    {
        resize(pv.getSize());
        for (int i = 0;i<_size;i++)
        {
            _arr[i] = pv._arr[i];
        }
    }

    PointArray::~PointArray()
    {
        delete[] _arr;
        _size = 0;
    }

    void PointArray::append(const xi::Point &pt)
    {
        resize(1);
        _arr[_size-1] = pt;
    }

    void PointArray::insert(const xi::Point &pt, xi::PointArray::Uint pos)
    {
        if(pos > _size)
            append(pt);
        else {
            resize(1);
            for(int i = pos+1; i < _size; i++)
            {
                _arr[i] =  _arr[i-1];
            }
            _arr[pos] = pt;
        }
    }

    void PointArray::remove(xi::PointArray::Uint pos)
    {
        if(pos < _size)
        {
            for(int i = pos; i < _size-1; i++)
            {
                _arr[i] =  _arr[i+1];
            }
            resize(-1);
        }
    }

    void PointArray::clear()
    {
        _size = 0;
        _arr = new Point[0];
    }

    double PointArray::computePath() const
    {
        double sum = 0;
        for(int i =0;i<_size-1;i++)
        {
            sum += _arr[i].dist(_arr[i+1]);
        }
        return sum;
    }

    PointArray::Uint PointArray::getSize() const
    {
        return _size;
    }

    const Point* PointArray::get(xi::PointArray::Uint pos) const
    {
        if(pos > _size)
            return nullptr;
        else
            return &_arr[pos];
    }

    Point* PointArray::get(xi::PointArray::Uint pos)
    {
        if(pos > _size)
            return nullptr;
        else
            return &_arr[pos];
    }

    void PointArray::resize(xi::PointArray::Uint n)
    {
        Point* resized_arr = new Point[_size + n];
        for(int i = 0;i<_size;i++)
        {
            resized_arr[i] = _arr[i];
        }
        _size += n;
        delete[] _arr;
        _arr = resized_arr;
    }



} // namespace xi {
