// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

// Stub implementations for functions not needed in dbcreate mode

#include "config.h"
#include "song/DetachedSong.hxx"
#include "SongLoader.hxx"
#include "io/BufferedOutputStream.hxx"

#include <stdio.h>

// Stub for ls.cxx
void
print_supported_uri_schemes_to_fp([[maybe_unused]] FILE *fp)
{
	// Not needed in dbcreate mode
}

// Stub for playlist song functions
bool
playlist_check_translate_song([[maybe_unused]] DetachedSong &song,
			      [[maybe_unused]] std::string_view base_uri,
			      [[maybe_unused]] const SongLoader &loader)
{
	// Not needed in dbcreate mode
	return false;
}

void
playlist_print_song([[maybe_unused]] BufferedOutputStream &os,
		    [[maybe_unused]] const DetachedSong &song)
{
	// Not needed in dbcreate mode
}

void
playlist_print_uri([[maybe_unused]] BufferedOutputStream &os,
		   [[maybe_unused]] const char *uri)
{
	// Not needed in dbcreate mode
}

// Stub for SongLoader
DetachedSong
SongLoader::LoadSong([[maybe_unused]] const char *uri_utf8) const
{
	// Not needed in dbcreate mode - throw to indicate failure
	throw std::runtime_error("SongLoader not available in dbcreate mode");
}
