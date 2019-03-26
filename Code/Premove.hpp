#ifndef _PREMOVE_HPP_
#define _PREMOVE_HPP_

#include <queue>
#include <string>
#include "Coordinate.hpp"

class PreMove {
    private:
    Coordinate const _start;
    Coordinate const _end;

    public:
    constexpr PreMove(Coordinate& start, Coordinate& end) noexcept : _start(start), _end(end) {}
    constexpr PreMove(Coordinate&& start, Coordinate&& end) noexcept : _start(start), _end(end) {}
    std::string& getPreMove() const {std::string res; res[0] = _start.getAbstractColumn();
    res[1] = _start.getAbstractRow(); res[2] = _end.getAbstractColumn();
    res[3] = _end.getAbstractRow(); return res;}
    ~PreMove() noexcept = default;
};

#endif