THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include
INCLUDE := ../include
KV_SRC := KeyValueStore.cpp KeyValueStore_types.cpp KeyValueStore_constants.cpp
KV_OBJ := $(patsubst %.cpp,%.o, $(KV_SRC))

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR) -I$(INCLUDE)

DROPBOX := $(shell ./compile Dropbox)

.PHONY: all clean

all: fa_test dropbox

%.o: $(INCLUDE)/%.cpp
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

%.o: %.cpp
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

fa_test: FileAccessTest.o FileAccess.o $(KV_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift

dropbox:
	$(DROPBOX)

clean:
	$(RM) *.o fa_test
	rm -rf bytecode 