#include "FtsoContract.h"
#include <iostream>
#include "types/uint256_t.h"
#include "cJSON/cJSON.h"

// Call super-class constructor
FtsoContract::FtsoContract(Web3* _web3, const string* address) : Contract(_web3, address) {
}

tuple<uint256_t, uint256_t> FtsoContract::getCurrentPrice() {
  string func = "getCurrentPrice()";
  string param = SetupContractData(&func);
  string result_body = Call(&param);
  // example return (price: uint256, timestamp: uint256)
  // {"jsonrpc":"2.0","id":0,"result":"0x00000000000000000000000000000000000000000000000000000000000134a700000000000000000000000000000000000000000000000000000000624fa3ad"}
  cJSON *result_json = cJSON_Parse(result_body.c_str());
  cJSON *result_element = cJSON_GetObjectItem(result_json, "result");
  if (cJSON_IsString(result_element) && (result_element->valuestring != NULL))
  {
    uint256_t price(string(result_element->valuestring, 2, 64), 16);
    uint256_t timestamp(string(result_element->valuestring, 66, 64), 16);
    return make_tuple(price, timestamp);
  } else {
    return make_tuple(uint256_t(0), uint256_t(0));
  }
}
