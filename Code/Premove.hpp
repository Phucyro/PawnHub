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
	constexpr PreMove(const Coordinate& start, const Coordinate& end) noexcept : _start(start), _end(end) {}
	constexpr PreMove(Coordinate&& start, Coordinate&& end) noexcept : _start(start), _end(end) {}
	std::string getPreMove() const {
		std::string res;
		res += _start.getAbstractColumn();
		res += _start.getAbstractRow();
		res += _end.getAbstractColumn();
		res += _end.getAbstractRow();
		return res;
	}
	~PreMove() noexcept = default;
};

#endif
