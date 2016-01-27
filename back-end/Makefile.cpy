THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include
INCLUDE := ./include
CRYPTOPP := ./extlib/cryptopp
TB_SRC := TrustedBridge.cpp TrustedBridge_constants.cpp TrustedBridge_types.cpp
TB_OBJ := $(patsubst %.cpp,%.o, $(TB_SRC))

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR) -I$(INCLUDE) -I$(CRYPTOPP)

.PHONY: all clean

all: tb_server

%.o: ./include/%.cpp
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@  ~/cryptopp/lib/libcryptopp.a

%.o: %.cpp
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@  ~/cryptopp/lib/libcryptopp.a

tb_server: TrustedBridge_server.o $(TB_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift ~/cryptopp/lib/libcryptopp.a

clean:
	$(RM) *.o tb_server
