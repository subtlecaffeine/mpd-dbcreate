// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_TWO_FILTERS_HXX
#define MPD_TWO_FILTERS_HXX

#include "filter/Prepared.hxx"
#include <memory>

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
PreparedTwoFilters([[maybe_unused]] std::unique_ptr<PreparedFilter> a,
		   [[maybe_unused]] std::unique_ptr<PreparedFilter> b)
{
	return nullptr;
}

inline std::unique_ptr<PreparedFilter>
ChainFilters([[maybe_unused]] std::unique_ptr<PreparedFilter> a,
	     [[maybe_unused]] std::unique_ptr<PreparedFilter> b,
	     [[maybe_unused]] const char *name = nullptr)
{
	return nullptr;
}

#endif
