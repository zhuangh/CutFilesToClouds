<?php

namespace TrustedBridge;

error_reporting(E_ALL);

//require_once __DIR__.'/../../lib/php/lib/Thrift/ClassLoader/ThriftClassLoader.php';
require_once 'Thrift/ClassLoader/ThriftClassLoader.php';
require_once 'TrustedBridge/Types.php';
require_once 'TrustedBridge/TrustedBridge.php';

use Thrift\ClassLoader\ThriftClassLoader;

$GEN_DIR = realpath(dirname(__FILE__).'/..').'/gen-php';

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', '.');
$loader->registerDefinition('TrustedBridge', '.');
$loader->register();

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\THttpClient;
use Thrift\Transport\TPhpStream;
use Thrift\Transport\TBufferedTransport;
use Thrift\Exception\TException;

try {
  /*  
  if (array_search('--http', $argv)) {
    $socket = new THttpClient('localhost', 8080, '/php/PhpServer.php');
  } else {
    $socket = new TSocket('localhost', 9090);
  }
  */
  $socket = new TSocket('sysnet91.sysnet.ucsd.edu', 10030);
  $transport = new TBufferedTransport($socket, 1024, 1024);
  //$transport = new TBufferedTransport(new TPhpStream(TPhpStream::MODE_R | TPhpStream::MODE_W));;
  $protocol = new TBinaryProtocol($transport);
  $client = new \TrustedBridge\TrustedBridgeClient($protocol);

  $transport->open();

  //$file = fopen("login.html", "rb");
  $file = file_get_contents('img/loading.gif', FILE_USE_INCLUDE_PATH);

  $response = $client->UploadToServer("loading.gif","early",$file);

  print_r($response);

  $transport->close();

} catch (TException $tx) {
  print 'TException: '.$tx->getMessage()."\n";
}

?>
