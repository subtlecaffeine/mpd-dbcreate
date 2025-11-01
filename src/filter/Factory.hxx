// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_FILTER_FACTORY_HXX
#define MPD_FILTER_FACTORY_HXX

struct ConfigData;

/**
 * Stub implementation - filter support not needed for database creation
 */
class FilterFactory {
public:
	FilterFactory([[maybe_unused]] const ConfigData &config) {}
};

#endif
