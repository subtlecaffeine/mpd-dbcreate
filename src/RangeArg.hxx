// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

#ifndef MPD_RANGE_ARG_HXX
#define MPD_RANGE_ARG_HXX

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <algorithm>

/**
 * A numeric range used for window/limit operations.
 * Simplified version for database operations without client protocol support.
 */
struct RangeArg {
	unsigned start, end;

	constexpr RangeArg() noexcept = default;

	constexpr RangeArg(unsigned _start, unsigned _end) noexcept
		:start(_start), end(_end) {}

	static constexpr RangeArg All() noexcept {
		return {0, std::numeric_limits<unsigned>::max()};
	}

	constexpr bool IsAll() const noexcept {
		return start == 0 && end == std::numeric_limits<unsigned>::max();
	}

	constexpr bool IsOpenEnded() const noexcept {
		return end == std::numeric_limits<unsigned>::max();
	}

	constexpr bool IsEmpty() const noexcept {
		return start >= end;
	}

	constexpr std::size_t Count() const noexcept {
		return IsEmpty() ? 0 : (end - start);
	}

	constexpr bool Contains(unsigned i) const noexcept {
		return i >= start && i < end;
	}

	constexpr bool operator==(const RangeArg &other) const noexcept {
		return start == other.start && end == other.end;
	}

	constexpr bool operator!=(const RangeArg &other) const noexcept {
		return !(*this == other);
	}

	constexpr bool CheckClip(unsigned total) const noexcept {
		return start <= total;
	}

	constexpr RangeArg ClipRelaxed(unsigned total) const noexcept {
		return {
			start,
			std::min(end, total)
		};
	}

	constexpr bool HasAtLeast(unsigned n) const noexcept {
		return Count() >= n;
	}
};

#endif
