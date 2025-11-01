// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Encoder support removed for mpd-dbcreate

#ifndef MPD_ENCODER_LIST_HXX
#define MPD_ENCODER_LIST_HXX

#include <iterator>

struct EncoderPlugin;

/**
 * Stub implementation - encoder support not needed for database creation
 */
class EncoderPluginIterator {
public:
	using iterator_category = std::forward_iterator_tag;
	using value_type = const EncoderPlugin *;
	using difference_type = std::ptrdiff_t;
	using pointer = value_type *;
	using reference = value_type &;

	bool operator==(const EncoderPluginIterator &) const noexcept { return true; }
	bool operator!=(const EncoderPluginIterator &) const noexcept { return false; }
	EncoderPluginIterator &operator++() noexcept { return *this; }
	const EncoderPlugin *operator*() const noexcept { return nullptr; }
};

inline EncoderPluginIterator
encoder_plugins_begin() noexcept
{
	return {};
}

inline EncoderPluginIterator
encoder_plugins_end() noexcept
{
	return {};
}

#endif
