// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#ifndef MPD_FILTER_HXX
#define MPD_FILTER_HXX

#include <span>
#include <cstddef>
#include <memory>

struct AudioFormat;

/**
 * Stub implementation - filter support not needed for database creation
 */
class Filter {
public:
	virtual ~Filter() = default;

	virtual std::span<const std::byte> FilterPCM(std::span<const std::byte> src) {
		return src; // Pass-through stub
	}

	virtual std::span<const std::byte> Flush() {
		return {}; // Empty stub
	}

	virtual std::span<const std::byte> ReadMore() {
		return {}; // Empty stub
	}

	virtual void Reset() noexcept {
		// No-op stub
	}

	virtual const AudioFormat &GetOutAudioFormat() const noexcept;
};

class PreparedFilter; // Forward declaration - see Prepared.hxx for full definition

#endif
