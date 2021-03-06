
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "include/settings.h"


/**
 * Settings
 *
 * @category    Machine Learning
 * @package     Rubix/DL
 * @author      Andrew DalPino
 */
ZEPHIR_INIT_CLASS(Dl_Settings) {

	ZEPHIR_REGISTER_CLASS(Dl, Settings, dl, settings, dl_settings_method_entry, 0);

	return SUCCESS;

}

/**
 * Test interface to TensorFlow.
 */
PHP_METHOD(Dl_Settings, tfVersion) {

	zval *this_ptr = getThis();


	tf_version(return_value);
	return;

}

