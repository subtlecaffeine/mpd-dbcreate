// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_AUTO_CONVERT_FILTER_PLUGIN_HXX
#define MPD_AUTO_CONVERT_FILTER_PLUGIN_HXX

#include "filter/Prepared.hxx"
#include <memory>

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
autoconvert_filter_new([[maybe_unused]] std::unique_ptr<PreparedFilter> a = nullptr)
{
	return nullptr;
}

#endif
