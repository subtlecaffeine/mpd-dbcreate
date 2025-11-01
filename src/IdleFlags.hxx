// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

#ifndef MPD_IDLE_FLAGS_HXX
#define MPD_IDLE_FLAGS_HXX

/**
 * Idle event flags for MPD subsystems.
 * Minimal version for database operations without full client protocol.
 */
enum {
	/** song database has been updated*/
	IDLE_DATABASE = 0x1,

	/** a stored playlist has been modified, created, deleted or renamed */
	IDLE_STORED_PLAYLIST = 0x2,

	/** the current playlist has been modified */
	IDLE_PLAYLIST = 0x4,

	/** the player state has changed: play, stop, pause, seek, ... */
	IDLE_PLAYER = 0x8,

	/** the volume has been modified */
	IDLE_MIXER = 0x10,

	/** an audio output device has been enabled or disabled */
	IDLE_OUTPUT = 0x20,

	/** options have changed: crossfade, random, repeat, ... */
	IDLE_OPTIONS = 0x40,

	/** a database update has started or finished. */
	IDLE_UPDATE = 0x80,

	/** a sticker has been modified. */
	IDLE_STICKER = 0x100,

	/** a client has subscribed to or unsubscribed from a channel */
	IDLE_SUBSCRIPTION = 0x200,

	/** a message on a subscribed channel was received */
	IDLE_MESSAGE = 0x400,

	/** a neighbor was found or lost */
	IDLE_NEIGHBOR = 0x800,

	/** the mount list has changed */
	IDLE_MOUNT = 0x1000,

	/** a partition was added, removed or changed */
	IDLE_PARTITION = 0x2000,
};

#endif
