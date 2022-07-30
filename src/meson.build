kati_cppdefs = []

if get_option('nolog')
    kati_cppdefs += '-DNOLOG'
endif

kati_src = [
    'affinity.cc',
    'command.cc',
    'dep.cc',
    'eval.cc',
    'exec.cc',
    'expr.cc',
    'file.cc',
    'file_cache.cc',
    'fileutil.cc',
    'find.cc',
    'flags.cc',
    'func.cc',
    'io.cc',
    'log.cc',
    'parser.cc',
    'rule.cc',
    'stats.cc',
    'stmt.cc',
    'string_piece.cc',
    'stringprintf.cc',
    'strutil.cc',
    'symtab.cc',
    'timeutil.cc',
    'var.cc',
]

kati_test = [
    'find_test',
    'string_piece_test',
    'strutil_test',
    'strutil_bench',
]

kati_lib = static_library('kati',
    kati_src,
    cpp_args: kati_cppdefs,
    install: false,
    pic: true
)

kati_exe = executable('kati', ['main.cc'],
    link_with: [kati_lib],
    dependencies: [thread_dep, rt_dep],
    cpp_args: kati_cppdefs,
    install: true
)

foreach t: kati_test
    kt = executable(t, [t + '.cc'],
        link_with: [kati_lib], cpp_args: kati_cppdefs, install: false
    )
endforeach
