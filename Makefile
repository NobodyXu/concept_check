.PHONY: RefInstall install precompile Test
RefInstall: include
	ln -s include /usr/include/concept_check
install: include
	cp include /usr/include/concept_check
precompile: include
	cd include						 \
	$(CXX) -std=c++14 *.hpp\
	cd concepts						 \
	$(CXX) -std=c++14 *.hpp\
	cd member							 \
	$(CXX) -std=c++14 *.hpp\
	cd ../operations			 \
	$(CXX) -std=c++14 *.hpp
Test: include test
	cd test												\
	$(CXX) -std=c++14 -c test_*.cc\
	cd concepts										\
	$(CXX) -std=c++14 -c test_*.cc\
	cd member											\
	$(CXX) -std=c++14 -c test_*.cc\
	cd ../operations							\
	$(CXX) -std=c++14 -c test_*.cc
