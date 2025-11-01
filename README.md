# mpd-dbcreate | Jay's MPD Database Creator - "Shut Up Baby, I Know It!"

It's mpd without the daemon and playback functionality. Creates an mpd database based on "better" rules regarding CUE sheets, multi-channel files, and SACD content.


## Overview

mpd-dbcreate is a command-line tool that creates MPD-compatible database files without running the full MPD daemon. This is particularly useful for:

- Creating databases for large music collections without running MPD - *You got hit by the systemd timeout first launch, didn't you?*
- Building databases on systems where MPD isn't installed - *Run it directly on the RAID...just symlink or awk your paths...static binary coming soon!*
- Filtering collections by channel configuration (stereo/multichannel) - *Even that niche format.*
- Supports updating an existing database. - *But only with this utility and not from within mpd.*
- Supports partial update based on path. - *Because the original did it!*


## Features

- Scans music directories and creates MPD-compatible database files - *At least the way I want them made.*
- Supports all audio formats that MPD supports - *SACD playback support requires Maxim's fork of mpd. Milage may vary. Hi Maxim!*
- Handles large collections (tested with multi-TB libraries) - *and I did it over the network in about an hour! Like reasonable frames with your perscription!*
- Looks for every reason to not use a .CUE sheet. - *There are valid reasons and that's why I wrote this!*
- ~~Network filesystem support (NFS, WebDAV)~~ - *URI's are supported, but broken? Please report. SMB is disabled.*
- Channel filtering options (stereo-only, multichannel-only, or all) - *Because it's not like I listen to Britney Spears in 5.1 on a regular basis.*


## "Better" Media Handling

I created this for the basic reason that mpd was not generating databases that worked for me, it angered me, and I thought I could do better:

### CUE Sheet Handling

You don't always need a CUE sheet for playback. If your media files are already split up, as they usually already are, then a CUE sheet doesn't give you any advantage on playback. In fact, this is a disadvantage. If mpd sees a cue sheet; it will only index that cue sheet. This is fine except when it doesn't properly parse the sheet and you wind up with most of an album unplayable. 

The solution is to just not use CUE sheets unless necessary. It compares the number of tracks in the CUE sheet to the number of media files in the folder and makes that decision based on the following rules:

  - If the cue sheet track count matches the media files, ignore the cue.
  - If the cue sheet track count is one more than media files, assume multi-session disc and ignore the cue.
  - Anything else, the CUE is the rule.


### Multi-Channel Filtering

If you don't have multi-channel playback; you don't need the multi-channel files in the database! So let's not even put them in! This was primarily developed for the SACD side as many of those contain both stereo and 5.1; however you may still have 5.1/multichannel releases floating around. I'm stereo-only playback and I have a ton of 5.1; and not all of them on SACD! 

You can specify if you want to keep just stereo, just multichannel, or everything! Be warned, *this is literal!* A multichannel database *will not* contain stereo files. If you support both types of playback, then the -all feature will work for you.

### SACD Cleanup

SACD's are presented to mpd in a non-standard way; so we had to go down in to that code and implement some changes. The primary one is that it follows stereo/multichannel rules like for the rest of the media. So a stereo only database will not have 5.1 SACD stuff mixed in. 

We also cleaned up the tags! The plugin added technical information to the album and track title tags. It's ugly. Primarily putting the channel configuration and track number in the track title is a bit much. So...we clean everything up! Track titles are sanitized/cleaned to be just the title, same with the album titles. After all...if you're only running stereo content, then it's all stereo; you're not at a risk of picking the multichannel version. Likewise, if you've got a multi-channel database; you won't be getting any stereo content.

And if you kept everything, you're still covered! We append (Stereo) or (Multichannel) to the album title. Clean, more human-readable. But we only do this on SACD. You'll have to tag your non-SACD multichannel releases yourself.


I've been using it to maintain my actual MPD database to test new builds and it's worked well. MPD has never complained about the database.

## Building

I've built this on CachyOS. If you have OSX or Windows good luck. It probably won't work. You guys aren't using mpd anyway; what am I worried about? *But seriously if it works let me know.*

### Prerequisites

A build environment with Meson, Ninja, GCC, and a subset of mpd's requirements. A full list is in BUILD_DEPENDENCIES.md. But this should roughly get you in the ballpark:

- Arch/CachyOS: `sudo pacman -S meson ninja gcc fmt icu sqlite zlib flac libvorbis opus libid3tag ffmpeg expat pcre2 libsndfile mpg123`
- Debian/Ubuntu: `sudo apt install meson ninja-build g++ libfmt-dev libicu-dev libsqlite3-dev zlib1g-dev libflac-dev libvorbis-dev libopus-dev libid3tag0-dev libavformat-dev libavcodec-dev libavutil-dev libexpat1-dev libpcre2-dev libsndfile1-dev libmpg123-dev`
- Fedora/RHEL: `sudo dnf install meson ninja-build gcc-c++ fmt-devel libicu-devel sqlite-devel zlib-devel flac-devel libvorbis-devel opus-devel libid3tag-devel ffmpeg-devel expat-devel pcre2-devel libsndfile-devel mpg123-devel`
 
*I need to build test systems to verify these. Safety not guarnteed.*

### Build & Install Instructions

```bash
git clone https://github.com/subtlecaffeine/mpd-dbcreate.git
cd mpd-dbcreate
meson setup build
ninja -C build
meson install -C build
```

## Usage

```bash
mpd-dbcreate --music-dir <path> --database <path> [options]

Options:
  --music-dir <path>   Music directory
  --database <path>    Database file
  --update             Update existing database (incremental scan)
  --update-path <path> Update only specified subdirectory (use with --update)
  --stereo             Stereo only
  --multichannel       Multichannel only
  --all                All (default)
  --verbose            Verbose output
  --help               Show help

```

I have found it's best to feed full paths for everything. It should be obvious if it doesn't like your music-dir argument. Not liking --database argument has shown up as a simple database plugin error.

### Examples

Create a database of only stereo content:
```bash
mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --stereo
```

Scan a database of only multichannel content:
```bash
mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --multichannel
```

Create a database of all content:
```bash
mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db --all
```

Update an existing database:

```bash
mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db (--stereo|--multichannel|--all) --update
```
Update a specific directory in the database:

```bash
mpd-dbcreate --music-dir /path/to/media --database /path/to/file.db (--stereo|--multichannel|--all) --update --update-path /path
```

The `--update-path` is relative to `--music-dir`. So if your `music-dir` is `/mnt/music` and you want to update `/mnt/music/newstuff`, --update-path would be `/newstuff`


Paths in the database are all stored relative to `--music-dir`. This means if you move your music directory, you can still use the same database as long as mpd is configured to see the same "root" directory. This helps for scanning on a different machine (like on your NAS) since you only have to scan the same "root" folder you have configured in mpd.

It's been two months since I built the first database with an early version and I've done numerous updates since; both for new media and to test new builds. That database has never been an issue and has made mpd a joy to use since it works the way *I* want it.

As a rough benchmark: It scanned an 8000 file library of 450.3 gigs in about 6.5 minutes; this includes the delay for the numerous ISOs in the library.

## Notes

Please make note of the following things:

- If you get a "simple database" error; check the path of the database you specified.
- Try to use full paths at all times.
- It looks like it hangs on ISO files when using --verbose. It's not. Just wait. I believe it's something with the plugin that I don't want to touch.
- Your music directory is root of the database. Keep this in mind if you want to scan on a different system. 

## Changes
```
28-AUG-2025 - Initial hacking of database tool from mpd-sacd itself. Multichannel, CUE, SACD logic updates.
29-AUG-2025 - Removed systemd, output, and daemonization features where possible. Restored verbose output from systemd hijack. Got --update working.
01-SEP-2025 - After being able to actually test DVD-Audio; modified DVD-Audio plugin to match SACD behavior for track and channel filtering.
24-SEP-2025 - Added --update-path option to update just a specific path in the database and waiting 3 weeks to getting around to testing it.
24-OCT-2025 - Removed dependencies and code not needed, like output plugins, mixers, libmpdclient, chromaprint. Internal Development Release.
01-NOV-2025 - Missed encoders and filters. Wrote documentation (manpage). Tweaked things for release builds. Milestone release: Version 1.0 equivalent.
```

## Bugs & Issues

If you find a bug, please report it at https://github.com/subtlecaffeine/mpd-dbcreate/issues

## License

GPL-2.0-or-later (inherited from MPD). Please see the `COPYING` or `LICENSE` files.

## Credits

Based on Maxim's fork of mpd with SACD and DVD-A plguins: https://sourceforge.net/projects/mpd.sacddecoder.p/ - Thanks Maxim!

Original MPD project: https://www.musicpd.org/
