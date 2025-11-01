# STUB FILE - Filter support removed for mpd-dbcreate
# Minimal build file for stub implementations

filter_api = static_library(
  'filter_api',
  'Filter.cxx',
  include_directories: inc,
)

filter_api_dep = declare_dependency(
  link_with: filter_api,
)

# Empty stub library for plugin dependencies
filter_plugins_dep = declare_dependency()

# Empty stub library for filter glue dependencies
filter_glue_dep = declare_dependency(
  dependencies: [
    filter_api_dep,
  ],
)
