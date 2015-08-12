HHVM_EXTENSION(my_module my_module.cpp)
include_directories(include)

HHVM_SYSTEMLIB(my_module ext_my_module.php)
