.PHONY: RefInstall install precompile test
RefInstall: include
	ln -s include /usr/include/concept_check
install: include
	cp include /usr/include/concept_check
precompile: include
	cd include						 \
	$(CXX) -std=c++17 *.hpp\
	cd concepts						 \
	$(CXX) -std=c++17 *.hpp\
	cd member							 \
	$(CXX) -std=c++17 *.hpp\
	cd ../operations			 \
	$(CXX) -std=c++17 *.hpp
test: include test
	cd test												\
	$(CXX) -std=c++17 -c test_*.cc\
	cd concepts										\
	$(CXX) -std=c++17 -c test_*.cc\
	cd member											\
	$(CXX) -std=c++17 -c test_*.cc\
	cd ../operations							\
	$(CXX) -std=c++17 -c test_*.cc
