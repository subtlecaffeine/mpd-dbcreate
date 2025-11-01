// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The Music Player Daemon Project

#ifndef MPD_ACK_HXX
#define MPD_ACK_HXX

#include <stdexcept>
#include <string>

/**
 * MPD protocol error codes.
 * Minimal version for database operations without full client protocol.
 */
enum ack {
	ACK_ERROR_NOT_LIST = 1,
	ACK_ERROR_ARG = 2,
	ACK_ERROR_PASSWORD = 3,
	ACK_ERROR_PERMISSION = 4,
	ACK_ERROR_UNKNOWN = 5,

	ACK_ERROR_NO_EXIST = 50,
	ACK_ERROR_PLAYLIST_MAX = 51,
	ACK_ERROR_SYSTEM = 52,
	ACK_ERROR_PLAYLIST_LOAD = 53,
	ACK_ERROR_UPDATE_ALREADY = 54,
	ACK_ERROR_PLAYER_SYNC = 55,
	ACK_ERROR_EXIST = 56,
};

/**
 * Exception class for MPD protocol errors.
 * For database-only operations, these are just regular exceptions.
 */
class ProtocolError : public std::runtime_error {
	enum ack code;

public:
	ProtocolError(enum ack _code, const char *msg)
		:std::runtime_error(msg), code(_code) {}

	ProtocolError(enum ack _code, const std::string &msg)
		:std::runtime_error(msg), code(_code) {}

	enum ack GetCode() const {
		return code;
	}
};

#endif
