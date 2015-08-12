## The example of the create native HHVM module

*func*  folder - example of the simple interface, use functions

*class* folder - example of the class interface

### Installation

	$ git clone git@github.com:akalend/hhvm-example-ext.git
	$ cd hhvm-example-ext
	$ hphpize && cmake . && make
	$ sudo make install [optional]

Editing the /etc/hhvm/php.ini [optional]:

	hhvm.dynamic_extension_path =  /usr/lib/x86_64-linux-gnu/hhvm/extensions/.. build number .../
	hhvm.dynamic_extensions[] = my_module.so

Build number folder You can find in the result of execute the cp into *make install*
 
Run test:
	
	hhvm test.php


So, You can to run HHVM with options:
	
	 hhvm -d extension_dir=. -d hhvm.extensions[]=my_module.so test.php