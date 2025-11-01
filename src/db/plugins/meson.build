db_plugins_sources = [
  '../../PlaylistDatabase.cxx',
  '../Registry.cxx',
  '../Helpers.cxx',
  '../VHelper.cxx',
  '../UniqueTags.cxx',
  'simple/DatabaseSave.cxx',
  'simple/DirectorySave.cxx',
  'simple/Directory.cxx',
  'simple/Song.cxx',
  'simple/SongSort.cxx',
  'simple/Mount.cxx',
  'simple/SimpleDatabasePlugin.cxx',
]

if upnp_dep.found()
  db_plugins_sources += [
    'upnp/UpnpDatabasePlugin.cxx',
    'upnp/Tags.cxx',
    'upnp/ContentDirectoryService.cxx',
    'upnp/Directory.cxx',
    'upnp/Object.cxx',
  ]
endif

# libmpdclient support removed - not needed for database creation
libmpdclient_dep = dependency('', required: false)
conf.set('ENABLE_LIBMPDCLIENT', false)

db_plugins = static_library(
  'db_plugins',
  db_plugins_sources,
  include_directories: inc,
  dependencies: [
    upnp_dep,
    pcre_dep,
    libmpdclient_dep,
    log_dep,
    zlib_dep,
  ],
)

db_plugins_dep = declare_dependency(
  link_with: db_plugins,
  dependencies: [
    db_api_dep,
    storage_api_dep,
    config_dep,
  ],
)
