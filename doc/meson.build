sphinx = find_program('sphinx-build', required: get_option('documentation'))
if not sphinx.found()
  subdir_done()
endif

if get_option('manpages')
  custom_target(
    'Manpage documentation',
    output: ['mpd-dbcreate.1'],
    input: ['mpd-dbcreate.1.rst', 'conf.py'],
    command: [sphinx, '-q', '-b', 'man', '-d', '@OUTDIR@/man_doctrees', meson.current_source_dir(), '@OUTDIR@'],
    build_by_default: true,
    install: true,
    install_dir: [join_paths(get_option('mandir'), 'man1')],
  )
endif

