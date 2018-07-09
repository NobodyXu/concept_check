RefInstall: include
	ln -s include /usr/include/concept_check
install: include
	cp include /usr/include/concept_check
test: include test
	cd test
	$CXX -std=c++17 -c test_*.cc
	cd meta
	$CXX -std=c++17 -c test_*.cc
	cd ../concepts
	$CXX -std=c++17 -c test_*.cc
	cd type_properties
	$CXX -std=c++17 -c test_*.cc
	cd member
	$CXX -std=c++17 -c test_*.cc
	cd ../operations 
	$CXX -std=c++17 -c test_*.cc
