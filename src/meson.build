source_files   = files('CrtbpSystem.cpp')
public_headers = files('CrtbpSystem.hpp')

crtbp_lib = library('crtbp', source_files, dependencies: boost_dep)
crtbp_dep = declare_dependency(link_with: crtbp_lib, include_directories: inc_dir)

install_headers(public_headers)

