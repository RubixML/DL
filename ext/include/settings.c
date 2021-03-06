#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <tensorflow/c/c_api.h>

void tf_version(zval * return_value)
{
    RETVAL_STRING(TF_Version());
}
