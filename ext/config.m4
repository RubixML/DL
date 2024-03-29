PHP_ARG_ENABLE(dl, whether to enable dl, [ --enable-dl   Enable Dl])

if test "$PHP_DL" = "yes"; then

	

	if ! test "x-I/usr/local/include -L/usr/local/lib -ltensorflow" = "x"; then
		PHP_EVAL_LIBLINE(-I/usr/local/include -L/usr/local/lib -ltensorflow, DL_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_DL, 1, [Whether you have Dl])
	dl_sources="dl.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c dl/settings.zep.c include/settings.c"
	PHP_NEW_EXTENSION(dl, $dl_sources, $ext_shared,, -O3 -ffast-math)
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	PHP_ADD_BUILD_DIR([$ext_builddir/dl/])
	PHP_SUBST(DL_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([dl], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([dl], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/dl], [php_DL.h])

fi
