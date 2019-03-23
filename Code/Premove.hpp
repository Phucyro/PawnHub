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
    PreMove(std::string& msg) noexcept : _start(msg[0], msg[1]), _end(msg[2], msg[3]) {}
    std::string& getPreMove() const {std::string res; res[0] = _start.getAbstractColumn();
    res[1] = _start.getAbstractRow(); res[2] = _end.getAbstractColumn();
    res[3] = _end.getAbstractRow(); res[4] = '\0'; return res;}
    ~PreMove() noexcept = default;
};

#endif