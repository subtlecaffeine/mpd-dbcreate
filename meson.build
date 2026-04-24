project(
  'mpd-dbcreate',
  ['c', 'cpp'],
  version: 'Cram It, Lobster!',
  meson_version: '>= 1.2',
  default_options: [
    'c_std=c11',
    'build.c_std=c11',
    'cpp_std=c++23',
    'build.cpp_std=c++23',
    'warning_level=3',
    'buildtype=minsize',
    'b_ndebug=true',
    'b_lto=true',
    'debug=false',
    'strip=true',
    'fmt:cpp_std=c++23',

    # If we build those libraries as Meson subproject, they shall be
    # linked statically into the MPD executable.
    'default_library=static',
    'curl:default_library=static',
    'expat:default_library=static',
    'flac:default_library=static',
    'fmt:default_library=static',
    'gtest:default_library=static',
    'id3tag:default_library=static',
    'lame:default_library=static',
    'libnpupnp:default_library=static',
    'libsndfile:default_library=static',
    'liburing:default_library=static',
    'ogg:default_library=static',
    'openssl:default_library=static',
    'opus:default_library=static',
    'sqlite3:default_library=static',
    'vorbis:default_library=static',

    # Not interested in compiler warnings from subprojects.
    'curl:werror=false',
    'curl:warning_level=0',
    'expat:werror=false',
    'expat:warning_level=0',
    'flac:werror=false',
    'flac:warning_level=0',
    'fmt:warning_level=0',
    'gtest:warning_level=0',
    'id3tag:werror=false',
    'id3tag:warning_level=0',
    'lame:werror=false',
    'lame:warning_level=0',
    'libmicrohttpd:warning_level=0',
    'libnpupnp:warning_level=0',
    'libsndfile:warning_level=0',
    'liburing:warning_level=0',
    'sqlite3:warning_level=0',
    'ogg:werror=false',
    'ogg:warning_level=0',
    'openssl:werror=false',
    'openssl:warning_level=0',
    'opus:werror=false',
    'opus:warning_level=0',
    'vorbis:warning_level=0',

    # Disable subprojects features we don't need
    'curl:tool=disabled',
    'curl:tests=disabled',
    'curl:unittests=disabled',
    'curl:brotli=disabled',
    'curl:cookies=disabled',
    'curl:progress-meter=disabled',
    'curl:zstd=disabled',
    'curl:kerberos-auth=disabled',
    'curl:negotiate-auth=disabled',
    'curl:gss-api=disabled',
    'curl:ntlm=disabled',
    'curl:ssh=disabled',
    'curl:dict=disabled',
    'curl:file=disabled',
    'curl:ftp=disabled',
    'curl:gopher=disabled',
    'curl:imap=disabled',
    'curl:ldap=disabled',
    'curl:ldaps=disabled',
    'curl:mqtt=disabled',
    'curl:pop3=disabled',
    'curl:rtmp=disabled',
    'curl:rtsp=disabled',
    'curl:smb=disabled',
    'curl:smtp=disabled',
    'curl:telnet=disabled',
    'curl:tftp=disabled',
    'lame:decoder=false',
    'lame:tools=disabled',
    'libsndfile:examples=false',
    'libsndfile:external_libs=disabled',
    'libsndfile:mpeg=disabled',
    'libsndfile:programs=false',
    'libsndfile:sndio=disabled',
    'openssl:build_cli=false',
    'openssl:asm=disabled',
    'opus:docs=disabled',
    'opus:extra-programs=disabled',
    'opus:tests=disabled',
  ],
  license: 'GPLv2+',
)

version_cxx = vcs_tag(input: 'src/GitVersion.cxx', output: 'GitVersion.cxx')

compiler = meson.get_compiler('cpp')
c_compiler = meson.get_compiler('c')

if compiler.get_id() == 'gcc' and compiler.version().version_compare('<12')
  warning('Your GCC version is too old.  You need at least version 12.')
elif compiler.get_id() == 'clang' and compiler.version().version_compare('<14')
  warning('Your clang version is too old.  You need at least version 14.')
endif
if get_option('b_lto')
  add_project_link_arguments('-Wno-odr', language: 'cpp')
endif

version_conf = configuration_data()
version_conf.set_quoted('PACKAGE', meson.project_name())
version_conf.set_quoted('PACKAGE_NAME', meson.project_name())
version_conf.set_quoted('VERSION', meson.project_version())
version_conf.set_quoted('PROTOCOL_VERSION', '0.25.0')
configure_file(output: 'Version.h', configuration: version_conf)

conf = configuration_data()
conf.set_quoted('SYSTEM_CONFIG_FILE_LOCATION', join_paths(get_option('prefix'), get_option('sysconfdir'), 'mpd.conf'))

common_global_cppflags = [
  '-D_GNU_SOURCE',
]

common_cppflags = [
]

test_global_common_flags = [
  '-fvisibility=hidden',
]

test_common_flags = [
  '-ffast-math',
  '-ftree-vectorize',

  '-Wcast-qual',
  '-Wdouble-promotion',
  '-Wmissing-declarations',
  '-Wshadow',
  '-Wunused',
  '-Wvla',
  '-Wwrite-strings',

  # clang specific warning options:
  '-Wunreachable-code-aggressive',
  '-Wused-but-marked-unused',

  # suppress bogus GCC12 warnings in libfmt headers
  '-Wno-stringop-overflow',

  # libfmt causes this warning due to -ffast-math
  '-Wno-nan-infinity-disabled',
]

test_global_cxxflags = test_global_common_flags + [
]

test_global_cflags = test_global_common_flags + [
]

test_cxxflags = test_common_flags + [
  '-fno-threadsafe-statics',
  '-fmerge-all-constants',

  '-Wcomma-subscript',
  '-Wextra-semi',
  '-Wmismatched-tags',
  '-Woverloaded-virtual',
  '-Wsign-promo',
  '-Wsuggest-override',
  '-Wvolatile',
  '-Wvirtual-inheritance',

  '-Wno-missing-field-initializers',

  # a vtable without a dtor is just fine
  '-Wno-non-virtual-dtor',

  # clang specific warning options:
  '-Wcomma',
  '-Wheader-hygiene',
  '-Winconsistent-missing-destructor-override',
]

test_cflags = test_common_flags + [
  '-Wmissing-prototypes',
  '-Wstrict-prototypes',
]

test_ldflags = [
  # make relocations read-only (hardening)
  '-Wl,-z,relro',

  # no lazy binding, please - not worth it for a daemon
  '-Wl,-z,now',
]

if get_option('buildtype') != 'debug'
  test_global_cxxflags += [
    '-ffunction-sections',
    '-fdata-sections',
  ]
  test_global_cflags += [
    '-ffunction-sections',
    '-fdata-sections',
  ]
  test_ldflags += [
    '-Wl,--gc-sections',
  ]
endif

if get_option('fuzzer')
  fuzzer_flags = []
  if get_option('libfuzzer')
    fuzzer_flags += ['-fsanitize=fuzzer']
  endif
  if get_option('b_sanitize') == 'none'
    fuzzer_flags += ['-fsanitize=address,undefined']
  endif
  add_global_arguments(fuzzer_flags, language: 'cpp')
  add_global_arguments(fuzzer_flags, language: 'c')
  add_global_link_arguments(fuzzer_flags, language: 'cpp')
endif

add_global_arguments(compiler.get_supported_arguments(test_global_cxxflags), language: 'cpp')
add_global_arguments(c_compiler.get_supported_arguments(test_global_cflags), language: 'c')
add_project_arguments(compiler.get_supported_arguments(test_cxxflags), language: 'cpp')
add_project_arguments(c_compiler.get_supported_arguments(test_cflags), language: 'c')
add_project_link_arguments(compiler.get_supported_link_arguments(test_ldflags), language: 'cpp')

is_linux = host_machine.system() == 'linux'
is_android = false  # Android support removed
is_darwin = host_machine.system() == 'darwin'
is_windows = host_machine.system() == 'windows'

# Android support removed

if is_windows
  common_cppflags += [
    # enable Windows Vista APIs
    '-DWINVER=0x0600', '-D_WIN32_WINNT=0x0600',

    # enable Unicode support (TCHAR=wchar_t) in the Windows API (macro
    # "UNICODE) and the C library (macro "_UNICODE")
    '-DUNICODE', '-D_UNICODE',

    # enable strict type checking in the Windows API headers
    '-DSTRICT',

    # reduce header bloat by disabling obscure and obsolete Windows
    # APIs
    '-DWIN32_LEAN_AND_MEAN',

    # disable more Windows APIs which are not used by MPD
    '-DNOGDI', '-DNOBITMAP', '-DNOCOMM',
    '-DNOUSER',

    # reduce COM header bloat
    '-DCOM_NO_WINDOWS_H',

    # disable Internet Explorer specific APIs
    '-D_WIN32_IE=0',
  ]

  subdir('win32')
endif

# Android support removed from mpd-dbcreate

add_global_arguments(common_global_cppflags, language: 'c')
add_global_arguments(common_global_cppflags, language: 'cpp')

add_project_arguments(common_cppflags, language: 'c')
add_project_arguments(common_cppflags, language: 'cpp')

# mpd-dbcreate is not a daemon - it's a standalone utility
enable_daemon = false
conf.set('ENABLE_DAEMON', false)

conf.set('HAVE_GETPWNAM_R', compiler.has_function('getpwnam_r'))
conf.set('HAVE_INITGROUPS', compiler.has_function('initgroups'))
conf.set('HAVE_FNMATCH', compiler.has_function('fnmatch'))
conf.set('HAVE_STRNDUP', compiler.has_function('strndup', prefix: '#define _GNU_SOURCE\n#include <string.h>'))
conf.set('HAVE_STRCASESTR', compiler.has_function('strcasestr'))

conf.set('HAVE_PRCTL', is_linux)

if not get_option('syslog').disabled()
  if compiler.has_function('syslog')
    conf.set('HAVE_SYSLOG', true)
  elif get_option('syslog').enabled()
    error('syslog() not found')
  endif
endif

enable_database = get_option('database')

enable_inotify = get_option('inotify') and is_linux and enable_database
conf.set('ENABLE_INOTIFY', enable_inotify)

enable_sacdiso = get_option('sacdiso')
conf.set('ENABLE_SACDISO', enable_sacdiso)

enable_dvdaiso = get_option('dvdaiso')
conf.set('ENABLE_DVDAISO', enable_dvdaiso)

inc = include_directories(
  'src',

  # for the generated config.h
  '.',
)

if enable_sacdiso or enable_dvdaiso
  inc = include_directories(
    'src',
	'.',
	'src/lib/sacdiso',
	'src/lib/sacdiso/libdstdec',
	'src/lib/sacdiso/libdstdec/binding',
	'src/lib/sacdiso/libdstdec/decoder',
	'src/lib/dvdaiso',
	'src/lib/dvdaiso/udf',
  )
endif

subdir('src/lib/fmt')

log = static_library(
  'log',
  'src/Log.cxx',
  'src/LogBackend.cxx',
  include_directories: inc,
  dependencies: fmt_dep,
)

log_dep = declare_dependency(
  link_with: log,
  dependencies: fmt_dep,
)

sources = [
  version_cxx,
  'src/Main.cxx',
  'src/config/PartitionConfig.cxx',
  'src/config/PlayerConfig.cxx',
  'src/config/ReplayGainConfig.cxx',
  'src/Idle.cxx',
  'src/decoder/Thread.cxx',
  'src/decoder/Control.cxx',
  'src/decoder/Bridge.cxx',
  'src/LogInit.cxx',
  'src/Instance.cxx',
  'src/MusicBuffer.cxx',
  'src/MusicPipe.cxx',
  'src/MusicChunk.cxx',
  'src/MusicChunkPtr.cxx',
  'src/Mapper.cxx',
  'src/Partition.cxx',
  'src/Permission.cxx',
  'src/player/CrossFade.cxx',
  'src/player/Thread.cxx',
  'src/player/Control.cxx',
  'src/PlaylistError.cxx',
  'src/db/PlaylistVector.cxx',
  'src/queue/Queue.cxx',
  'src/queue/Save.cxx',
  'src/queue/Selection.cxx',
  'src/queue/Playlist.cxx',
  'src/queue/PlaylistControl.cxx',
  'src/queue/PlaylistEdit.cxx',
  'src/queue/PlaylistTag.cxx',
  'src/queue/PlaylistState.cxx',
  'src/SongUpdate.cxx',
  'src/SongSave.cxx',
  'src/StateFile.cxx',
  'src/StateFileConfig.cxx',
  'src/TagSave.cxx',
  'src/TagFile.cxx',
  'src/TagStream.cxx',
  'src/mixer/Memento.cxx',
  'src/StatsStub.cxx',
  'src/StubFunctions.cxx',
]

if is_windows
  sources += [
    'src/win32/Win32Main.cxx',
  ]
endif

# Android support removed - always use non-Android sources
sources += [
  'src/unix/SignalHandlers.cxx',
]

if enable_daemon
  sources += 'src/unix/Daemon.cxx'
endif

if enable_database
  sources += [
    'src/storage/StorageState.cxx',
    'src/queue/PlaylistUpdate.cxx',
  ]
endif

subdir('src/util')
subdir('src/cmdline')
subdir('src/time')
subdir('src/lib/icu')
subdir('src/fs')
subdir('src/io')
subdir('src/io/uring')
subdir('src/system')
subdir('src/system/linux')
subdir('src/thread')
subdir('src/net')
subdir('src/event')
subdir('src/win32')

subdir('src/apple')

subdir('src/fs/glue')

subdir('src/config')
subdir('src/pcm')

subdir('src/lib/dbus')
subdir('src/lib/smbclient')
subdir('src/lib/zlib')

# subdir('src/lib/alsa')  # Disabled - not needed for database creation
alsa_dep = declare_dependency()  # Empty dependency for compatibility
# subdir('src/lib/chromaprint')  # Disabled - not needed for database creation
chromaprint_dep = declare_dependency()  # Empty dependency for compatibility
subdir('src/lib/curl')
subdir('src/lib/expat')
subdir('src/lib/ffmpeg')
subdir('src/lib/gcrypt')
subdir('src/lib/nfs')
subdir('src/lib/nlohmann_json')
# subdir('src/lib/oss')  # Disabled - not needed for database creation
enable_oss = false  # Disabled for database creation
subdir('src/lib/pcre')
# subdir('src/lib/pipewire')  # Disabled - not needed for database creation
pipewire_dep = declare_dependency()  # Empty dependency for compatibility
# subdir('src/lib/pulse')  # Disabled - not needed for database creation
pulse_dep = declare_dependency()  # Empty dependency for compatibility
# subdir('src/lib/sndio')  # Disabled - not needed for database creation
libsndio_dep = declare_dependency()  # Empty dependency for compatibility
subdir('src/lib/sqlite')
subdir('src/lib/systemd')  # Provides empty systemd_dep for compatibility
subdir('src/lib/upnp')

subdir('src/lib/crypto')

subdir('src/zeroconf')

subdir('src/tag')
subdir('src/neighbor')
subdir('src/input')
subdir('src/archive')
subdir('src/filter')  # Stub implementations for compatibility
subdir('src/mixer')
subdir('src/output')
subdir('src/lib/xiph')
subdir('src/decoder')
# subdir('src/encoder')  # Removed - not needed for database creation
encoder_glue_dep = declare_dependency()  # Empty dependency for compatibility
subdir('src/song')
subdir('src/playlist')

if enable_sacdiso or enable_dvdaiso
  # ixml is required by the SACD/DVD-Audio metabase code (<upnp/ixml.h>).
  # It ships as part of libupnp (pupnp) or libnpupnp; prefer pupnp for
  # portability across distros, fall back to npupnp.
  ixml_dep = dependency('libupnp', required: true)
  if not ixml_dep.found()
    ixml_dep = dependency('libnpupnp', required: true)
  endif
  if not ixml_dep.found()
    error('SACD/DVD-Audio support requires libupnp or libnpupnp (for ixml)')
  endif
endif

if enable_sacdiso
  subdir('src/lib/sacdiso')
endif

if enable_dvdaiso
  subdir('src/lib/dvdaiso')
endif

if curl_dep.found()
  sources += 'src/RemoteTagCache.cxx'
endif

if sqlite_dep.found()
  sources += [
    'src/sticker/Database.cxx',
    'src/sticker/SongSticker.cxx',
    'src/sticker/TagSticker.cxx',
    'src/sticker/AllowedTags.cxx',
    'src/sticker/CleanupService.cxx',
  ]
endif

basic = static_library(
  'basic',
  'src/ReplayGainMode.cxx',
  'src/SingleMode.cxx',
  'src/ConsumeMode.cxx',
  include_directories: inc,
)

basic_dep = declare_dependency(
  link_with: basic,
)

if enable_database
  subdir('src/storage')
else
  storage_glue_dep = dependency('', required: false)
endif
subdir('src/db')


if archive_glue_dep.found()
  sources += [
    'src/TagArchive.cxx',
  ]

  if enable_database
    sources += ['src/db/update/Archive.cxx']
  endif
endif

if is_windows
  sources += windows_resources
endif

link_args = []
more_deps = []
# Android support removed - always use executable type
target_type = 'executable'
target_name = 'mpd-dbcreate'
install_dir = get_option('bindir')

if enable_sacdiso
  more_deps += [
    sacdiso_dep,
  ]
endif

if enable_dvdaiso
  more_deps += [
    dvdaiso_dep,
  ]
endif

# The mpd-dbcreator utility is a specialized database creator that
# uses MPD's codebase but with modified behavior for filtering
# multichannel content. It's just hacked mpd.'

configure_file(output: 'config.h', configuration: conf)

# MPD Database Creator utility
# Build source list with our Main.cxx and additional update sources
db_creator_sources = [
  version_cxx,
  'src/Main.cxx',
  'src/db/update/FilteredSongUpdate.cxx',
  'src/db/update/CueValidator.cxx',
]

# Add all source files from the main sources list except the old sources[0] version_cxx
# and sources[1] which was the old Main.cxx placeholder
source_index = 0
foreach src : sources
  if source_index <= 1
    # Skip version_cxx and the old Main.cxx entry
    source_index += 1
  else
    db_creator_sources += src
    source_index += 1
  endif
endforeach

mpd_dbcreate = executable(
  'mpd-dbcreate',
  db_creator_sources,
  include_directories: inc,
  dependencies: [
    cmdline_dep,
    basic_dep,
    config_dep,
    fs_dep,
    net_dep,
    util_dep,
    event_dep,
    thread_dep,
    input_glue_dep,
    archive_glue_dep,
    decoder_glue_dep,
    playlist_glue_dep,
    db_glue_dep,
    storage_glue_dep,
    song_dep,
    # so log systemd!
    sqlite_dep,
    neighbor_glue_dep,
    output_glue_dep,
    # encoder_glue_dep,  # Removed - not needed for database creation
    mixer_glue_dep,
    more_deps,
    fmt_dep,
  ],
  link_args: link_args,
  install: true,
  install_dir: get_option('bindir')
)

# dropped systemd like a bad habbit because we quit daemon life

# Android deleted because why would you run this on a phone?
install_data(
  'mpd.svg',
  install_dir: join_paths(get_option('datadir'), 'icons', 'hicolor', 'scalable', 'apps'),
)

install_data(
  'AUTHORS', 'COPYING', 'README.md',
  install_dir: join_paths(get_option('datadir'), 'doc', meson.project_name()),
)

subdir('doc')

if get_option('test')
  subdir('test')
endif

if get_option('fuzzer')
  subdir('test/fuzzer')
endif
