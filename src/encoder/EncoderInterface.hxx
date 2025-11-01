// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Encoder support removed for mpd-dbcreate

#ifndef MPD_ENCODER_INTERFACE_HXX
#define MPD_ENCODER_INTERFACE_HXX

#include <memory>

/**
 * Stub implementation - encoder support not needed for database creation
 */
class Encoder {
public:
	virtual ~Encoder() = default;
};

using EncoderPtr = std::unique_ptr<Encoder>;

#endif
