// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project
// STUB FILE - Filter support removed for mpd-dbcreate

#include "Filter.hxx"
#include "pcm/AudioFormat.hxx"

const AudioFormat &
Filter::GetOutAudioFormat() const noexcept
{
	// Return a static dummy audio format with minimal valid initialization
	static const AudioFormat dummy_format{44100, SampleFormat::S16, 2};
	return dummy_format;
}
