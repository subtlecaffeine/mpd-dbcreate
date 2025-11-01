mixer_plugins_sources = [
  'NullMixerPlugin.cxx',
  'SoftwareMixerPlugin.cxx',
]



mixer_plugins = static_library(
  'mixer_plugins',
  mixer_plugins_sources,
  include_directories: inc,
  dependencies: [
    mixer_api_dep,
  ]
)

mixer_plugins_dep = declare_dependency(
  link_with: mixer_plugins,
  dependencies: [
    config_dep,
  ],
)
