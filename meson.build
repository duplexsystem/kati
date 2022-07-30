project('kati', ['cpp'],
    version: '0.0.1',
    default_options: [
        'buildtype=debugoptimized', 'warning_level=2', 'cpp_rtti=false',
        'cpp_std=c++17'
    ],
    meson_version: '>=0.50'
)

thread_dep = dependency('threads')
rt_dep = dependency('rt', required: false)

subdir('src')
