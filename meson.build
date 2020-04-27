project(
  'crtbp',
  'cpp',
  version: '0.1.0',
  default_options: [
    'cpp_std=c++11',
  ]
)

boost_dep = dependency('boost', version: '>=1.71')
inc_dir = include_directories('src')

subdir('src')
subdir('test')
