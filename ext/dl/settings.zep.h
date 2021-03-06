
extern zend_class_entry *dl_settings_ce;

ZEPHIR_INIT_CLASS(Dl_Settings);

PHP_METHOD(Dl_Settings, tfVersion);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_dl_settings_tfversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_dl_settings_tfversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dl_settings_method_entry) {
	PHP_ME(Dl_Settings, tfVersion, arginfo_dl_settings_tfversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
