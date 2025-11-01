net_features = configuration_data()

# Network client/server support disabled for mpd-dbcreate
net_features.set('HAVE_TCP', false)
net_features.set('HAVE_IPV6', false)
net_features.set('HAVE_UN', false)

net = static_library(
  'net',
  'FormatAddress.cxx',
  'ToString.cxx',
  'HostParser.cxx',
  'Resolver.cxx',
  'AddressInfo.cxx',
  'StaticSocketAddress.cxx',
  'AllocatedSocketAddress.cxx',
  'SocketAddress.cxx',
  'SocketUtil.cxx',
  'SocketDescriptor.cxx',
  'SocketError.cxx',
  include_directories: inc,
  dependencies: [
    fmt_dep,
  ],
)

net_dep = declare_dependency(
  link_with: net,
  dependencies: [
    system_dep,
    io_dep,
  ],
)

configure_file(output: 'Features.hxx', configuration: net_features)
