#include "hphp/runtime/ext/extension.h"

namespace HPHP {


const StaticString
		CURRENT_YEAR("CURRENT_YEAR"),
        YANDEX_URL("YANDEX_URL"),
        the_URL("http://yandex.ru"),
        name("name"),
        value("value");


static String HHVM_FUNCTION(hello_goodbye, const String& name, bool hello) {
	  return hello ? "Hello " + name : "Goodbye" + name;
}

static Array HHVM_FUNCTION(get_data, const String& data) {
	Array ret = Array::Create();
	
	ret.set(name, value);

	if (!data.empty()) {
		ret.set( 0, data );
	}

	return ret;
}




class MyModuleExtension : public Extension {
 public:
  MyModuleExtension(): Extension("my_module", "1.0") {}
  	
  	void moduleInit() override {
    	
    	HHVM_FE(hello_goodbye);
    	HHVM_FE(get_data);
    	
    	Native::registerConstant<KindOfInt64>(CURRENT_YEAR.get(), 2015);
		Native::registerConstant<KindOfStaticString>( YANDEX_URL.get(),the_URL.get());
    	loadSystemlib();		
    } 


} s_my_module_extension;

HHVM_GET_MODULE(my_module);

} // namespace HPHP