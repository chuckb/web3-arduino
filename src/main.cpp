#include "Web3.h"
#include "FtsoContract.h"

// To build:
// g++ --std=c++11 types/uint128_t.cpp types/uint256_t.cpp Util.cpp Log.cpp Contract.cpp FtsoContract.cpp Web3.cpp cJSON/cJSON.c main.cpp -DDEBUGLOG -I/usr/local/Cellar/openssl@1.1/1.1.1m/include -L/usr/local/Cellar/openssl@1.1/1.1.1m/lib -lssl -lcrypto -o main

/* Example of running
charles-benedicts-macbook-2:src chuck_benedict$ ./main

Calling server...

Sending...

{"jsonrpc":"2.0","method":"web3_sha3","params":["0x67657443757272656e7450726963652829"],"id":0}

Received...

{"jsonrpc":"2.0","id":0,"result":"0xeb91d37e63e47db51a4c9cabc39eaea30be8e7f2b5b333faf45f25ada20d780a"}


Calling server...

Sending...

{"jsonrpc":"2.0","method":"eth_call","params":[{"from":"0x4584Aa23FbfCbA5dcaeE389b1E4FD6EBfdb87Ebc","to":"0xA1a9B8aB5BB798EeE536A23669AD744DCF8537a3","data":"0xeb91d37e"}, "latest"],"id":0}

Received...

{"jsonrpc":"2.0","id":0,"result":"0x000000000000000000000000000000000000000000000000000000000001346c00000000000000000000000000000000000000000000000000000000624fa514"}

78956
1649386772
charles-benedicts-macbook-2:src chuck_benedict$
*/

int main() {
  // Call the XRP FTSO contract and get the current price.

  // Set the path for the RPC endpint of the Flare Songbird network
  string host = "https://songbird.towolabs.com";
  string path = "/rpc";

  // Set the contract address of the XRP FTSO
  string xrpContractAddress = "0xA1a9B8aB5BB798EeE536A23669AD744DCF8537a3";

  // Init web3 for communication to the blockchain
  Web3 web3(&host, &path);

  // Init a contract object to wrap contract specific methods.
  FtsoContract xrpFtsoContract(&web3, &xrpContractAddress);
  strcpy(xrpFtsoContract.options.from,"0x4584Aa23FbfCbA5dcaeE389b1E4FD6EBfdb87Ebc");
  strcpy(xrpFtsoContract.options.gasPrice,"20000000000000");
  xrpFtsoContract.options.gas = 5000000;

  // Call the contract
  auto result = xrpFtsoContract.getCurrentPrice();

  // Spit out the results
  // Results can be checked here: https://songbird-explorer.flare.network/address/0xA1a9B8aB5BB798EeE536A23669AD744DCF8537a3/read-contract
  // Current price
  cout << get<0>(result) << endl;
  // as of timestamp
  cout << get<1>(result) << endl;
  return 0;
}