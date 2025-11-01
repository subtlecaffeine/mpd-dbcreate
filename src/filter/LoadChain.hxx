// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_FILTER_LOAD_CHAIN_HXX
#define MPD_FILTER_LOAD_CHAIN_HXX

#include "Prepared.hxx"
#include <memory>

class FilterFactory;
struct ConfigBlock;

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
filter_chain_parse([[maybe_unused]] std::unique_ptr<PreparedFilter> &prepared,
		   [[maybe_unused]] FilterFactory &factory,
		   [[maybe_unused]] const char *spec)
{
	return nullptr;
}

inline std::unique_ptr<PreparedFilter>
filter_chain_new([[maybe_unused]] const ConfigBlock *block)
{
	return nullptr;
}

#endif
