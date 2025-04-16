project('FtpFM', 'c',
  version : '0.1b',
  default_options : ['c_std=gnu99'  'warning_level=3'])

pkg=import('pkgconfig')  

cc = get_compiler('c')

add_project_arguments(
  cc.get_supported_arguments(
  '-Wchar-subscripts',
  '-Wempty-body',
  '-Wformat',
  '-Wformat=2',
  '-Wformat-nonliteral',
  '-Wformat-security',
  '-Wformat-y2k',
  '-Winit-self',
  '-Winline',
  '-Wint-conversion',
  '-Wmissing-declarations',
  '-Wmissing-format-attribute',
  '-Wpointer-arith',
  '-Wshadow',
  '-Wsign-compare',
    ),
  language:'c'
  )  

ftpfm=[
	'src/ftpfm.c'
]

ftpfm_lp=[
	'src/ftpf_logprint.c'   
]

ftpfm_lp_so = shared_library('logp' , 
executable(meson.project_name() ,
           'main.c', 
		   include_directories('include'), 
           install : true)
