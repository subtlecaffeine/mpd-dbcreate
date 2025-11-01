// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_CONVERT_FILTER_PLUGIN_HXX
#define MPD_CONVERT_FILTER_PLUGIN_HXX

#include "filter/Prepared.hxx"
#include <memory>

struct AudioFormat;
class Filter;

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
convert_filter_new([[maybe_unused]] const AudioFormat &in,
		   [[maybe_unused]] const AudioFormat &out)
{
	return nullptr;
}

inline void
convert_filter_set([[maybe_unused]] Filter *,
		   [[maybe_unused]] const AudioFormat &) noexcept
{
	// No-op stub
}

inline std::unique_ptr<PreparedFilter>
convert_filter_prepare()
{
	return nullptr;
}

#endif
