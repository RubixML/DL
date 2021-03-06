
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "dl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *dl_settings_ce;

ZEND_DECLARE_MODULE_GLOBALS(dl)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(dl)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Dl_Settings);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(dl)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_dl_globals *dl_globals TSRMLS_DC)
{
	dl_globals->initialized = 0;

	/* Cache Enabled */
	dl_globals->cache_enabled = 1;

	/* Recursive Lock */
	dl_globals->recursive_lock = 0;

	/* Static cache */
	memset(dl_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_dl_globals *dl_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(dl)
{
	zend_dl_globals *dl_globals_ptr;
	dl_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(dl_globals_ptr);
	zephir_initialize_memory(dl_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(dl)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(dl)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_DL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_DL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_DL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_DL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_DL_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(dl)
{
#if defined(COMPILE_DL_DL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(dl_globals);
	php_zephir_init_module_globals(dl_globals);
}

static PHP_GSHUTDOWN_FUNCTION(dl)
{
	
}


zend_function_entry php_dl_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_dl_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry dl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_dl_deps,
	PHP_DL_EXTNAME,
	php_dl_functions,
	PHP_MINIT(dl),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(dl),
#else
	NULL,
#endif
	PHP_RINIT(dl),
	PHP_RSHUTDOWN(dl),
	PHP_MINFO(dl),
	PHP_DL_VERSION,
	ZEND_MODULE_GLOBALS(dl),
	PHP_GINIT(dl),
	PHP_GSHUTDOWN(dl),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(dl),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_DL
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(dl)
#endif
