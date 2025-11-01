// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

#include "Registry.hxx"
#include "InputPlugin.hxx"
#include "input/Features.h"
#include "config.h"

// Streaming/remote plugins removed - not needed for database creation
// - ALSA input (commented out - for audio capture only)
// - CURL (for HTTP/streaming)
// - MMS (for streaming)
// - Qobuz (commercial streaming service)
// - SMB (network file sharing - broken in MPD)
// - CDIO_PARANOIA (CD playback only)

#ifdef ENABLE_FFMPEG
#include "plugins/FfmpegInputPlugin.hxx"
#endif

#ifdef ENABLE_NFS
#include "plugins/NfsInputPlugin.hxx"
#endif

constinit const InputPlugin *const input_plugins[] = {
#ifdef ENABLE_FFMPEG
	&input_plugin_ffmpeg,
#endif
#ifdef ENABLE_NFS
	&input_plugin_nfs,
#endif
	nullptr
};

static constexpr std::size_t n_input_plugins = std::size(input_plugins) - 1;

/* the std::max() is just here to avoid a zero-sized array, which is
   forbidden in C++ */
bool input_plugins_enabled[std::max(n_input_plugins, std::size_t(1))];

bool
HasRemoteTagScanner(std::string_view uri) noexcept
{
	for (const auto &plugin : GetEnabledInputPlugins()) {
		if (plugin.scan_tags != nullptr &&
		    plugin.SupportsUri(uri))
			return true;
	}

	return false;
}
