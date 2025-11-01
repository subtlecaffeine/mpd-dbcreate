// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_FILTER_PREPARED_HXX
#define MPD_FILTER_PREPARED_HXX

#include "Filter.hxx"
#include <memory>

struct AudioFormat;

/**
 * Stub implementation - filter support not needed for database creation
 */
class PreparedFilter {
public:
	virtual ~PreparedFilter() = default;

	virtual std::unique_ptr<Filter> Open([[maybe_unused]] const AudioFormat &af) {
		return nullptr; // Stub returns nullptr
	}
};

#endif
