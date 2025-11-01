// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_VOLUME_FILTER_PLUGIN_HXX
#define MPD_VOLUME_FILTER_PLUGIN_HXX

#include "filter/Prepared.hxx"
#include <memory>

class Filter;

/**
 * Stub implementation - filter support not needed for database creation
 */
inline void
volume_filter_set(Filter *, unsigned) noexcept
{
	// No-op stub
}

inline std::unique_ptr<PreparedFilter>
volume_filter_prepare() noexcept
{
	return nullptr;
}

#endif
