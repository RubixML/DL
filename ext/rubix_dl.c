
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "rubix_dl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *rubix_dl_poc_ce;

ZEND_DECLARE_MODULE_GLOBALS(rubix_dl)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(rubix_dl)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Rubix_DL_Poc);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(rubix_dl)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_rubix_dl_globals *rubix_dl_globals TSRMLS_DC)
{
	rubix_dl_globals->initialized = 0;

	/* Cache Enabled */
	rubix_dl_globals->cache_enabled = 1;

	/* Recursive Lock */
	rubix_dl_globals->recursive_lock = 0;

	/* Static cache */
	memset(rubix_dl_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_rubix_dl_globals *rubix_dl_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(rubix_dl)
{
	zend_rubix_dl_globals *rubix_dl_globals_ptr;
	rubix_dl_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(rubix_dl_globals_ptr);
	zephir_initialize_memory(rubix_dl_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(rubix_dl)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(rubix_dl)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_RUBIX_DL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_RUBIX_DL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_RUBIX_DL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_RUBIX_DL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_RUBIX_DL_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(rubix_dl)
{
#if defined(COMPILE_DL_RUBIX_DL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(rubix_dl_globals);
	php_zephir_init_module_globals(rubix_dl_globals);
}

static PHP_GSHUTDOWN_FUNCTION(rubix_dl)
{
	
}


zend_function_entry php_rubix_dl_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_rubix_dl_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry rubix_dl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_rubix_dl_deps,
	PHP_RUBIX_DL_EXTNAME,
	php_rubix_dl_functions,
	PHP_MINIT(rubix_dl),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(rubix_dl),
#else
	NULL,
#endif
	PHP_RINIT(rubix_dl),
	PHP_RSHUTDOWN(rubix_dl),
	PHP_MINFO(rubix_dl),
	PHP_RUBIX_DL_VERSION,
	ZEND_MODULE_GLOBALS(rubix_dl),
	PHP_GINIT(rubix_dl),
	PHP_GSHUTDOWN(rubix_dl),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(rubix_dl),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_RUBIX_DL
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(rubix_dl)
#endif
