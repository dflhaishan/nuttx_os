/* /home/jhs/nuttx/nuttx_os/boards/arm/stm32/stm32f103-alientek/src/generated_symtab.c: Auto-generated symbol table.  Do not edit */

#include <nuttx/config.h>
#include <nuttx/compiler.h>
#include <nuttx/symtab.h>

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <aio.h>
#include <unistd.h>
#include <debug.h>
#include <dirent.h>
#include <stdio.h>
#include <assert.h>
#include <fixedmath.h>
#include <libgen.h>
#include <libintl.h>
#include <sys/boardctl.h>
#include <wchar.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/timex.h>
#include <time.h>
#include <nuttx/crc32.h>
#include <dlfcn.h>
#include <nuttx/queue.h>
#include <sys/epoll.h>
#include <errno.h>
#include <netinet/ether.h>
#include <sys/eventfd.h>
#include <nuttx/binfmt/binfmt.h>
#include <fcntl.h>
#include <strings.h>
#include <fnmatch.h>
#include <netdb.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>
#include <sys/resource.h>
#include <pwd.h>
#include <sys/random.h>
#include <arpa/inet.h>
#include <iconv.h>
#include <inttypes.h>
#include <sys/inotify.h>
#include <nuttx/module.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <wctype.h>
#include <signal.h>
#include <nuttx/tls.h>
#include <lvgl/lvgl.h>
#include <malloc.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <mqueue.h>
#include <nuttx/fs/fs.h>
#include <nuttx/pthread.h>
#include <nuttx/sched.h>
#include <nuttx/semaphore.h>
#include <nuttx/syslog/syslog.h>
#include <nuttx/arch.h>
#include <poll.h>
#include <spawn.h>
#include <sys/prctl.h>
#include <sys/uio.h>
#include <sys/select.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <sys/sendfile.h>
#include <locale.h>
#include <syslog.h>
#include <sys/shm.h>
#include <sys/signalfd.h>
#include <ssp/ssp.h>
#include <sys/sysinfo.h>
#include <nuttx/spawn.h>
#include <sys/timerfd.h>
#include <sys/utsname.h>
#include <sys/wait.h>

const struct symtab_s g_symtab[] =
{
  { "abort", (FAR const void *)&abort },
  { "abs", (FAR const void *)abs },
#if defined(CONFIG_NET)
  { "accept4", (FAR const void *)accept4 },
#endif
#if defined(CONFIG_CLOCK_ADJTIME)
  { "adjtime", (FAR const void *)adjtime },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_cancel", (FAR const void *)aio_cancel },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_error", (FAR const void *)aio_error },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_fsync", (FAR const void *)aio_fsync },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_read", (FAR const void *)aio_read },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_return", (FAR const void *)aio_return },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_suspend", (FAR const void *)aio_suspend },
#endif
#if defined(CONFIG_FS_AIO)
  { "aio_write", (FAR const void *)aio_write },
#endif
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "alarm", (FAR const void *)alarm },
#endif
#if !defined(CONFIG_CPP_HAVE_VARARGS) && defined(CONFIG_DEBUG_ERROR)
  { "_alert", (FAR const void *)_alert },
#endif
  { "alphasort", (FAR const void *)alphasort },
  { "arc4random_buf", (FAR const void *)arc4random_buf },
  { "arc4random", (FAR const void *)&arc4random },
  { "asprintf", (FAR const void *)asprintf },
  { "__assert", (FAR const void *)__assert },
  { "_assert", (FAR const void *)_assert },
#if defined(CONFIG_HAVE_DOUBLE)
  { "atof", (FAR const void *)atof },
#endif
  { "atoi", (FAR const void *)atoi },
#if defined(CONFIG_HAVE_LONG_LONG)
  { "atoll", (FAR const void *)atoll },
#endif
  { "atol", (FAR const void *)atol },
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "b16atan2", (FAR const void *)b16atan2 },
#endif
  { "b16cos", (FAR const void *)b16cos },
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "b16divb16", (FAR const void *)b16divb16 },
#endif
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "b16mulb16", (FAR const void *)b16mulb16 },
#endif
  { "b16sin", (FAR const void *)b16sin },
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "b16sqr", (FAR const void *)b16sqr },
#endif
  { "basename", (FAR const void *)basename },
#if defined(CONFIG_NET)
  { "bind", (FAR const void *)bind },
#endif
#if defined(CONFIG_LIBC_LOCALE_GETTEXT)
  { "bind_textdomain_codeset", (FAR const void *)bind_textdomain_codeset },
#endif
#if defined(CONFIG_LIBC_LOCALE_GETTEXT)
  { "bindtextdomain", (FAR const void *)bindtextdomain },
#endif
#if defined(CONFIG_BOARDCTL)
  { "boardctl", (FAR const void *)boardctl },
#endif
  { "bsearch", (FAR const void *)bsearch },
  { "btowc", (FAR const void *)btowc },
  { "calloc", (FAR const void *)calloc },
  { "cfgetspeed", (FAR const void *)cfgetspeed },
  { "cfsetspeed", (FAR const void *)cfsetspeed },
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "chdir", (FAR const void *)chdir },
#endif
  { "chmod", (FAR const void *)chmod },
  { "chown", (FAR const void *)chown },
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "clearenv", (FAR const void *)&clearenv },
#endif
#if defined(CONFIG_CLOCK_ADJTIME)
  { "clock_adjtime", (FAR const void *)clock_adjtime },
#endif
  { "clock_getcpuclockid", (FAR const void *)clock_getcpuclockid },
  { "clock_getres", (FAR const void *)clock_getres },
  { "clock_gettime", (FAR const void *)clock_gettime },
  { "clock_nanosleep", (FAR const void *)clock_nanosleep },
  { "clock_settime", (FAR const void *)clock_settime },
  { "clock", (FAR const void *)&clock },
  { "closedir", (FAR const void *)closedir },
  { "close", (FAR const void *)close },
#if defined(CONFIG_NET)
  { "connect", (FAR const void *)connect },
#endif
  { "crc32", (FAR const void *)crc32 },
  { "crc32part", (FAR const void *)crc32part },
#if defined(CONFIG_CRYPTO)
  { "crypt_r", (FAR const void *)crypt_r },
#endif
#if defined(CONFIG_CRYPTO)
  { "crypt", (FAR const void *)crypt },
#endif
  { "ctime", (FAR const void *)ctime },
  { "__cxa_atexit", (FAR const void *)__cxa_atexit },
  { "daemon", (FAR const void *)daemon },
#if defined(CONFIG_LIBC_LOCALE_GETTEXT)
  { "dgettext", (FAR const void *)dgettext },
#endif
  { "dirname", (FAR const void *)dirname },
#if defined(CONFIG_LIBC_DLFCN)
  { "dlclose", (FAR const void *)dlclose },
#endif
#if defined(CONFIG_LIBC_DLFCN)
  { "dlerror", (FAR const void *)&dlerror },
#endif
#if defined(CONFIG_LIBC_DLFCN)
  { "dlopen", (FAR const void *)dlopen },
#endif
#if defined(CONFIG_LIBC_DLFCN)
  { "dlsym", (FAR const void *)dlsym },
#endif
#if defined(CONFIG_LIBC_DLFCN)
  { "dlsymtab", (FAR const void *)dlsymtab },
#endif
  { "dq_addafter", (FAR const void *)dq_addafter },
  { "dq_remfirst", (FAR const void *)dq_remfirst },
  { "dq_remlast", (FAR const void *)dq_remlast },
  { "dup2", (FAR const void *)dup2 },
  { "dup", (FAR const void *)dup },
  { "epoll_close", (FAR const void *)epoll_close },
  { "epoll_create1", (FAR const void *)epoll_create1 },
  { "epoll_create", (FAR const void *)epoll_create },
  { "epoll_ctl", (FAR const void *)epoll_ctl },
  { "epoll_pwait", (FAR const void *)epoll_pwait },
  { "epoll_wait", (FAR const void *)epoll_wait },
#if !defined(CONFIG_CPP_HAVE_VARARGS) && defined(CONFIG_DEBUG_ERROR)
  { "_err", (FAR const void *)_err },
#endif
#if defined(CONFIG_BUILD_FLAT)
  { "__errno", (FAR const void *)&__errno },
#endif
  { "ether_ntoa", (FAR const void *)ether_ntoa },
#if defined(CONFIG_EVENT_FD)
  { "eventfd", (FAR const void *)eventfd },
#endif
#if !defined(CONFIG_BINFMT_DISABLE) && !defined(CONFIG_BUILD_KERNEL)
  { "exec", (FAR const void *)exec },
#endif
#if !defined(CONFIG_BINFMT_DISABLE) && defined(CONFIG_LIBC_EXECFUNCS)
  { "execve", (FAR const void *)execve },
#endif
#if defined(CONFIG_LIBC_EXECFUNCS)
  { "execv", (FAR const void *)execv },
#endif
  { "exit", (FAR const void *)exit },
  { "_exit", (FAR const void *)_exit },
  { "_exit", (FAR const void *)_exit },
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "fchdir", (FAR const void *)fchdir },
#endif
  { "fchmod", (FAR const void *)fchmod },
  { "fchown", (FAR const void *)fchown },
#if defined(CONFIG_FILE_STREAM)
  { "fclose", (FAR const void *)fclose },
#endif
  { "fcntl", (FAR const void *)fcntl },
#if defined(CONFIG_FILE_STREAM)
  { "fdopen", (FAR const void *)fdopen },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "feof", (FAR const void *)feof },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "ferror", (FAR const void *)ferror },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fflush", (FAR const void *)fflush },
#endif
  { "ffs", (FAR const void *)ffs },
#if defined(CONFIG_FILE_STREAM)
  { "fgetc", (FAR const void *)fgetc },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fgetpos", (FAR const void *)fgetpos },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fgets", (FAR const void *)fgets },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fgetwc_unlocked", (FAR const void *)fgetwc_unlocked },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fgetwc", (FAR const void *)fgetwc },
#endif
  { "fileno", (FAR const void *)fileno },
#if !defined(CONFIG_FILE_STREAM)
  { "flockfile", (FAR const void *)flockfile },
#endif
  { "fnmatch", (FAR const void *)fnmatch },
#if defined(CONFIG_FILE_STREAM)
  { "fopen", (FAR const void *)fopen },
#endif
#if !defined(CONFIG_BUILD_KERNEL) && defined(CONFIG_ARCH_HAVE_FORK)
  { "fork", (FAR const void *)&fork },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fprintf", (FAR const void *)fprintf },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputc", (FAR const void *)fputc },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputs", (FAR const void *)fputs },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputwc_unlocked", (FAR const void *)fputwc_unlocked },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputwc", (FAR const void *)fputwc },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputws_unlocked", (FAR const void *)fputws_unlocked },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fputws", (FAR const void *)fputws },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fread", (FAR const void *)fread },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "freeaddrinfo", (FAR const void *)freeaddrinfo },
#endif
  { "free", (FAR const void *)free },
  { "fscanf", (FAR const void *)fscanf },
#if defined(CONFIG_FILE_STREAM)
  { "fseek", (FAR const void *)fseek },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "fsetpos", (FAR const void *)fsetpos },
#endif
  { "fstatfs", (FAR const void *)fstatfs },
  { "fstat", (FAR const void *)fstat },
  { "fstatvfs", (FAR const void *)fstatvfs },
  { "fsync", (FAR const void *)fsync },
#if defined(CONFIG_FILE_STREAM)
  { "ftell", (FAR const void *)ftell },
#endif
  { "ftruncate", (FAR const void *)ftruncate },
#if !defined(CONFIG_FILE_STREAM)
  { "ftrylockfile", (FAR const void *)ftrylockfile },
#endif
#if !defined(CONFIG_FILE_STREAM)
  { "funlockfile", (FAR const void *)funlockfile },
#endif
  { "futimens", (FAR const void *)futimens },
#if defined(CONFIG_FILE_STREAM)
  { "fwrite", (FAR const void *)fwrite },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "gai_strerror", (FAR const void *)gai_strerror },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "getaddrinfo", (FAR const void *)getaddrinfo },
#endif
  { "getc", (FAR const void *)getc },
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "get_current_dir_name", (FAR const void *)get_current_dir_name },
#endif
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "getcwd", (FAR const void *)getcwd },
#endif
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "getegid", (FAR const void *)&getegid },
#endif
  { "getegid", (FAR const void *)&getegid },
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "get_environ_ptr", (FAR const void *)&get_environ_ptr },
#endif
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "getenv", (FAR const void *)getenv },
#endif
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "geteuid", (FAR const void *)&geteuid },
#endif
  { "geteuid", (FAR const void *)&geteuid },
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "getgid", (FAR const void *)&getgid },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "gethostbyname2", (FAR const void *)gethostbyname2 },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "gethostbyname", (FAR const void *)gethostbyname },
#endif
  { "gethostname", (FAR const void *)gethostname },
  { "gethostname", (FAR const void *)gethostname },
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "getitimer", (FAR const void *)getitimer },
#endif
#if defined(CONFIG_LIBC_NETDB)
  { "getnameinfo", (FAR const void *)getnameinfo },
#endif
  { "getoptargp", (FAR const void *)&getoptargp },
  { "getopterrp", (FAR const void *)&getopterrp },
  { "getoptindp", (FAR const void *)&getoptindp },
  { "getoptoptp", (FAR const void *)&getoptoptp },
  { "getopt", (FAR const void *)getopt },
  { "getpass", (FAR const void *)getpass },
#if defined(CONFIG_NET)
  { "getpeername", (FAR const void *)getpeername },
#endif
  { "getpid", (FAR const void *)&getpid },
#if defined(CONFIG_SCHED_HAVE_PARENT)
  { "getppid", (FAR const void *)&getppid },
#endif
  { "getpriority", (FAR const void *)getpriority },
  { "getpwnam_r", (FAR const void *)getpwnam_r },
  { "getpwuid_r", (FAR const void *)getpwuid_r },
#if !defined(CONFIG_BUILD_KERNEL)
  { "getrandom", (FAR const void *)getrandom },
#endif
#if defined(CONFIG_NET)
  { "getsockname", (FAR const void *)getsockname },
#endif
#if defined(CONFIG_NET)
  { "getsockopt", (FAR const void *)getsockopt },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "gets", (FAR const void *)gets },
#endif
#if defined(CONFIG_LIBC_LOCALE_GETTEXT)
  { "gettext", (FAR const void *)gettext },
#endif
  { "gettimeofday", (FAR const void *)gettimeofday },
  { "gettimeofday", (FAR const void *)gettimeofday },
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "getuid", (FAR const void *)&getuid },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "getwc", (FAR const void *)getwc },
#endif
  { "gmtime_r", (FAR const void *)gmtime_r },
  { "gmtime", (FAR const void *)gmtime },
  { "htonl", (FAR const void *)htonl },
  { "htonq", (FAR const void *)htonq },
  { "htons", (FAR const void *)htons },
#if defined(CONFIG_LIBC_LOCALE)
  { "iconv_close", (FAR const void *)iconv_close },
#endif
#if defined(CONFIG_LIBC_LOCALE)
  { "iconv", (FAR const void *)iconv },
#endif
#if defined(CONFIG_LIBC_LOCALE)
  { "iconv_open", (FAR const void *)iconv_open },
#endif
  { "imaxabs", (FAR const void *)imaxabs },
  { "inet_addr", (FAR const void *)inet_addr },
#if defined(CONFIG_NET_IPv4)
  { "inet_ntoa", (FAR const void *)inet_ntoa },
#endif
  { "inet_ntop", (FAR const void *)inet_ntop },
  { "inet_pton", (FAR const void *)inet_pton },
#if !defined(CONFIG_CPP_HAVE_VARARGS) && defined(CONFIG_DEBUG_INFO)
  { "_info", (FAR const void *)_info },
#endif
#if defined(CONFIG_FS_NOTIFY)
  { "inotify_add_watch", (FAR const void *)inotify_add_watch },
#endif
#if defined(CONFIG_FS_NOTIFY)
  { "inotify_init1", (FAR const void *)inotify_init1 },
#endif
#if defined(CONFIG_FS_NOTIFY)
  { "inotify_init", (FAR const void *)&inotify_init },
#endif
#if defined(CONFIG_FS_NOTIFY)
  { "inotify_rm_watch", (FAR const void *)inotify_rm_watch },
#endif
#if defined(CONFIG_MODULE)
  { "insmod", (FAR const void *)insmod },
#endif
  { "ioctl", (FAR const void *)ioctl },
  { "isalnum", (FAR const void *)isalnum },
  { "isalpha", (FAR const void *)isalpha },
  { "isascii", (FAR const void *)isascii },
  { "isatty", (FAR const void *)isatty },
  { "isblank", (FAR const void *)isblank },
  { "iscntrl", (FAR const void *)iscntrl },
  { "isdigit", (FAR const void *)isdigit },
  { "isgraph", (FAR const void *)isgraph },
  { "islower", (FAR const void *)islower },
  { "isprint", (FAR const void *)isprint },
  { "ispunct", (FAR const void *)ispunct },
  { "isspace", (FAR const void *)isspace },
  { "isupper", (FAR const void *)isupper },
  { "iswalnum", (FAR const void *)iswalnum },
  { "iswalpha", (FAR const void *)iswalpha },
  { "iswblank", (FAR const void *)iswblank },
  { "iswcntrl", (FAR const void *)iswcntrl },
  { "iswctype", (FAR const void *)iswctype },
  { "iswdigit", (FAR const void *)iswdigit },
  { "iswgraph", (FAR const void *)iswgraph },
  { "iswlower", (FAR const void *)iswlower },
  { "iswprint", (FAR const void *)iswprint },
  { "iswpunct", (FAR const void *)iswpunct },
  { "iswspace", (FAR const void *)iswspace },
  { "iswupper", (FAR const void *)iswupper },
  { "iswxdigit", (FAR const void *)iswxdigit },
  { "isxdigit", (FAR const void *)isxdigit },
  { "kill", (FAR const void *)kill },
  { "labs", (FAR const void *)labs },
  { "lchmod", (FAR const void *)lchmod },
  { "lchown", (FAR const void *)lchown },
  { "lib_dumpbuffer", (FAR const void *)lib_dumpbuffer },
  { "lib_get_stream", (FAR const void *)lib_get_stream },
#if defined(CONFIG_PSEUDOFS_SOFTLINKS)
  { "link", (FAR const void *)link },
#endif
#if defined(CONFIG_FS_AIO)
  { "lio_listio", (FAR const void *)lio_listio },
#endif
#if defined(CONFIG_NET)
  { "listen", (FAR const void *)listen },
#endif
#if defined(CONFIG_HAVE_LONG_LONG)
  { "llabs", (FAR const void *)llabs },
#endif
  { "localtime_r", (FAR const void *)localtime_r },
  { "localtime", (FAR const void *)localtime },
  { "lseek", (FAR const void *)lseek },
  { "lstat", (FAR const void *)lstat },
  { "lutimens", (FAR const void *)lutimens },
  { "lv_anim_init", (FAR const void *)lv_anim_init },
  { "lv_anim_path_ease_out", (FAR const void *)lv_anim_path_ease_out },
  { "lv_anim_path_linear", (FAR const void *)lv_anim_path_linear },
  { "lv_anim_path_overshoot", (FAR const void *)lv_anim_path_overshoot },
  { "lv_anim_set_completed_cb", (FAR const void *)lv_anim_set_completed_cb },
  { "lv_anim_set_delay", (FAR const void *)lv_anim_set_delay },
  { "lv_anim_set_duration", (FAR const void *)lv_anim_set_duration },
  { "lv_anim_set_exec_cb", (FAR const void *)lv_anim_set_exec_cb },
  { "lv_anim_set_path_cb", (FAR const void *)lv_anim_set_path_cb },
  { "lv_anim_set_values", (FAR const void *)lv_anim_set_values },
  { "lv_anim_set_var", (FAR const void *)lv_anim_set_var },
  { "lv_anim_start", (FAR const void *)lv_anim_start },
  { "lv_button_create", (FAR const void *)lv_button_create },
  { "lv_color_hex3", (FAR const void *)lv_color_hex3 },
  { "lv_color_hex", (FAR const void *)lv_color_hex },
  { "lv_display_get_default", (FAR const void *)lv_display_get_default },
  { "lv_display_get_horizontal_resolution", (FAR const void *)lv_display_get_horizontal_resolution },
  { "lv_display_get_vertical_resolution", (FAR const void *)lv_display_get_vertical_resolution },
  { "lv_event_get_code", (FAR const void *)lv_event_get_code },
  { "lv_event_get_target", (FAR const void *)lv_event_get_target },
  { "lv_font_get_line_height", (FAR const void *)lv_font_get_line_height },
  { "lv_font_montserrat_14", (FAR const void *)&lv_font_montserrat_14 },
  { "lv_group_add_obj", (FAR const void *)lv_group_add_obj },
  { "lv_group_get_default", (FAR const void *)lv_group_get_default },
  { "lv_imagebutton_create", (FAR const void *)lv_imagebutton_create },
  { "lv_imagebutton_set_src", (FAR const void *)lv_imagebutton_set_src },
  { "lv_image_create", (FAR const void *)lv_image_create },
  { "lv_image_set_antialias", (FAR const void *)lv_image_set_antialias },
  { "lv_image_set_inner_align", (FAR const void *)lv_image_set_inner_align },
  { "lv_image_set_scale", (FAR const void *)lv_image_set_scale },
  { "lv_image_set_src", (FAR const void *)lv_image_set_src },
  { "lv_indev_active", (FAR const void *)lv_indev_active },
  { "lv_indev_get_gesture_dir", (FAR const void *)lv_indev_get_gesture_dir },
  { "lv_init", (FAR const void *)lv_init },
  { "lv_is_initialized", (FAR const void *)lv_is_initialized },
  { "lv_label_create", (FAR const void *)lv_label_create },
  { "lv_label_set_text_fmt", (FAR const void *)lv_label_set_text_fmt },
  { "lv_label_set_text", (FAR const void *)lv_label_set_text },
  { "lv_log_add", (FAR const void *)lv_log_add },
  { "lv_nuttx_dsc_init", (FAR const void *)lv_nuttx_dsc_init },
  { "lv_nuttx_init", (FAR const void *)lv_nuttx_init },
  { "lv_obj_add_event_cb", (FAR const void *)lv_obj_add_event_cb },
  { "lv_obj_add_flag", (FAR const void *)lv_obj_add_flag },
  { "lv_obj_add_state", (FAR const void *)lv_obj_add_state },
  { "lv_obj_add_style", (FAR const void *)lv_obj_add_style },
  { "lv_obj_align", (FAR const void *)lv_obj_align },
  { "lv_obj_center", (FAR const void *)lv_obj_center },
  { "lv_obj_create", (FAR const void *)lv_obj_create },
  { "lv_obj_delete_anim_completed_cb", (FAR const void *)lv_obj_delete_anim_completed_cb },
  { "lv_obj_get_child", (FAR const void *)lv_obj_get_child },
  { "lv_obj_get_index", (FAR const void *)lv_obj_get_index },
  { "lv_obj_get_style_prop", (FAR const void *)lv_obj_get_style_prop },
  { "lv_obj_has_state", (FAR const void *)lv_obj_has_state },
  { "lv_obj_refresh_ext_draw_size", (FAR const void *)lv_obj_refresh_ext_draw_size },
  { "lv_obj_remove_flag", (FAR const void *)lv_obj_remove_flag },
  { "lv_obj_remove_flag", (FAR const void *)lv_obj_remove_flag },
  { "lv_obj_remove_state", (FAR const void *)lv_obj_remove_state },
  { "lv_obj_remove_style_all", (FAR const void *)lv_obj_remove_style_all },
  { "lv_obj_scroll_to_view", (FAR const void *)lv_obj_scroll_to_view },
  { "lv_obj_set_flex_align", (FAR const void *)lv_obj_set_flex_align },
  { "lv_obj_set_flex_flow", (FAR const void *)lv_obj_set_flex_flow },
  { "lv_obj_set_grid_cell", (FAR const void *)lv_obj_set_grid_cell },
  { "lv_obj_set_grid_dsc_array", (FAR const void *)lv_obj_set_grid_dsc_array },
  { "lv_obj_set_height", (FAR const void *)lv_obj_set_height },
  { "lv_obj_set_scroll_dir", (FAR const void *)lv_obj_set_scroll_dir },
  { "lv_obj_set_scroll_snap_y", (FAR const void *)lv_obj_set_scroll_snap_y },
  { "lv_obj_set_size", (FAR const void *)lv_obj_set_size },
  { "lv_obj_set_style_anim_duration", (FAR const void *)lv_obj_set_style_anim_duration },
  { "lv_obj_set_style_bg_color", (FAR const void *)lv_obj_set_style_bg_color },
  { "lv_obj_set_style_bg_grad_color", (FAR const void *)lv_obj_set_style_bg_grad_color },
  { "lv_obj_set_style_bg_grad_dir", (FAR const void *)lv_obj_set_style_bg_grad_dir },
  { "lv_obj_set_style_bg_image_src", (FAR const void *)lv_obj_set_style_bg_image_src },
  { "lv_obj_set_style_bg_opa", (FAR const void *)lv_obj_set_style_bg_opa },
  { "lv_obj_set_style_border_width", (FAR const void *)lv_obj_set_style_border_width },
  { "lv_obj_set_style_grid_row_align", (FAR const void *)lv_obj_set_style_grid_row_align },
  { "lv_obj_set_style_image_opa", (FAR const void *)lv_obj_set_style_image_opa },
  { "lv_obj_set_style_outline_width", (FAR const void *)lv_obj_set_style_outline_width },
  { "lv_obj_set_style_pad_bottom", (FAR const void *)lv_obj_set_style_pad_bottom },
  { "lv_obj_set_style_pad_left", (FAR const void *)lv_obj_set_style_pad_left },
  { "lv_obj_set_style_pad_right", (FAR const void *)lv_obj_set_style_pad_right },
  { "lv_obj_set_style_pad_row", (FAR const void *)lv_obj_set_style_pad_row },
  { "lv_obj_set_style_pad_top", (FAR const void *)lv_obj_set_style_pad_top },
  { "lv_obj_set_style_text_color", (FAR const void *)lv_obj_set_style_text_color },
  { "lv_obj_set_style_text_font", (FAR const void *)lv_obj_set_style_text_font },
  { "lv_obj_set_width", (FAR const void *)lv_obj_set_width },
  { "lv_obj_set_x", (FAR const void *)lv_obj_set_x },
  { "lv_obj_set_y", (FAR const void *)lv_obj_set_y },
  { "lv_obj_update_layout", (FAR const void *)lv_obj_update_layout },
  { "lv_pct", (FAR const void *)lv_pct },
  { "lv_screen_active", (FAR const void *)lv_screen_active },
  { "lv_screen_active", (FAR const void *)lv_screen_active },
  { "lv_slider_create", (FAR const void *)lv_slider_create },
  { "lv_slider_set_range", (FAR const void *)lv_slider_set_range },
  { "lv_slider_set_value", (FAR const void *)lv_slider_set_value },
  { "lv_snprintf", (FAR const void *)lv_snprintf },
  { "lv_style_init", (FAR const void *)lv_style_init },
  { "lv_style_reset", (FAR const void *)lv_style_reset },
  { "lv_style_set_bg_color", (FAR const void *)lv_style_set_bg_color },
  { "lv_style_set_bg_opa", (FAR const void *)lv_style_set_bg_opa },
  { "lv_style_set_grid_column_dsc_array", (FAR const void *)lv_style_set_grid_column_dsc_array },
  { "lv_style_set_grid_row_align", (FAR const void *)lv_style_set_grid_row_align },
  { "lv_style_set_grid_row_dsc_array", (FAR const void *)lv_style_set_grid_row_dsc_array },
  { "lv_style_set_image_opa", (FAR const void *)lv_style_set_image_opa },
  { "lv_style_set_layout", (FAR const void *)lv_style_set_layout },
  { "lv_style_set_pad_right", (FAR const void *)lv_style_set_pad_right },
  { "lv_style_set_radius", (FAR const void *)lv_style_set_radius },
  { "lv_style_set_text_color", (FAR const void *)lv_style_set_text_color },
  { "lv_style_set_text_font", (FAR const void *)lv_style_set_text_font },
  { "lv_style_set_text_opa", (FAR const void *)lv_style_set_text_opa },
  { "lv_style_set_width", (FAR const void *)lv_style_set_width },
  { "lv_timer_create", (FAR const void *)lv_timer_create },
  { "lv_timer_delete", (FAR const void *)lv_timer_delete },
  { "lv_timer_handler", (FAR const void *)lv_timer_handler },
  { "lv_timer_handler", (FAR const void *)lv_timer_handler },
  { "lv_timer_pause", (FAR const void *)lv_timer_pause },
  { "lv_timer_resume", (FAR const void *)lv_timer_resume },
  { "mallinfo", (FAR const void *)mallinfo },
  { "malloc_size", (FAR const void *)malloc_size },
  { "malloc", (FAR const void *)malloc },
  { "mblen", (FAR const void *)mblen },
  { "mbrlen", (FAR const void *)mbrlen },
  { "mbrtowc", (FAR const void *)mbrtowc },
  { "mbsnrtowcs", (FAR const void *)mbsnrtowcs },
  { "mbsrtowcs", (FAR const void *)mbsrtowcs },
  { "mbstowcs", (FAR const void *)mbstowcs },
  { "mbtowc", (FAR const void *)mbtowc },
  { "memccpy", (FAR const void *)memccpy },
  { "memchr", (FAR const void *)memchr },
  { "memcmp", (FAR const void *)memcmp },
  { "memcpy", (FAR const void *)memcpy },
  { "memmove", (FAR const void *)memmove },
  { "memset", (FAR const void *)memset },
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "mkdir", (FAR const void *)mkdir },
#endif
  { "mkdtemp", (FAR const void *)mkdtemp },
#if defined(CONFIG_PIPES) && CONFIG_DEV_FIFO_SIZE > 0
  { "mkfifo", (FAR const void *)mkfifo },
#endif
  { "mkstemp", (FAR const void *)mkstemp },
  { "mktemp", (FAR const void *)mktemp },
  { "mktime", (FAR const void *)mktime },
  { "mmap", (FAR const void *)mmap },
#if defined(CONFIG_MODULE)
  { "modhandle", (FAR const void *)modhandle },
#endif
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "mount", (FAR const void *)mount },
#endif
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_close", (FAR const void *)mq_close },
#endif
  { "mq_close", (FAR const void *)mq_close },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_getattr", (FAR const void *)mq_getattr },
#endif
  { "mq_getattr", (FAR const void *)mq_getattr },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_notify", (FAR const void *)mq_notify },
#endif
  { "mq_notify", (FAR const void *)mq_notify },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_open", (FAR const void *)mq_open },
#endif
  { "mq_open", (FAR const void *)mq_open },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_receive", (FAR const void *)mq_receive },
#endif
  { "mq_receive", (FAR const void *)mq_receive },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_send", (FAR const void *)mq_send },
#endif
  { "mq_send", (FAR const void *)mq_send },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_setattr", (FAR const void *)mq_setattr },
#endif
  { "mq_setattr", (FAR const void *)mq_setattr },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_timedreceive", (FAR const void *)mq_timedreceive },
#endif
  { "mq_timedreceive", (FAR const void *)mq_timedreceive },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_timedsend", (FAR const void *)mq_timedsend },
#endif
  { "mq_timedsend", (FAR const void *)mq_timedsend },
#if !defined(CONFIG_DISABLE_MQUEUE)
  { "mq_unlink", (FAR const void *)mq_unlink },
#endif
  { "mq_unlink", (FAR const void *)mq_unlink },
  { "msync", (FAR const void *)msync },
  { "munmap", (FAR const void *)munmap },
  { "nanosleep", (FAR const void *)nanosleep },
  { "nice", (FAR const void *)nice },
  { "ntohl", (FAR const void *)ntohl },
  { "ntohq", (FAR const void *)ntohq },
  { "ntohs", (FAR const void *)ntohs },
#if defined(CONFIG_PIPES) && CONFIG_DEV_FIFO_SIZE > 0
  { "nx_mkfifo", (FAR const void *)nx_mkfifo },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "nx_pthread_create", (FAR const void *)nx_pthread_create },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "nx_pthread_exit", (FAR const void *)nx_pthread_exit },
#endif
  { "nxsched_get_stackinfo", (FAR const void *)nxsched_get_stackinfo },
  { "nxsem_clockwait", (FAR const void *)nxsem_clockwait },
#if defined(CONFIG_FS_NAMED_SEMAPHORES)
  { "nxsem_close", (FAR const void *)nxsem_close },
#endif
  { "nxsem_destroy", (FAR const void *)nxsem_destroy },
#if defined(CONFIG_PRIORITY_PROTECT)
  { "nxsem_getprioceiling", (FAR const void *)nxsem_getprioceiling },
#endif
#if defined(CONFIG_FS_NAMED_SEMAPHORES)
  { "nxsem_open", (FAR const void *)nxsem_open },
#endif
  { "nxsem_post_slow", (FAR const void *)nxsem_post_slow },
#if defined(CONFIG_PRIORITY_PROTECT)
  { "nxsem_setprioceiling", (FAR const void *)nxsem_setprioceiling },
#endif
#if defined(CONFIG_PRIORITY_INHERITANCE)
  { "nxsem_set_protocol", (FAR const void *)nxsem_set_protocol },
#endif
  { "nxsem_tickwait", (FAR const void *)nxsem_tickwait },
  { "nxsem_timedwait", (FAR const void *)nxsem_timedwait },
  { "nxsem_trywait_slow", (FAR const void *)nxsem_trywait_slow },
#if defined(CONFIG_FS_NAMED_SEMAPHORES)
  { "nxsem_unlink", (FAR const void *)nxsem_unlink },
#endif
  { "nxsem_wait_slow", (FAR const void *)nxsem_wait_slow },
  { "nx_vsyslog", (FAR const void *)nx_vsyslog },
  { "opendir", (FAR const void *)opendir },
  { "open", (FAR const void *)open },
#if defined(CONFIG_FILE_STREAM)
  { "perror", (FAR const void *)perror },
#endif
#if defined(CONFIG_BUILD_KERNEL)
  { "pgalloc", (FAR const void *)pgalloc },
#endif
#if defined(CONFIG_PIPES) && CONFIG_DEV_PIPE_SIZE > 0
  { "pipe2", (FAR const void *)pipe2 },
#endif
#if defined(CONFIG_PIPES) && CONFIG_DEV_PIPE_SIZE > 0
  { "pipe", (FAR const void *)pipe },
#endif
  { "poll", (FAR const void *)poll },
  { "poll", (FAR const void *)poll },
  { "posix_fallocate", (FAR const void *)posix_fallocate },
  { "posix_memalign", (FAR const void *)posix_memalign },
#if !defined(CONFIG_BINFMT_DISABLE) && defined(CONFIG_LIBC_EXECFUNCS)
  { "posix_spawn", (FAR const void *)posix_spawn },
#endif
  { "ppoll", (FAR const void *)ppoll },
  { "prctl", (FAR const void *)prctl },
  { "pread", (FAR const void *)pread },
  { "preadv", (FAR const void *)preadv },
  { "printf", (FAR const void *)printf },
  { "pselect", (FAR const void *)pselect },
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_destroy", (FAR const void *)pthread_attr_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_getinheritsched", (FAR const void *)pthread_attr_getinheritsched },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_getschedparam", (FAR const void *)pthread_attr_getschedparam },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_getschedpolicy", (FAR const void *)pthread_attr_getschedpolicy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_getstacksize", (FAR const void *)pthread_attr_getstacksize },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_init", (FAR const void *)pthread_attr_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_setinheritsched", (FAR const void *)pthread_attr_setinheritsched },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_setschedparam", (FAR const void *)pthread_attr_setschedparam },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_setschedpolicy", (FAR const void *)pthread_attr_setschedpolicy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_attr_setstacksize", (FAR const void *)pthread_attr_setstacksize },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrierattr_destroy", (FAR const void *)pthread_barrierattr_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrierattr_getpshared", (FAR const void *)pthread_barrierattr_getpshared },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrierattr_init", (FAR const void *)pthread_barrierattr_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrierattr_setpshared", (FAR const void *)pthread_barrierattr_setpshared },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrier_destroy", (FAR const void *)pthread_barrier_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrier_init", (FAR const void *)pthread_barrier_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_barrier_wait", (FAR const void *)pthread_barrier_wait },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cancel", (FAR const void *)pthread_cancel },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_condattr_destroy", (FAR const void *)pthread_condattr_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_condattr_init", (FAR const void *)pthread_condattr_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_condattr_setclock", (FAR const void *)pthread_condattr_setclock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_broadcast", (FAR const void *)pthread_cond_broadcast },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_clockwait", (FAR const void *)pthread_cond_clockwait },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_destroy", (FAR const void *)pthread_cond_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_init", (FAR const void *)pthread_cond_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_signal", (FAR const void *)pthread_cond_signal },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_timedwait", (FAR const void *)pthread_cond_timedwait },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_cond_wait", (FAR const void *)pthread_cond_wait },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_create", (FAR const void *)pthread_create },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_detach", (FAR const void *)pthread_detach },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_SMP)
  { "pthread_getaffinity_np", (FAR const void *)pthread_getaffinity_np },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_getname_np", (FAR const void *)pthread_getname_np },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_getschedparam", (FAR const void *)pthread_getschedparam },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && CONFIG_TLS_NELEM > 0
  { "pthread_getspecific", (FAR const void *)pthread_getspecific },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_gettid_np", (FAR const void *)pthread_gettid_np },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_join", (FAR const void *)pthread_join },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && CONFIG_TLS_NELEM > 0
  { "pthread_key_create", (FAR const void *)pthread_key_create },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && CONFIG_TLS_NELEM > 0
  { "pthread_key_delete", (FAR const void *)pthread_key_delete },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutexattr_destroy", (FAR const void *)pthread_mutexattr_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PRIORITY_PROTECT)
  { "pthread_mutexattr_getprioceiling", (FAR const void *)pthread_mutexattr_getprioceiling },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutexattr_getpshared", (FAR const void *)pthread_mutexattr_getpshared },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PTHREAD_MUTEX_TYPES)
  { "pthread_mutexattr_gettype", (FAR const void *)pthread_mutexattr_gettype },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutexattr_init", (FAR const void *)pthread_mutexattr_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PRIORITY_PROTECT)
  { "pthread_mutexattr_setprioceiling", (FAR const void *)pthread_mutexattr_setprioceiling },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutexattr_setpshared", (FAR const void *)pthread_mutexattr_setpshared },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PTHREAD_MUTEX_TYPES)
  { "pthread_mutexattr_settype", (FAR const void *)pthread_mutexattr_settype },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && !defined(CONFIG_PTHREAD_MUTEX_UNSAFE)
  { "pthread_mutex_consistent", (FAR const void *)pthread_mutex_consistent },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_destroy", (FAR const void *)pthread_mutex_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PRIORITY_PROTECT)
  { "pthread_mutex_getprioceiling", (FAR const void *)pthread_mutex_getprioceiling },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_init", (FAR const void *)pthread_mutex_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_lock", (FAR const void *)pthread_mutex_lock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_PRIORITY_PROTECT)
  { "pthread_mutex_setprioceiling", (FAR const void *)pthread_mutex_setprioceiling },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_timedlock", (FAR const void *)pthread_mutex_timedlock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_trylock", (FAR const void *)pthread_mutex_trylock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_mutex_unlock", (FAR const void *)pthread_mutex_unlock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_once", (FAR const void *)pthread_once },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_rwlock_destroy", (FAR const void *)pthread_rwlock_destroy },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_rwlock_init", (FAR const void *)pthread_rwlock_init },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_rwlock_rdlock", (FAR const void *)pthread_rwlock_rdlock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_rwlock_unlock", (FAR const void *)pthread_rwlock_unlock },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_self", (FAR const void *)pthread_self },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && defined(CONFIG_SMP)
  { "pthread_setaffinity_np", (FAR const void *)pthread_setaffinity_np },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_setname_np", (FAR const void *)pthread_setname_np },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_setschedparam", (FAR const void *)pthread_setschedparam },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_setschedprio", (FAR const void *)pthread_setschedprio },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD) && CONFIG_TLS_NELEM > 0
  { "pthread_setspecific", (FAR const void *)pthread_setspecific },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_sigmask", (FAR const void *)pthread_sigmask },
#endif
#if !defined(CONFIG_DISABLE_PTHREAD)
  { "pthread_yield", (FAR const void *)&pthread_yield },
#endif
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "putenv", (FAR const void *)putenv },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "puts", (FAR const void *)puts },
#endif
  { "putwchar", (FAR const void *)putwchar },
#if defined(CONFIG_FILE_STREAM)
  { "putwc_unlocked", (FAR const void *)putwc_unlocked },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "putwc", (FAR const void *)putwc },
#endif
  { "pwrite", (FAR const void *)pwrite },
  { "pwritev", (FAR const void *)pwritev },
  { "qsort", (FAR const void *)qsort },
  { "raise", (FAR const void *)raise },
  { "rand", (FAR const void *)&rand },
  { "readdir", (FAR const void *)readdir },
  { "readdir_r", (FAR const void *)readdir_r },
#if defined(CONFIG_PSEUDOFS_SOFTLINKS)
  { "readlink", (FAR const void *)readlink },
#endif
  { "read", (FAR const void *)read },
  { "readv", (FAR const void *)readv },
  { "readv", (FAR const void *)readv },
  { "realloc", (FAR const void *)realloc },
#if defined(CONFIG_NET)
  { "recvfrom", (FAR const void *)recvfrom },
#endif
#if defined(CONFIG_NET)
  { "recvmsg", (FAR const void *)recvmsg },
#endif
#if defined(CONFIG_NET)
  { "recv", (FAR const void *)recv },
#endif
  { "remove", (FAR const void *)remove },
  { "rename", (FAR const void *)rename },
#if defined(CONFIG_FILE_STREAM)
  { "rewind", (FAR const void *)rewind },
#endif
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "rmdir", (FAR const void *)rmdir },
#endif
#if defined(CONFIG_MODULE)
  { "rmmod", (FAR const void *)rmmod },
#endif
  { "scandir", (FAR const void *)scandir },
#if defined(CONFIG_SCHED_BACKTRACE)
  { "sched_backtrace", (FAR const void *)sched_backtrace },
#endif
#if defined(CONFIG_SMP)
  { "sched_getaffinity", (FAR const void *)sched_getaffinity },
#endif
  { "sched_getcpu", (FAR const void *)&sched_getcpu },
  { "sched_getparam", (FAR const void *)sched_getparam },
  { "sched_get_priority_max", (FAR const void *)sched_get_priority_max },
  { "sched_get_priority_min", (FAR const void *)sched_get_priority_min },
  { "sched_getscheduler", (FAR const void *)sched_getscheduler },
  { "sched_lockcount", (FAR const void *)&sched_lockcount },
  { "sched_lock", (FAR const void *)&sched_lock },
  { "sched_rr_get_interval", (FAR const void *)sched_rr_get_interval },
#if defined(CONFIG_SMP)
  { "sched_setaffinity", (FAR const void *)sched_setaffinity },
#endif
  { "sched_setparam", (FAR const void *)sched_setparam },
  { "sched_setscheduler", (FAR const void *)sched_setscheduler },
  { "sched_unlock", (FAR const void *)&sched_unlock },
  { "sched_yield", (FAR const void *)&sched_yield },
  { "select", (FAR const void *)select },
  { "sem_getvalue", (FAR const void *)sem_getvalue },
  { "sem_init", (FAR const void *)sem_init },
  { "sem_post", (FAR const void *)sem_post },
  { "sem_wait", (FAR const void *)sem_wait },
  { "sendfile", (FAR const void *)sendfile },
#if defined(CONFIG_NET)
  { "sendmsg", (FAR const void *)sendmsg },
#endif
#if defined(CONFIG_NET)
  { "send", (FAR const void *)send },
#endif
#if defined(CONFIG_NET)
  { "sendto", (FAR const void *)sendto },
#endif
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "setegid", (FAR const void *)setegid },
#endif
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "setenv", (FAR const void *)setenv },
#endif
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "seteuid", (FAR const void *)seteuid },
#endif
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "setgid", (FAR const void *)setgid },
#endif
  { "sethostname", (FAR const void *)sethostname },
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "setitimer", (FAR const void *)setitimer },
#endif
#if defined(CONFIG_LIBC_LOCALE)
  { "setlocale", (FAR const void *)setlocale },
#endif
  { "setlogmask", (FAR const void *)setlogmask },
  { "setpriority", (FAR const void *)setpriority },
#if defined(CONFIG_NET) && defined(CONFIG_NET_SOCKOPTS)
  { "setsockopt", (FAR const void *)setsockopt },
#endif
  { "settimeofday", (FAR const void *)settimeofday },
#if defined(CONFIG_SCHED_USER_IDENTITY)
  { "setuid", (FAR const void *)setuid },
#endif
#if defined(CONFIG_MM_SHM)
  { "shmat", (FAR const void *)shmat },
#endif
#if defined(CONFIG_MM_SHM)
  { "shmctl", (FAR const void *)shmctl },
#endif
#if defined(CONFIG_MM_SHM)
  { "shmdt", (FAR const void *)shmdt },
#endif
#if defined(CONFIG_MM_SHM)
  { "shmget", (FAR const void *)shmget },
#endif
#if defined(CONFIG_FS_SHMFS)
  { "shm_open", (FAR const void *)shm_open },
#endif
#if defined(CONFIG_FS_SHMFS)
  { "shm_unlink", (FAR const void *)shm_unlink },
#endif
#if defined(CONFIG_NET)
  { "shutdown", (FAR const void *)shutdown },
#endif
#if defined(CONFIG_NET)
  { "shutdown", (FAR const void *)shutdown },
#endif
  { "sigaction", (FAR const void *)sigaction },
  { "sigaddset", (FAR const void *)sigaddset },
  { "sigdelset", (FAR const void *)sigdelset },
  { "sigemptyset", (FAR const void *)sigemptyset },
  { "sigfillset", (FAR const void *)sigfillset },
  { "sigismember", (FAR const void *)sigismember },
#if defined(CONFIG_SIGNAL_FD)
  { "signalfd", (FAR const void *)signalfd },
#endif
  { "signal", (FAR const void *)signal },
  { "signal", (FAR const void *)signal },
  { "sigpending", (FAR const void *)sigpending },
  { "sigprocmask", (FAR const void *)sigprocmask },
  { "sigqueue", (FAR const void *)sigqueue },
  { "sigsuspend", (FAR const void *)sigsuspend },
  { "sigtimedwait", (FAR const void *)sigtimedwait },
  { "sigwaitinfo", (FAR const void *)sigwaitinfo },
  { "sigwaitinfo", (FAR const void *)sigwaitinfo },
  { "sleep", (FAR const void *)sleep },
  { "snprintf", (FAR const void *)snprintf },
#if defined(CONFIG_NET)
  { "socketpair", (FAR const void *)socketpair },
#endif
#if defined(CONFIG_NET)
  { "socket", (FAR const void *)socket },
#endif
  { "sprintf", (FAR const void *)sprintf },
  { "sprintf", (FAR const void *)sprintf },
  { "sq_addafter", (FAR const void *)sq_addafter },
  { "sq_remafter", (FAR const void *)sq_remafter },
  { "sq_remfirst", (FAR const void *)sq_remfirst },
  { "sq_remlast", (FAR const void *)sq_remlast },
  { "srand", (FAR const void *)srand },
  { "sscanf", (FAR const void *)sscanf },
  { "sscanf", (FAR const void *)sscanf },
#if defined(CONFIG_STACK_CANARIES)
  { "__stack_chk_fail", (FAR const void *)__stack_chk_fail },
#endif
  { "statfs", (FAR const void *)statfs },
  { "stat", (FAR const void *)stat },
  { "statvfs", (FAR const void *)statvfs },
  { "stpcpy", (FAR const void *)stpcpy },
  { "strcasecmp", (FAR const void *)strcasecmp },
  { "strcasestr", (FAR const void *)strcasestr },
  { "strcat", (FAR const void *)strcat },
  { "strchrnul", (FAR const void *)strchrnul },
  { "strchr", (FAR const void *)strchr },
  { "strcmp", (FAR const void *)strcmp },
#if defined(CONFIG_LIBC_LOCALE)
  { "strcoll", (FAR const void *)strcoll },
#endif
  { "strcpy", (FAR const void *)strcpy },
  { "strcspn", (FAR const void *)strcspn },
  { "strdup", (FAR const void *)strdup },
  { "strerror_r", (FAR const void *)strerror_r },
  { "strerror", (FAR const void *)strerror },
  { "strftime", (FAR const void *)strftime },
  { "strlcpy", (FAR const void *)strlcpy },
  { "strlen", (FAR const void *)strlen },
  { "strncasecmp", (FAR const void *)strncasecmp },
  { "strncat", (FAR const void *)strncat },
  { "strncmp", (FAR const void *)strncmp },
  { "strncpy", (FAR const void *)strncpy },
  { "strndup", (FAR const void *)strndup },
  { "strnlen", (FAR const void *)strnlen },
  { "strpbrk", (FAR const void *)strpbrk },
  { "strrchr", (FAR const void *)strrchr },
  { "strsep", (FAR const void *)strsep },
  { "strspn", (FAR const void *)strspn },
  { "strstr", (FAR const void *)strstr },
#if defined(CONFIG_HAVE_DOUBLE)
  { "strtod", (FAR const void *)strtod },
#endif
  { "strtod", (FAR const void *)strtod },
  { "strtoimax", (FAR const void *)strtoimax },
  { "strtok_r", (FAR const void *)strtok_r },
  { "strtok", (FAR const void *)strtok },
#if defined(CONFIG_HAVE_LONG_LONG)
  { "strtoll", (FAR const void *)strtoll },
#endif
  { "strtol", (FAR const void *)strtol },
#if defined(CONFIG_HAVE_LONG_LONG)
  { "strtoull", (FAR const void *)strtoull },
#endif
  { "strtoull", (FAR const void *)strtoull },
  { "strtoul", (FAR const void *)strtoul },
  { "strtoumax", (FAR const void *)strtoumax },
#if defined(CONFIG_LIBC_LOCALE)
  { "strxfrm", (FAR const void *)strxfrm },
#endif
  { "swab", (FAR const void *)swab },
  { "swprintf", (FAR const void *)swprintf },
#if defined(CONFIG_PSEUDOFS_SOFTLINKS)
  { "symlink", (FAR const void *)symlink },
#endif
  { "sync", (FAR const void *)&sync },
  { "sysconf", (FAR const void *)sysconf },
  { "sysinfo", (FAR const void *)sysinfo },
  { "syslog", (FAR const void *)syslog },
#if !defined(CONFIG_BUILD_KERNEL)
  { "task_create", (FAR const void *)task_create },
#endif
#if !defined(CONFIG_BUILD_KERNEL)
  { "task_delete", (FAR const void *)task_delete },
#endif
#if !defined(CONFIG_BUILD_KERNEL)
  { "task_restart", (FAR const void *)task_restart },
#endif
#if !defined(CONFIG_BUILD_KERNEL)
  { "task_spawn", (FAR const void *)task_spawn },
#endif
#if defined(CONFIG_CANCELLATION_POINTS)
  { "task_testcancel", (FAR const void *)&task_testcancel },
#endif
#if !defined(CONFIG_BUILD_KERNEL) && CONFIG_TLS_TASK_NELEM > 0
  { "task_tls_alloc", (FAR const void *)task_tls_alloc },
#endif
#if CONFIG_TLS_TASK_NELEM > 0
  { "task_tls_get_value", (FAR const void *)task_tls_get_value },
#endif
#if CONFIG_TLS_TASK_NELEM > 0
  { "task_tls_set_value", (FAR const void *)task_tls_set_value },
#endif
  { "tcflush", (FAR const void *)tcflush },
  { "tcgetattr", (FAR const void *)tcgetattr },
  { "tcsetattr", (FAR const void *)tcsetattr },
  { "telldir", (FAR const void *)telldir },
#if defined(CONFIG_LIBC_LOCALE_GETTEXT)
  { "textdomain", (FAR const void *)textdomain },
#endif
  { "tgkill", (FAR const void *)tgkill },
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "timer_create", (FAR const void *)timer_create },
#endif
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "timer_delete", (FAR const void *)timer_delete },
#endif
#if defined(CONFIG_TIMER_FD)
  { "timerfd_create", (FAR const void *)timerfd_create },
#endif
#if defined(CONFIG_TIMER_FD)
  { "timerfd_gettime", (FAR const void *)timerfd_gettime },
#endif
#if defined(CONFIG_TIMER_FD)
  { "timerfd_settime", (FAR const void *)timerfd_settime },
#endif
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "timer_getoverrun", (FAR const void *)timer_getoverrun },
#endif
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "timer_gettime", (FAR const void *)timer_gettime },
#endif
#if !defined(CONFIG_DISABLE_POSIX_TIMERS)
  { "timer_settime", (FAR const void *)timer_settime },
#endif
  { "time", (FAR const void *)time },
  { "time", (FAR const void *)time },
  { "tolower", (FAR const void *)tolower },
  { "toupper", (FAR const void *)toupper },
  { "towlower", (FAR const void *)towlower },
  { "towupper", (FAR const void *)towupper },
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "truncate", (FAR const void *)truncate },
#endif
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "ub16divub16", (FAR const void *)ub16divub16 },
#endif
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "ub16mulub16", (FAR const void *)ub16mulub16 },
#endif
#if !defined(CONFIG_HAVE_LONG_LONG)
  { "ub16sqr", (FAR const void *)ub16sqr },
#endif
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "umount2", (FAR const void *)umount2 },
#endif
  { "uname", (FAR const void *)uname },
#if defined(CONFIG_FILE_STREAM)
  { "ungetc", (FAR const void *)ungetc },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "ungetwc_unlocked", (FAR const void *)ungetwc_unlocked },
#endif
#if defined(CONFIG_FILE_STREAM)
  { "ungetwc", (FAR const void *)ungetwc },
#endif
#if !defined(CONFIG_DISABLE_MOUNTPOINT)
  { "unlink", (FAR const void *)unlink },
#endif
#if !defined(CONFIG_DISABLE_ENVIRON)
  { "unsetenv", (FAR const void *)unsetenv },
#endif
#if defined(CONFIG_ARCH_HAVE_FORK)
  { "up_fork", (FAR const void *)&up_fork },
#endif
  { "usleep", (FAR const void *)usleep },
  { "utimens", (FAR const void *)utimens },
  { "vasprintf", (FAR const void *)vasprintf },
  { "versionsort", (FAR const void *)versionsort },
#if defined(CONFIG_FILE_STREAM)
  { "vfprintf", (FAR const void *)vfprintf },
#endif
  { "vprintf", (FAR const void *)vprintf },
#if defined(CONFIG_FILE_STREAM)
  { "vscanf", (FAR const void *)vscanf },
#endif
  { "vsnprintf", (FAR const void *)vsnprintf },
  { "vsprintf", (FAR const void *)vsprintf },
  { "vsscanf", (FAR const void *)vsscanf },
  { "vsyslog", (FAR const void *)vsyslog },
#if defined(CONFIG_SCHED_WAITPID) && defined(CONFIG_SCHED_HAVE_PARENT)
  { "waitid", (FAR const void *)waitid },
#endif
#if defined(CONFIG_SCHED_WAITPID)
  { "waitpid", (FAR const void *)waitpid },
#endif
#if defined(CONFIG_SCHED_WAITPID) && defined(CONFIG_SCHED_HAVE_PARENT)
  { "wait", (FAR const void *)wait },
#endif
#if !defined(CONFIG_CPP_HAVE_VARARGS) && defined(CONFIG_DEBUG_WARN)
  { "_warn", (FAR const void *)_warn },
#endif
  { "wcrtomb", (FAR const void *)wcrtomb },
  { "wcscat", (FAR const void *)wcscat },
  { "wcschr", (FAR const void *)wcschr },
  { "wcscmp", (FAR const void *)wcscmp },
  { "wcscoll", (FAR const void *)wcscoll },
  { "wcscpy", (FAR const void *)wcscpy },
  { "wcscspn", (FAR const void *)wcscspn },
  { "wcsftime", (FAR const void *)wcsftime },
  { "wcslcat", (FAR const void *)wcslcat },
  { "wcslcpy", (FAR const void *)wcslcpy },
  { "wcslen", (FAR const void *)wcslen },
  { "wcsncat", (FAR const void *)wcsncat },
  { "wcsncmp", (FAR const void *)wcsncmp },
  { "wcsncpy", (FAR const void *)wcsncpy },
  { "wcsnrtombs", (FAR const void *)wcsnrtombs },
  { "wcspbrk", (FAR const void *)wcspbrk },
  { "wcsrchr", (FAR const void *)wcsrchr },
  { "wcsrtombs", (FAR const void *)wcsrtombs },
  { "wcsspn", (FAR const void *)wcsspn },
  { "wcsstr", (FAR const void *)wcsstr },
  { "wcstod", (FAR const void *)wcstod },
  { "wcstof", (FAR const void *)wcstof },
  { "wcstok", (FAR const void *)wcstok },
  { "wcstold", (FAR const void *)wcstold },
  { "wcstoll", (FAR const void *)wcstoll },
  { "wcstol", (FAR const void *)wcstol },
  { "wcstombs", (FAR const void *)wcstombs },
  { "wcstoul", (FAR const void *)wcstoul },
  { "wcswcs", (FAR const void *)wcswcs },
  { "wcswidth", (FAR const void *)wcswidth },
  { "wcsxfrm", (FAR const void *)wcsxfrm },
  { "wctob", (FAR const void *)wctob },
  { "wctomb", (FAR const void *)wctomb },
  { "wctype", (FAR const void *)wctype },
  { "wcwidth", (FAR const void *)wcwidth },
  { "wmemchr", (FAR const void *)wmemchr },
  { "wmemcmp", (FAR const void *)wmemcmp },
  { "wmemcpy", (FAR const void *)wmemcpy },
  { "wmemmove", (FAR const void *)wmemmove },
  { "wmemset", (FAR const void *)wmemset },
  { "write", (FAR const void *)write },
  { "writev", (FAR const void *)writev },
  { "writev", (FAR const void *)writev }
};

#define NSYMBOLS (sizeof(g_symtab) / sizeof (struct symtab_s))
int g_nsymbols = NSYMBOLS;
