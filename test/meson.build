

simple_test_files = [
  'test_crtbp_system.cpp',
  'test_integration.cpp',
]

foreach f: simple_test_files
  t = executable(f, f, dependencies: [crtbp_dep, boost_dep])
  test(f, t)
endforeach
