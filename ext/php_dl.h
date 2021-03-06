
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_DL_H
#define PHP_DL_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_DL_NAME        "dl"
#define PHP_DL_VERSION     "0.0.1-alpha"
#define PHP_DL_EXTNAME     "dl"
#define PHP_DL_AUTHOR      "Andrew DalPino"
#define PHP_DL_ZEPVERSION  "0.12.21-$Id$"
#define PHP_DL_DESCRIPTION "A deep learning library for PHP based on TensorFlow."



ZEND_BEGIN_MODULE_GLOBALS(dl)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(dl)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(dl)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(dl, v)
#else
	#define ZEPHIR_GLOBAL(v) (dl_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_dl_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(dl_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(dl_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def dl_globals
#define zend_zephir_globals_def zend_dl_globals

extern zend_module_entry dl_module_entry;
#define phpext_dl_ptr &dl_module_entry

#endif
