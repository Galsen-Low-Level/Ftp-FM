/* @file ftpfm.h 
 * @author 2025 Umar Ba <jUmarB@protonmail.com> 
 * */
#if !defined(FTPFM)
#define  FTPFM
#include <sys/cdefs.h>
#include <stdarg.h>

#include "config.h"  

#if !defined(__GNUC__) 
# error  "Require GNU C compiler" 
#endif  

#pragma  GCC  diagnostic  ignored "-Wvarargs" 

#define  __parmreq [static 1] 
#define  __parmreq_(__requested_size) [static __requested_size] 

#define  __null  (__ptr_t) 0  
#define  __bunit  1<<3 
#define  nptr  __null

/*NOTICE:  this macro are used  for annotation*/
#define  _Nullable  
#define  _Opac 
/*!END OF NOTE */

#ifdef  __unused__ 
# define __maybe_unused __unused__ 
#else   
# define __maybe_unused 
#endif

#define  EMPTY_SPACE ( (char[2]){0x20}  )   
#define  DESC(__description)\
  __description

#define  DOM_TITLE(__title, __dump)\
  sprintf(__dump , HTTP_DIRENDER_DOCTYPE , __title);

#define __STR(x)  #x 
#define STR(x) __STR(x)  

#define CRLF \r\n\r\n      
#define HTTP_HEADER_RESPONSE_OK "HTTP/1.1 200 OK" STR(CRLF) 
//TODO : add 404 NO RESOURCE FOUND  

#define  HTTP_EXTF_DEF   html
#define  HTTP_EXTF_ATL   htm
#ifndef  HTML_DEFAULT_RESSOURCE 
# define HTML_DEFAULT_RESSOURCE        "index."STR(HTTP_EXTF_DEF) 
# define HTML_DEFAULT_RESSOURCE_ALT    "index."STR(HTTP_EXTF_ATL) 
#endif  

enum { 
  METHOD, 
#define METHOD METHOD
  RESOURCE ,  
#define RESOURCE RESOURCE 
  VERSION   
#define VERSION VERSION
}; 

#define  hget(__item)  \
  htftp_get_##__item(htftp_reqhdr_t *) 

#if !defined(LISTEN_BACKLOG) 
# define LISTEN_BACKLOG  4 
#endif 


#define UA_CURL   (1 << 1)
#define UA_WGET   (1 << 2)

#define UA_ALL (UA_CURL|UA_WGET) 


//! GET , HOST , USER-AGENT 
#define HTTP_REQUEST_HEADER_LINE      3 
#define HTTP_GLOBAL_CONTENT_DISPATCH  3   

#define  HTTP_REQST_BUFF  sizeof(__ptr_t) <<  (__bunit << 1)  
#define  PATH_MAX_LENGHT  1024  

#define  _rblock(sbyte) [(sbyte)]  

//!NOTE::WARNING: no control on  __ops 
#define  statops(__ops ,  __filed, __member)({   \
    struct stat  __sbuff;                        \
    __ops(__filed , &__sbuff);                   \
    __sbuff.__member ;                           \
    }) 

#define __habsp  (path+1)  

#define  HTFTP_DEFCFG {PF_INET, htons(DEFAULT_PORT) ,htonl(INADDR_ANY)}   
#define __getsockfd(__hf)  ((__hf->_sp) >> 0x10) 
#define __getportnb(__hf)  ((__hf->_sp) &  0xffff)   

#define  SA  struct sockaddr 

_Opac typedef  struct __htftp_protocol_header_t  htftp_protocol_header_t ; 
_Opac typedef  struct __htftp_request_header_t   htftp_reqhdr_t ; 
_Opac typedef  struct __htftp_t                  htftp_t;

typedef  struct __fobject_t               fobject_t ; 
struct __fobject_t {
   char hr_time  _rblock(0xff) ;   //!  human readable  time 
   char hr_size  _rblock(0xff);    //!  human readable  size 
   size_t fsize ;    
   time_t ftime ;  
};

typedef void(*__htftp_fcfg_t)(struct __htftp_t * __restrict__ ,  void * __maybe_unused _Nullable) ; 
#define  htftp_fcfg  __htftp_fcfg_t  

#define TIME_ASC 1    //!  time read format  ascii mode    
#define TIME_NUM 2    //!  time read format  numerical mode 


#define htftp_error(__fcall , ...) \
  do{perror(#__fcall); errx(1 ,  __VA_ARGS__);}while(0)  


/* TODO : enable this macro 
 * #define htftp_errorx(__fcall , ...) \
  do{perror(#__fcall); LOGFATAL(__VA_ARGS__);}while(0)  
*/ 
void htftp_errorx(const char * __fcall , const  char * fmt , ...);

//! For internal use 
static htftp_protocol_header_t *explode(htftp_protocol_header_t * __hproto, char *__restrict__ __raw_data ) ;  
static char *htftp_list_dirent_content(char *__ftype ,  char *__dump) ; 

static void  release_local_alloc(char  **_arr) __attribute((deprecated)); 

static void  htftp_prepare(char *__restrict__ __global_content , ...) ; 
static void  setup_htftp(struct __htftp_t  *__restrict__ __hf , int __socket_fd , int __portnumber) ; 
static void  __use_defconfig(struct __htftp_t* __restrict__ __hf , void * __maybe_unused _Nullable __xtrargs) ;
static char * file_size_human_readable(fobject_t * __restrict__ __fobj); 

/** 
 * @fn htftp_detect_user_agent(struct __htftp_request_header_t * )
 * @brief  detect which user agent is making  a request 
 *         specialy  for curl and wget.
 * @param  struct __htftp_request_header_t *  -  header information  that hold the user agent  type 
 * @param  int   -  user agent  target  can be oring  using flag UA_CURL  OR   UA_WGET 
 * 
 */
static void  htftp_detect_user_agent(struct __htftp_request_header_t * __restrict__ __htfpt_rh ,  int __ua_target); 
static void  append2tablerow(char __item __parmreq,
                                      char __render_buffer  __parmreq, 
                                      char * _Nullable __restrict__ subdirent, 
                                      int  ___show_previous); 

htftp_t  *htftp_start(int  __port_number ,  
                      __htftp_fcfg_t _Nullable __function_configuration, 
                      void * _Nullable  __restrict__ __extra_argument) __attribute__((weak)) ; 
int  htftp_polling(struct __htftp_t  * __restrict__  __hf); 
htftp_reqhdr_t* htftp_parse_request( char __htftp_buffer __parmreq); 
char * htftp_get_requested_content(htftp_reqhdr_t * __restrict__ __hproto,
                                  char * __restrict__ __target_path); 
extern void htftp_close(struct  __htftp_t * __restrict__ __hf );
char * htftp_read_content(int __user_agent , char *__restrict__ __filename , char * __restrict__  __dump) ; 
int htftp_transmission(int  __user_agent, char  __content_delivry __parmreq) ; 
fobject_t * file_detail(fobject_t *__restrict__  __fobj ,
                        char *__restrict__ __fitem,
                        int __tfmtopt); 
#endif 
