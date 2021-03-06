
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
#include "include/test.h"


/**
 * POC
 *
 * @internal
 *
 * @category    Machine Learning
 * @package     Rubix/DL
 * @author      Andrew DalPino
 */
ZEPHIR_INIT_CLASS(Dl_Poc) {

	ZEPHIR_REGISTER_CLASS(Dl, Poc, dl, poc, dl_poc_method_entry, 0);

	return SUCCESS;

}

/**
 * Test interface to TensorFlow.
 */
PHP_METHOD(Dl_Poc, tfVersion) {

	zval *this_ptr = getThis();


	tf_version(return_value);
	return;

}

