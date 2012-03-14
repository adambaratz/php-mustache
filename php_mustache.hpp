
#ifndef PHP_MUSTACHE_HPP
#define PHP_MUSTACHE_HPP

extern "C" {

#define PHP_MUSTACHE_NAME "mustache"  
#define PHP_MUSTACHE_VERSION "0.1.0"
#define PHP_MUSTACHE_RELEASE "2012-03-14"
#define PHP_MUSTACHE_BUILD "master"
#define PHP_MUSTACHE_AUTHORS "John Boehr <jbboehr@gmail.com> (lead)\n"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
  
#ifdef PHP_WIN32
#define PHP_FFTW_API __declspec(dllexport)
#else
#define PHP_FFTW_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

} // extern "C" 

#include <string>

#include "mustache/mustache.hpp"

#include "php_mustache_methods.hpp"

static zend_class_entry * Mustache_ce_ptr = NULL;
static zend_class_entry * MustacheTemplate_ce_ptr = NULL;

extern zend_module_entry mustache_module_entry;
#define phpext_mustache_ptr &mustache_module_entry

PHP_MINIT_FUNCTION(mustache);
PHP_MINFO_FUNCTION(mustache);

typedef struct _php_obj_Mustache {
    zend_object obj;
    mustache::Mustache * mustache;
} php_obj_Mustache;

typedef struct _php_obj_MustacheTemplate {
    zend_object obj;
    mustache::Node * node;
} php_obj_MustacheTemplate;


#endif /* PHP_MUSTACHE_HPP */