// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_NORMALIZE_FILTER_PLUGIN_HXX
#define MPD_NORMALIZE_FILTER_PLUGIN_HXX

#include "filter/Prepared.hxx"
#include <memory>

struct ConfigBlock;

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
normalize_filter_prepare([[maybe_unused]] const ConfigBlock *block = nullptr)
{
	return nullptr;
}

#endif
