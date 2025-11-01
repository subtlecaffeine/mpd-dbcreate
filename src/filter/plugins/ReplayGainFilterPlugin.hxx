// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_REPLAY_GAIN_FILTER_PLUGIN_HXX
#define MPD_REPLAY_GAIN_FILTER_PLUGIN_HXX

#include "filter/Prepared.hxx"
#include <memory>
#include <cstdint>

struct ReplayGainConfig;
enum class ReplayGainMode : uint8_t;

/**
 * Stub implementation - filter support not needed for database creation
 */
inline std::unique_ptr<PreparedFilter>
NewReplayGainFilter([[maybe_unused]] const ReplayGainConfig &config,
		    [[maybe_unused]] bool allow_convert = false)
{
	return nullptr;
}

inline void
replay_gain_filter_set_mode([[maybe_unused]] Filter &,
			    [[maybe_unused]] ReplayGainMode) noexcept
{
	// No-op stub
}

inline void
replay_gain_filter_set_info([[maybe_unused]] Filter &,
			    [[maybe_unused]] const void *) noexcept
{
	// No-op stub
}

inline void
replay_gain_filter_set_mixer([[maybe_unused]] PreparedFilter &,
			     [[maybe_unused]] class Mixer *,
			     [[maybe_unused]] unsigned) noexcept
{
	// No-op stub
}

#endif
