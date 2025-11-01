// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

#pragma once

// Channel mode for database creation filtering
enum class ChannelMode {
	STEREO,
	MULTICHANNEL,
	ALL
};

// External function to get channel mode
// Implemented in Main.cxx for mpd-dbcreate
// Note: Using extern "C" to avoid C++ name mangling so it can be called from any namespace
extern "C" ChannelMode GetChannelMode() noexcept;
