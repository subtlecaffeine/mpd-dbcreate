// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

// Stub implementation for stats functions that are not needed in dbcreate mode

#include "Stats.hxx"

void
stats_invalidate()
{
	// In dbcreate mode, we don't track stats
}
