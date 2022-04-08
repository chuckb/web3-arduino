#ifndef FTSOCONTRACT_H
#define FTSOCONTRACT_H

#include "Contract.h"
#include "Web3.h"
#include <string>
#include <tuple>
#include "types/uint256_t.h"

class FtsoContract: public Contract {
  public:
    FtsoContract(Web3* _web3, const string* address);
    //string getSymbol();
    tuple<uint256_t, uint256_t> getCurrentPrice();    
};

#endif //FTSOCONTRACT_H
