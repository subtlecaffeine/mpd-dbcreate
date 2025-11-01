// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_FILTER_OBSERVER_HXX
#define MPD_FILTER_OBSERVER_HXX

#include <memory>

class Filter;
class PreparedFilter;

/**
 * Stub implementation - filter support not needed for database creation
 */
class FilterObserver {
public:
	FilterObserver() noexcept = default;

	Filter *Get() noexcept { return nullptr; }

	void Set(Filter *) noexcept {}

	// Also accept PreparedFilter unique_ptr, return it for chaining
	// Use template to avoid incomplete type issues
	template<typename T>
	std::unique_ptr<T> Set(std::unique_ptr<T> p) noexcept {
		return p;
	}
};

#endif
