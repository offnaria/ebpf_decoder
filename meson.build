project('ebpf_decoder', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

exe = executable('ebpf_decoder', [
    'src/main.cpp',
    'src/hello.cpp'
  ],
  install : true)

test('basic', exe)
