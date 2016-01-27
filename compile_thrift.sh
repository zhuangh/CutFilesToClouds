#!/bin/bash

thrift --gen php -out ./front-end/ TrustedBridge.thrift
echo "php"
thrift --gen cpp -out ./back-end/include TrustedBridge.thrift
echo "cpp TB"
thrift --gen cpp -out ./back-end/include KeyValueStore.thrift
echo "cpp KV"
