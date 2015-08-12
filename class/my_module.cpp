#include "hphp/runtime/ext/extension.h"
namespace HPHP {

const StaticString
  Hello("Hello"),
  s_name("name");

String HHVM_METHOD(Hello, getName) {
  return this_->o_get(s_name, false, Hello);
}

String HHVM_STATIC_METHOD(Hello, DefaultHello) {
  return "Hello";
}

class MyModuleExtension : public Extension {
 public:
  MyModuleExtension(): Extension("my_module", "1.0") {}
  	
  	void moduleInit() override {

      HHVM_ME(Hello, getName);
      HHVM_STATIC_ME(Hello, DefaultHello);
    	
    	loadSystemlib();		
    } 

} s_my_module_extension;

HHVM_GET_MODULE(my_module);
} // namespace HPHP