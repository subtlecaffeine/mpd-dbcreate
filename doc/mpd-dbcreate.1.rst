============
mpd-dbcreate
============

SYNOPSIS
--------

``mpd-dbcreate`` --music-dir <path> --database <path/file.db> [OPTIONS]

DESCRIPTION
-----------

mpd-dbcreate is a program for creating a media database for MPD. It differs from MPD's built-in database tool in the following ways:

- Allows filtering of only stereo or only multi-channel content
- "Intelligent" handling of CUE files, using only when really necessary
- SACD Title specific fixes (For those who run that fork)
- Very verbose output so you can see what it's doing

It can be run on a system without full mpd; or before first mpd run to avoid systemd timeout.

Databases created by mpd-dbcreate should only be updated with mpd-dbcreate. Auto-updating within MPD is not supported and will use MPD's rules. You will need to update the database with mpd-dbcreate and then restart MPD. You can update/write to the database while MPD is running since it loads it in to memory at start.

mpd-dbcreate only indexes media and attempts to have a wide format support. Actual format playback will depend on the capabilities of your local mpd install.

OPTIONS
-------

.. program:: mpd-dbcreate

.. option:: --help

  Output a brief help message.

.. option:: --music-dir

  The path of the music directory you want to index. (Also your database root)

.. option:: --database

  Location of MPD database file. (Will create if new.)

.. option:: --update

  Updates existing database for new files. (Incremental scan.)

.. option:: --update-path <path>

  The path relative to your database root to update. (Use with --update)

.. option:: --stereo

  Filter database for only stereo content.

.. option:: --multichannel

  Filter database for only multi-channel content.

.. option:: --all

  Don't filter. Keep everything. (Default)

.. option:: --verbose

  Verbose output of scanning process to console.

EXAMPLES
--------

Create a database of only stereo content:

``mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --stereo``

Scan a database of only multichannel content:

``mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --multichannel``

Create a database of all content:

``mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --all``

Update an existing database:

``mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db (--stereo|--multichannel|--all) --update``

Update a specific directory in the database:

``mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db (--stereo|--multichannel|--all) --update --update-path /path``

FILES
-----

The MPD database can live just about anywhere on the system. The usual location seems to be ``/var/lib/mpd/mpd.db``. This is entirely determined by your ``mpd.conf`` file.

The database can be moved to a different system than it was scanned on. This is helpful for scanning directly on the NAS. The database stores everything as relative to the root of the music directory. So you can scan ``/raid/music`` on your NAS, mount it as ``/mnt/music`` on your local machine, point MPD to ``/mnt/music``, and that's it.

NOTES
-----

Please make note of the following things:

- If you get a "simple database" error; check the path of the database you specified.
- Try to use full paths at all times.
- It looks like it hangs on ISO files when using --verbose. It's not. Just wait. I believe it's something with the plugin that I don't want to touch.
- Your music directory is root of the database. Keep this in mind if you want to scan on a different system.

SEE ALSO
--------

:manpage:`mpd(1)`, :manpage:`mpd.conf(5)`


BUGS
----
If you find a bug, please report it at https://github.com/subtlecaffeine/mpd-dbcreate/issues
