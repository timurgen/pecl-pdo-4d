/*
  +----------------------------------------------------------------------+
  | PECL :: PDO_4D                                                       |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2007 The PHP Group                                |
  +----------------------------------------------------------------------+
  |                                                                      |
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Contributed by Alter Way                                             |
  |                http://www.alterway.fr/                               |
  |                4D SAS                                                |
  |                http://www.4d.fr/                                     |
  | Authors: Stephane Planquart <stephane.planquart@o4db.com>,           |
  |          Alexandre Morgaut <php@4d.fr>                               |
  +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#include "php_pdo_4d.h"
#include "php_pdo_4d_int.h"

#if HAVE_PDO_4D

#include "ext/standard/info.h"
#include "pdo/php_pdo.h"
#include "pdo/php_pdo_driver.h"

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "zend_exceptions.h"

/* {{{ phpinfo logo definitions */

#include "php_logos.h"


static unsigned char pdo_4d_logo[] = {
#include "pdo_4d_logos.h"
}; 
/* }}} */
/* {{{ pdo_4d_functions[] */
function_entry pdo_4d_functions[] = {
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ pdo_4d_module_entry
 */
zend_module_entry pdo_4d_module_entry = {
	STANDARD_MODULE_HEADER,
	"pdo_4d",
	pdo_4d_functions,
	PHP_MINIT(pdo_4d),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(pdo_4d), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(pdo_4d),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(pdo_4d), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(pdo_4d),
	"0.1", 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PDO_4D
ZEND_GET_MODULE(pdo_4d)
#endif
/* {{{ PHP_INI_BEGIN
*/
PHP_INI_BEGIN()
	PHP_INI_ENTRY("pdo_4d.preferred_image_types", "jpg", PHP_INI_ALL, NULL)
	PHP_INI_ENTRY("pdo_4d.timeout", "30", PHP_INI_ALL, NULL)
PHP_INI_END()

/* }}} */


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pdo_4d)
{
	php_register_info_logo("PDO_4D_LOGO_ID", "", pdo_4d_logo, 778);
	REGISTER_INI_ENTRIES();
	/* add your stuff here */
	
	/* register 4d pdo driver */
	if (FAILURE == php_pdo_register_driver(&pdo_4d_driver)) {
/*		fprintf(stderr,"Error on register pdo-4d driver\n"); */
		return FAILURE;
  }
  /* fprintf(stderr,"Registering pdo-4d driver OK\n"); **/
	REGISTER_PDO_CLASS_CONST_LONG("FOURD_ATTR_CHARSET", (long)PDO_FOURD_ATTR_CHARSET);
	REGISTER_PDO_CLASS_CONST_LONG("FOURD_ATTR_PREFERRED_IMAGE_TYPES", (long)PDO_FOURD_ATTR_PREFERRED_IMAGE_TYPES);

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(pdo_4d)
{
	php_unregister_info_logo("PDO_4D_LOGO_ID");
	
	php_pdo_unregister_driver(&pdo_4d_driver);
    UNREGISTER_INI_ENTRIES();

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(pdo_4d)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(pdo_4d)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pdo_4d)
{
	php_info_print_box_start(0);

	php_printf("<img src='");
	if (SG(request_info).request_uri) {
		php_printf("%s", (SG(request_info).request_uri));
	}   
	php_printf("?=%s", "PDO_4D_LOGO_ID");
	php_printf("' align='right' alt='image' border='0'>\n");

	php_printf("<p>PDOs driver for 4D-SQL database</p>\n");
	php_printf("<p>Version 0.1alpha (2009-02-19)</p>\n");
	php_printf("<p>Revision $Id$ </p>\n");
	php_printf("<p><b>Authors:</b></p>\n");
	php_printf("<p>Alexandre Morgaut &lt;php@4d.fr&gt; (lead)</p>\n");
	php_printf("<p>Stephane Planquart &lt;stephane.planquart@o4db.com&gt; (developer)</p>\n");
	php_info_print_box_end();
	/* add your stuff here */

}
/* }}} */


#endif /* HAVE_PDO_4D */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */