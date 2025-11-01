input_plugins_sources = [
  'FileInputPlugin.cxx',
]

if uring_dep.found()
  input_plugins_sources += 'UringInputPlugin.cxx'
endif

# Streaming/playback-only plugins removed from mpd-dbcreate:
# - ALSA input (audio capture for playback)
# - CURL (HTTP/streaming)
# - MMS (streaming protocol)
# - Qobuz (commercial streaming service)
# - SMB (network shares - broken in MPD)
# - CDIO_PARANOIA (CD playback)

# Create empty dependencies for removed plugins to maintain compatibility
libcdio_paranoia_dep = declare_dependency()
input_features.set('ENABLE_CDIO_PARANOIA', false)

libmms_dep = declare_dependency()
input_features.set('ENABLE_MMS', false)

enable_qobuz = false
input_features.set('ENABLE_QOBUZ', false)

if ffmpeg_dep.found()
  input_plugins_sources += 'FfmpegInputPlugin.cxx'
endif

if nfs_dep.found()
  input_plugins_sources += 'NfsInputPlugin.cxx'
endif

input_plugins = static_library(
  'input_plugins',
  input_plugins_sources,
  include_directories: inc,
  dependencies: [
    input_api_dep,
    input_basic_dep,
    log_dep,
    ffmpeg_dep,
    nfs_dep,
  ],
)

input_plugins_dep = declare_dependency(
  link_with: input_plugins,
  dependencies: [
    input_api_dep,
    pcm_dep,
  ],
)
