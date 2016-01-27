THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include
INCLUDE := ./include
CRYPTOPP := ./extlib/cryptopp
TB_SRC := TrustedBridge.cpp TrustedBridge_constants.cpp TrustedBridge_types.cpp
TB_OBJ := $(patsubst %.cpp,%.o, $(TB_SRC))
KV_SRC := KeyValueStore.cpp KeyValueStore_types.cpp KeyValueStore_constants.cpp
KV_OBJ := $(patsubst %.cpp,%.o, $(KV_SRC))
# GDB := -g

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR) -I$(INCLUDE) -I$(CRYPTOPP) 

.PHONY: all clean

all: tb_server kv_server

%.o: ./include/%.cpp
	$(CXX) -Wall $(GDB) -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@ 

%.o: %.cpp
	$(CXX) -Wall $(GDB) -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@  ~/cryptopp/lib/libcryptopp.a 


kv_server: KeyValueStore_server.o $(KV_OBJ)
	$(CXX) $(GDB) $^ -o $@ -L/usr/local/lib -lthrift

tb_server: TrustedBridge_server.o $(TB_OBJ) $(KV_OBJ) FileAccess.o
	$(CXX) $(GDB) $^ -o $@ -L/usr/local/lib -lthrift  ~/cryptopp/lib/libcryptopp.a 

clean:
	$(RM) *.o tb_server *.sgt
