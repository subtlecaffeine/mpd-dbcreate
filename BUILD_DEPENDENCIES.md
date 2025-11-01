# Build Dependencies for mpd-dbcreate

## Build System Requirements

**Required:**
- **Meson** >= 1.2
- **Ninja** (build backend)
- **C++ compiler** with C++23 support (GCC >= 12 or Clang >= 14)
- **C compiler** with C11 support

## Core Dependencies

**Always Required:**
- **fmt** >= 9 - String formatting library

## Common Optional Dependencies

These are auto-detected and enabled if found. Most users will want these for full functionality:

### Audio Format Support
- **FFmpeg** (libavformat >= 58.12, libavcodec >= 58.18, libavutil >= 56.14) - Broad codec support
- **FLAC** >= 1.2 - FLAC format
- **Vorbis + Ogg** - Ogg Vorbis format
- **Opus** - Opus format
- **libsndfile** - WAV, AIFF, and other formats
- **libmpg123** - MP3 decoder

### Metadata/Tag Support
- **libid3tag** - ID3 tags for MP3 files

### Database & Storage
- **SQLite3** >= 3.7.3 - Sticker database
- **zlib** - Database compression

### Character Encoding
- **ICU** >= 50 - Unicode handling (recommended)
- **iconv** - Character conversion (alternative to ICU)

### Network Support
- **libnfs** >= 4 - NFS protocol (optional, for scanning NFS shares)

### Other
- **Expat** - XML parsing for playlists
- **libpcre2-8** - Regular expression support

## Additional Decoders

All optional, auto-detected if available:

- **WavPack** >= 5 - WavPack lossless format
- **libmad** - Alternative MP3 decoder
- **libfaad** - AAC decoder
- **libmpcdec** - Musepack decoder
- **AdPlug** - AdLib sound emulation
- **FluidSynth** >= 1.1 - MIDI via SoundFont synthesis
- **libgme** >= 0.6 - Video game music files
- **libsidplayfp** >= 1.8 - C64 SID music files
- **libaudiofile** >= 0.3 - Audio file library decoder
- **libmikmod** >= 3.2 - MOD/tracker music files
- **libmodplug** - Alternative MOD decoder
- **OpenMPT** - Modern tracker music decoder
- **WildMidi** - MIDI decoder

## Archive Format Support

All optional:

- **libbz2** - bzip2 compressed archives
- **libiso9660** - ISO9660 CD image support
- **zziplib** >= 0.13 - ZIP archive support

## Linux-Specific

All optional:

- **liburing** >= 2.3 - io_uring async I/O (performance boost)
- **D-Bus** - D-Bus integration
- **inotify** - Built-in (kernel feature for auto-update)

## Special Format Support

Built-in libraries (no external dependencies):

- **DVD-Audio ISO** - Support for DVD-Audio ISO images (enabled by default)
- **SACD ISO** - Support for Super Audio CD ISO images (enabled by default)

## Package Installation Commands

### Debian/Ubuntu

```bash
sudo apt install meson ninja-build g++ \
  libfmt-dev libicu-dev libsqlite3-dev zlib1g-dev \
  libflac-dev libvorbis-dev libopus-dev libid3tag0-dev \
  libavformat-dev libavcodec-dev libavutil-dev \
  libexpat1-dev libpcre2-dev \
  libsndfile1-dev libmpg123-dev
```

### Fedora/RHEL

```bash
sudo dnf install meson ninja-build gcc-c++ \
  fmt-devel libicu-devel sqlite-devel zlib-devel \
  flac-devel libvorbis-devel opus-devel libid3tag-devel \
  ffmpeg-devel expat-devel pcre2-devel \
  libsndfile-devel mpg123-devel
```

### Arch Linux

```bash
sudo pacman -S meson ninja gcc \
  fmt icu sqlite zlib flac libvorbis opus libid3tag \
  ffmpeg expat pcre2 libsndfile mpg123
```

## Minimal Build

For a minimal build with only the absolutely required dependencies:

```bash
meson setup build -Ddatabase=true
ninja -C build
```

This will build with only **fmt** as a dependency, but many audio formats will not be supported.

## Recommended Build

For a functional database creator with common audio format support, install at minimum:

- fmt
- FFmpeg (provides broad codec coverage)
- FLAC
- Vorbis/Opus
- SQLite3
- libid3tag
- ICU or iconv
- Expat

Then build normally:

```bash
meson setup build
ninja -C build
meson install -C build
```

Meson will auto-detect available dependencies and enable corresponding features.

## Disabling Features

You can explicitly disable optional features during configuration:

```bash
meson setup build \
  -Dnfs=disabled \
  -Dffmpeg=disabled
```

See `meson_options.txt` for a complete list of configurable options.

## Notes

- **FFmpeg** provides the broadest codec support and is highly recommended
- **ICU** is recommended over **iconv** for better Unicode handling
- Most users will want **SQLite3** for sticker database support
- On Linux, **liburing** can provide significant I/O performance improvements
- **NFS** support is optional and only needed if you scan NFS network shares (and don't want to mount them...which is more reliable)
- Streaming plugins (CURL, MMS, Qobuz, SMB, CDIO_PARANOIA, ALSA input) have been removed as they are not needed for database creation
