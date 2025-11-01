storage_plugins_sources = [
  'LocalStorage.cxx',
]

# WebDAV/CURL storage removed - not needed for database creation
enable_webdav = false
conf.set('ENABLE_WEBDAV', enable_webdav)

if nfs_dep.found()
  storage_plugins_sources += 'NfsStorage.cxx'
endif

# SMB storage removed - not needed for database creation

if enable_udisks
  storage_plugins_sources += 'UdisksStorage.cxx'
endif

storage_plugins = static_library(
  'storage_plugins',
  storage_plugins_sources,
  include_directories: inc,
  dependencies: [
    log_dep,
    dbus_dep,
    nfs_dep,
    input_glue_dep,
    archive_glue_dep,
  ],
)

storage_plugins_dep = declare_dependency(
  link_with: storage_plugins,
  dependencies: [
    storage_api_dep,
    fs_dep,
    time_dep,
  ],
)
