
extern zend_class_entry *dl_poc_ce;

ZEPHIR_INIT_CLASS(Dl_Poc);

PHP_METHOD(Dl_Poc, tfVersion);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_dl_poc_tfversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_dl_poc_tfversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dl_poc_method_entry) {
	PHP_ME(Dl_Poc, tfVersion, arginfo_dl_poc_tfversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
