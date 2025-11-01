output_plugins_sources = [
  'NullOutputPlugin.cxx',
]

output_plugins_deps = [
  output_api_dep,
  config_dep,
  tag_dep,
  log_dep,
]

need_encoder = false
need_wave_encoder = false



# Define empty dependencies to avoid build errors


output_plugins = static_library(
  'output_plugins',
  output_plugins_sources,
  include_directories: inc,
  dependencies: output_plugins_deps,
)

output_plugins_dep = declare_dependency(
  link_with: output_plugins,
  dependencies: output_plugins_deps,
)
