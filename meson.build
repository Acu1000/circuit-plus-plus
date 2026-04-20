project(
  'circuitsim',
  'cpp',
  version : '0.1',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++20'],
)

include_dirs = include_directories('include')

lib = library(
  'circuitsim',
  'src/comps/component.cpp',
  'src/comps/resistor.cpp',
  'src/comps/dcpower.cpp',
  'src/comps/voltmeter.cpp',
  'src/comps/ammeter.cpp',
  'src/parts/node.cpp',
  'src/parts/terminal.cpp',
  'src/simulation/simulation.cpp',
  'src/simulation/mna_equation.cpp',
  'src/simulation/circuit.cpp',
  include_directories : include_dirs
)

demo_exe = executable(
  'circuitsim_demo',
  'demos/main.cpp',
  link_with: lib,
  install : true,
  include_directories : include_dirs
)


gtest_dep = dependency('gtest', main: true)

test_exe = executable(
  'circuitsim_tests',
  'tests/tests.cpp',
  link_with: lib,
  dependencies: gtest_dep,
  include_directories : include_dirs
)

test('basic_tests', test_exe)