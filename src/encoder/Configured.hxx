// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Encoder support removed for mpd-dbcreate

#ifndef MPD_ENCODER_CONFIGURED_HXX
#define MPD_ENCODER_CONFIGURED_HXX

#include "EncoderInterface.hxx"

struct ConfigBlock;
class AudioFormat;

/**
 * Stub implementation - encoder support not needed for database creation
 */
inline EncoderPtr
encoder_init([[maybe_unused]] const ConfigBlock &block,
	     [[maybe_unused]] AudioFormat &audio_format)
{
	return nullptr;
}

#endif
