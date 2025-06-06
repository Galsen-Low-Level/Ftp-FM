# + @file  meson.build
# + @breif receip  build for ftpfm 
# + @author  Umar Ba jUmarB@protonmail.com  <github/Jukoo>

project('FtpFM', 'c',
  version : '0.1b',
  default_options : ['c_std=gnu99', 'warning_level=3'])

pkg=import('pkgconfig')  

cc = meson.get_compiler('c')

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
  '-DARGHLPER', 
  language:'c'
  )  

cfg_data =  configuration_data(
  { 'PROJECT_VERSION': '0.1b' }
  )

#+ Generate  Configuration file from config/config.h.in ->  config.h
cfg_file = configure_file( 
  input:'config/config.h.in', 
  output:'config.h',
  configuration:cfg_data
  )

inc_dir  = include_directories('include')

#+ Arghlp  as subproject for argument parsing and generate usage  
libarghlp_proj = subproject('Arghlp')
arghlp_dep  = libarghlp_proj.get_variable('arghlp_dep') 

libminilog_proj= subproject('Minilog') 
minilog_dep =  libminilog_proj.get_variable('minilog_so_decl') 


ftpfm       = ['src/ftpfm.c']
ftpfm_so    = shared_library('ftpfm',ftpfm, include_directories:[inc_dir] , dependencies:[minilog_dep],soversion:meson.project_version()) 


source_file_entry='main.c'

executable(meson.project_name(),
           source_file_entry,
		   include_directories:[inc_dir],
           link_with:[ftpfm_so, ], 
           dependencies:[arghlp_dep], 
           install : true) 
